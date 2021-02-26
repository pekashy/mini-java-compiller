#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type Scanner::ScanToken()

#include "FlexBisonOutput/parser.hh"
#include <memory>

class CompilerDriver;
class Location;

class Scanner: public yyFlexLexer {
public:
    using Ptr = std::shared_ptr<Scanner>;

    Scanner(std::shared_ptr<CompilerDriver> shDriver, std::shared_ptr<Location> shLocation);
    virtual ~Scanner() = default;
    virtual yy::parser::symbol_type ScanToken();
    void UpdateLocation();
private:
    std::shared_ptr<CompilerDriver> m_pDriver;
    std::shared_ptr<Location> m_pLocation;
};
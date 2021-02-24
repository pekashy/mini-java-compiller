#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type Scanner::ScanToken()

#include "FlexBisonOutput/parser.hh"

class CompilerDriver;

class Scanner: public yyFlexLexer {
public:
    Scanner(CompilerDriver& driver): driver(driver) {}
    virtual ~Scanner() {}
    virtual yy::parser::symbol_type ScanToken();
    CompilerDriver &driver;
    void UpdateLocation();
};
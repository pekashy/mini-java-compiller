#pragma once

#include <memory>
#include "FlexBisonOutput/parser.hh"


class Location
{
public:
    using Ptr = std::shared_ptr<Location>;
    using stype = yy::parser::symbol_type;

    static Ptr Create(const std::string& filename, bool bDebug);

    virtual void Update(int yyleng) = 0;
    virtual void Step() = 0;
    virtual void SkipEmptyLines(int yyleng) = 0;

    virtual stype MakeNumber(const std::string& yytext) = 0;
    virtual stype MakeMinus() = 0;
    virtual stype MakePlus() = 0;
    virtual stype MakeStar() = 0;
    virtual stype MakeSlash() = 0;
    virtual stype MakeLParen() = 0;
    virtual stype MakeRParen() = 0;
    virtual stype MakeAssign() = 0;
    virtual ~Location() = default;
protected:
    Location() = default;
};


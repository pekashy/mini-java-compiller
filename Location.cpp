#include "Location.h"

#include <limits.h>

namespace {
    using yy::parser;

    class LocationImpl : public Location
    {
    public:
        LocationImpl(const std::string& filename, bool bDebug);
        void Update(ctype yyleng) override;
        void SkipEmptyLines(ctype yyleng) override;
        void Step() override;
        void ThrowError(const std::string& rErrorMsg) override;

        stype MakeNumber(const std::string& yytext) override;
        stype MakeIdentifier(const std::string& yytext) override;

        stype MakeMinus() override;
        stype MakePlus() override;
        stype MakeStar() override;
        stype MakeSlash() override;
        stype MakeLParen() override;
        stype MakeRParen() override;
        stype MakeAssign() override;
        stype MakeEnd() override;
    private:
        const bool m_bDebug;
        const std::string m_rFilename;
        yy::parser::location_type m_loc;
    };
}

LocationImpl::LocationImpl(const std::string& filename, bool bDebug)
    : m_rFilename(filename)
    , m_bDebug(bDebug)
{
    m_loc.initialize(&m_rFilename);
}


Location::stype LocationImpl::MakeNumber(const std::string& yytext) {
    errno = 0;
    long n = strtol(yytext.c_str(), NULL, 10);
    if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
        throw yy::parser::syntax_error(m_loc, "integer is out of range: " + yytext);
    return yy::parser::make_NUMBER((int) n, m_loc);
}


Location::stype LocationImpl::MakeIdentifier(const std::string& yytext) {
    return parser::make_IDENTIFIER(yytext, m_loc);
}


void LocationImpl::Update(ctype yyleng) {
    if(m_bDebug)
    {
        std::cerr << "Action called " << m_loc << std::endl;
    }
    m_loc.columns(yyleng);
}

Location::stype LocationImpl::MakeMinus() {
    return parser::make_MINUS(m_loc);
}


void LocationImpl::SkipEmptyLines(ctype yyleng) {
    m_loc.lines(yyleng);
    m_loc.step();
}

Location::stype LocationImpl::MakePlus() {
    return parser::make_PLUS(m_loc);
}

Location::stype LocationImpl::MakeStar() {
    return parser::make_STAR(m_loc);
}

Location::stype LocationImpl::MakeSlash() {
    return parser::make_SLASH(m_loc);
}

Location::stype LocationImpl::MakeLParen() {
    return parser::make_LPAREN(m_loc);
}

Location::stype LocationImpl::MakeRParen() {
    return parser::make_RPAREN(m_loc);
}

Location::stype LocationImpl::MakeAssign() {
    return parser::make_ASSIGN(m_loc);
}

void LocationImpl::Step() {
    m_loc.step();
}

Location::stype LocationImpl::MakeEnd() {
    return parser::make_END(m_loc);
}

void LocationImpl::ThrowError(const std::string& rErrorMsg)
{
    throw parser::syntax_error(m_loc, rErrorMsg);
}

Location::Ptr Location::Create(const std::string& filename, bool bDebug)
{
    return std::make_shared<LocationImpl>(filename, bDebug);
}


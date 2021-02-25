#include "Location.h"

namespace {
    using yy::parser;

    class LocationImpl : public Location
    {
    public:
        LocationImpl(const std::string& filename, bool bDebug);
        void Update(int yyleng) override;

        void SkipEmptyLines(int yyleng) override;
        void Step() override;

        stype MakeNumber(const std::string& yytext) override;
        stype MakeMinus() override;
        stype MakePlus() override;
        stype MakeStar() override;
        stype MakeSlash() override;
        stype MakeLParen() override;
        stype MakeRParen() override;
        stype MakeAssign() override;
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

Location::stype LocationImpl::MakeNumber(const std::string &yytext) {
    return Location::stype();
}

void LocationImpl::Update(int yyleng) {
    if(m_bDebug)
    {
        std::cerr << "Action called " << m_loc << std::endl;
    }
    m_loc.columns(yyleng);
}

Location::stype LocationImpl::MakeMinus() {
    return parser::make_MINUS(m_loc);
}


void LocationImpl::SkipEmptyLines(int yyleng) {
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

Location::Ptr Location::Create(const std::string& filename, bool bDebug)
{
    return std::make_shared<LocationImpl>(filename, bDebug);
}


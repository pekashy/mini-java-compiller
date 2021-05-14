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
        stype MakeAssert() override;
        stype MakeEnd() override;
        stype MakeThis() override;
        stype MakeDot() override;
        stype MakeComadot() override;
        stype MakeLSParnt() override;
        stype MakeRSParent() override;
        stype MakeInt() override;
        stype MakeBoolean() override;
        stype MakeVoid() override;
        stype MakePublic() override;
        stype MakeLFparen() override;
        stype MakeRFParen() override;
        stype MakeIf() override;
        stype MakeElse() override;
        stype MakeWhile() override;
        stype MakePrint() override;
        stype MakeClass() override;
        stype MakeMain() override;
        stype MakeStatic() override;
        stype MakeNew() override;
        stype MakeTrue() override;
        stype MakeFalse() override;
        stype MakeLength() override;
        stype MakeInverse() override;
        stype MakeLess() override;
        stype MakeMore() override;
        stype MakeLeq() override;
        stype MakeMeq() override;
        stype MakeEq() override;
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

Location::stype LocationImpl::MakeThis() {
    return parser::make_THIS(m_loc);
}

Location::stype LocationImpl::MakeDot() {
    return parser::make_DOT(m_loc);
}

Location::stype LocationImpl::MakeLSParnt() {
    return parser::make_LSPAREN(m_loc);
}

Location::stype LocationImpl::MakeRSParent() {
    return parser::make_RSPAREN(m_loc);
}

Location::stype LocationImpl::MakeComadot() {
    return parser::make_COMADOT(m_loc);
}

Location::stype LocationImpl::MakeInt() {
    return parser::make_INT(m_loc);
}

Location::stype LocationImpl::MakeBoolean() {
    return parser::make_BOOLEAN(m_loc);
}

Location::stype LocationImpl::MakeVoid() {
    return parser::make_VOID(m_loc);
}

Location::stype LocationImpl::MakePublic() {
    return parser::make_PUBLIC(m_loc);
}

Location::stype LocationImpl::MakeLFparen() {
    return parser::make_LFPARENT(m_loc);
}

Location::stype LocationImpl::MakeRFParen() {
    return parser::make_RFPARENT(m_loc);
}

Location::stype LocationImpl::MakeAssert(){
    return parser::make_ASSERT(m_loc);
}

Location::stype LocationImpl::MakeIf() {
    return parser::make_IF(m_loc);
}

Location::stype LocationImpl::MakeElse() {
    return parser::make_ELSE(m_loc);
}

Location::stype LocationImpl::MakeWhile() {
    return parser::make_WHILE(m_loc);
}

Location::stype LocationImpl::MakePrint() {
    return parser::make_PRINT(m_loc);
}

Location::stype LocationImpl::MakeClass() {
    return parser::make_CLASS(m_loc);
}

Location::stype LocationImpl::MakeMain() {
    return parser::make_MAIN(m_loc);
}

Location::stype LocationImpl::MakeStatic() {
    return parser::make_STATIC(m_loc);
}

Location::stype LocationImpl::MakeEnd() {
    return parser::make_END(m_loc);
}

Location::stype LocationImpl::MakeNew() {
    return parser::make_NEW(m_loc);
}

Location::stype LocationImpl::MakeTrue() {
    return parser::make_TRUE(m_loc);
}

Location::stype LocationImpl::MakeFalse()
{
    return parser::make_FALSE(m_loc);
}

Location::stype LocationImpl::MakeLength()
{
    return parser::make_LENGTH(m_loc);
}

Location::stype LocationImpl::MakeInverse()
{
    return parser::make_INVERSE(m_loc);
}

Location::stype LocationImpl::MakeLess()
{
    return parser::make_LESS(m_loc);
}

Location::stype LocationImpl::MakeMore()
{
    return parser::make_MORE(m_loc);
}

Location::stype LocationImpl::MakeLeq()
{
    return parser::make_LEQ(m_loc);
}

Location::stype LocationImpl::MakeMeq()
{
    return parser::make_MEQ(m_loc);
}

Location::stype LocationImpl::MakeEq()
{
    return parser::make_EQ(m_loc);
}



void LocationImpl::Step() {
    m_loc.step();
}

void LocationImpl::ThrowError(const std::string& rErrorMsg)
{
    throw parser::syntax_error(m_loc, rErrorMsg);
}

Location::Ptr Location::Create(const std::string& filename, bool bDebug)
{
    return std::make_shared<LocationImpl>(filename, bDebug);
}


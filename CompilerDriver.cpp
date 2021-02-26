#include "CompilerDriver.h"
#include "Location.h"
#include "Program.h"

#include <fstream>

namespace
{
    class CompilerDriverImpl : public CompilerDriver, public std::enable_shared_from_this<CompilerDriverImpl>
    {
    public:
        CompilerDriverImpl(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation);
        int Parse(const std::string& f) override;
        void SetProgram(Program::Ptr pProgram) override;
        //[[nodiscard]] Location::Ptr GetLocation() const override;
        void Init();
    private:
        std::shared_ptr<Scanner> CreateScanner(const std::string& f);
        std::shared_ptr<yy::parser> CreateParser(const std::shared_ptr<Scanner>& shScanner);

        const bool m_bTraceParsing;
        const bool m_bTraceScanning;
        const bool m_bDebugLocation;
        Program::Ptr m_pProgram = nullptr;
    };
}


CompilerDriverImpl::CompilerDriverImpl(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation)
    : m_bTraceParsing(bTraceParsing)
    , m_bTraceScanning(bTraceScanning)
    , m_bDebugLocation(bDebugLocation)
{}

std::shared_ptr<Scanner> CompilerDriverImpl::CreateScanner(const std::string& f)
{
    auto shLocation = Location::Create(f, m_bDebugLocation);
    std::shared_ptr<Scanner> shScanner = std::make_shared<Scanner>(shared_from_this(), shLocation);
    shScanner->set_debug(m_bTraceScanning);
    return shScanner;
}


std::shared_ptr<yy::parser> CompilerDriverImpl::CreateParser(const std::shared_ptr<Scanner>& shScanner)
{
    auto shParser = std::make_shared<yy::parser>(*shScanner, *this);
    shParser->set_debug_level(m_bTraceParsing);
    return shParser;
}
int CompilerDriverImpl::Parse(const std::string& f)
{
    if (f.empty () || f == "-")
    {
        return -1;
    }
    m_pProgram = nullptr;
    auto shScanner = CreateScanner(f);
    auto shParser = CreateParser(shScanner);
    std::ifstream programStream(f);
    shScanner->yyrestart(programStream);
    //m_pScanner->yyrestart(programStream);
    return (*shParser)();
}


void CompilerDriverImpl::SetProgram(std::shared_ptr<Program> pProgram) {
    m_pProgram = pProgram;
}

CompilerDriver::Ptr CompilerDriver::Create(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation)
{
    return std::make_shared<CompilerDriverImpl>(bTraceParsing, bTraceScanning, bDebugLocation);
}

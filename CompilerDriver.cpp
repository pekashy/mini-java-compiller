#include "CompilerDriver.h"
#include "Location.h"


namespace
{
    class CompilerDriverImpl : public CompilerDriver, std::enable_shared_from_this<CompilerDriverImpl>
    {
    public:
        CompilerDriverImpl(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation);
        int ResetLocation(const std::string& f) override;
        [[nodiscard]] Location::Ptr GetLocation() const override;
    private:
        const bool m_bTraceParsing;
        const bool m_bTraceScanning;
        const bool m_bDebugLocation;
        Location::Ptr m_pLocation = nullptr;

        Scanner m_Scanner;
        yy::parser m_Parser;
    };
}


CompilerDriverImpl::CompilerDriverImpl(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation)
    : m_bTraceParsing(bTraceParsing)
    , m_bTraceScanning(bTraceScanning)
    , m_bDebugLocation(bDebugLocation)
    , m_Scanner(shared_from_this())
    , m_Parser(m_Scanner, *this)
{
    m_Scanner.set_debug(bTraceScanning);
    m_Parser.set_debug_level(bTraceParsing);
}


int CompilerDriverImpl::ResetLocation(const std::string& f)
{
    m_pLocation = Location::Create(f, m_bDebugLocation);

}

Location::Ptr CompilerDriverImpl::GetLocation() const {
    return m_pLocation;
}

CompilerDriver::Ptr CompilerDriver::Create(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation)
{
    return std::make_shared<CompilerDriverImpl>(bTraceParsing, bTraceScanning, bDebugLocation);
}

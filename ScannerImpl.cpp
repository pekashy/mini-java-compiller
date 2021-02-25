#include "Scanner.h"
#include "CompilerDriver.h"

Scanner::Scanner(std::shared_ptr<CompilerDriver> pDriver)
    : m_pDriver(std::move(pDriver))
{
    m_pLocation = m_pDriver->GetLocation();
}

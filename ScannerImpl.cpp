#include "Scanner.h"
#include "CompilerDriver.h"

Scanner::Scanner(std::shared_ptr<CompilerDriver> shDriver, std::shared_ptr<Location> shLocation)
    : m_pDriver(shDriver)
    , m_pLocation(shLocation)
{}

#pragma once

#include "Scanner.h"
#include <memory>

class Location;

class CompilerDriver
{
public:
    using Ptr = std::shared_ptr<CompilerDriver>;
    static Ptr Create(bool bTraceParsing, bool bTraceScanning, bool bDebugLocation);
    virtual int Parse(const std::string& f) = 0;
    virtual void SetProgram(const std::shared_ptr<Program>& pProgram) = 0;

    virtual ~CompilerDriver() = default;
protected:
    CompilerDriver() = default;
};
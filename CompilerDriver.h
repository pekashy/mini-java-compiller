#pragma once
#include "Scanner.h"


class CompilerDriver {
public:
    CompilerDriver() = default;
    int parse(const std::string& f) { return false;}
    bool result = false;
    yy::location location;
    bool location_debug;
    bool trace_parsing;
    bool trace_scanning;
};
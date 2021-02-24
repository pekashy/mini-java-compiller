#pragma once
#include "Scanner.h"

class CompilerDriver {
public:
    CompilerDriver() {std::cout << "blah blah" << std::endl;};
    int parse(const std::string& f) { return false;}
    bool result = false;
    yy::location location;
    bool location_debug;
    bool trace_parsing;
    bool trace_scanning;
};
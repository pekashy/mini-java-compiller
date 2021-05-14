#include "CompilerDriver.h"

#include <iostream>


int main(int argc, char** argv) {
    bool bTraceParsing = false;
    bool bTraceScanning = false;
    bool bLocationDebug = false;
    std::string rParseString;

    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            bTraceParsing = true;
        } else if (argv[i] == std::string("-s")) {
            bTraceScanning = true;
        } else if (argv[i] == std::string("-l")) {
            bLocationDebug = true;
        } else {
            rParseString = argv[i];
        }
    }

    auto pDriver = CompilerDriver::Create(bTraceParsing, bTraceScanning, bLocationDebug);
    return pDriver->Parse(rParseString);
}
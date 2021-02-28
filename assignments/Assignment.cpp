#include "Assignment.h"
#include <iostream>

Assignment::Assignment(
    const std::string& variable,
    Expression* expression
) : variable_(variable), expression_(expression) {
    std::cout << "\nAssigned value '" << expression->eval() << "' to variable '" << variable << "'\n";
}
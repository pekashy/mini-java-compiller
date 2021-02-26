#pragma once

#include "assignments/AssignmentList.h"
#include "expressions/Expression.h"

#include <memory>

class Program {
public:
    using Ptr = std::shared_ptr<Program>;
    static Ptr Create(AssignmentList* assignments, Expression* expression);
protected:
    Program() = default;
};

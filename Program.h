#pragma once

#include "Grammar/assignments/AssignmentList.h"
#include "Grammar/expressions/Expression.h"

#include <memory>

class Program {
public:
    using Ptr = std::shared_ptr<Program>;
    static Ptr Create(AssignmentList* assignments, Expression* expression);
protected:
    Program() = default;
};

#include "Program.h"

namespace
{
    class ProgramImpl : public Program
    {
    public:
        ProgramImpl(AssignmentList *assignments, Expression *expression)
            : m_pAssignments(assignments)
            , m_pExpression(expression)
            {}
    private:
        AssignmentList* m_pAssignments;
        Expression* m_pExpression;
    };
}


Program::Ptr Program::Create(AssignmentList *assignments, Expression *expression)
{
    return std::make_shared<ProgramImpl>(assignments, expression);
}
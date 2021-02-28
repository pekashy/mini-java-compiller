#include <stdexcept>
#include "AssignmentList.h"


void AssignmentList::AddAssignment(const GrammarNode::Ptr& pGrammarNode) {
    auto pAssignment = std::dynamic_pointer_cast<Assignment>(pGrammarNode);
    if(pAssignment)
    {
        m_mapAssignmentPtrs.push_back(pAssignment);
    }
    else
    {
        throw std::runtime_error("Tried to add non-assignment type to assignment list!");
    }
}
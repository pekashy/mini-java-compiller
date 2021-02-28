#pragma once

#include "Assignment.h"

#include <vector>

class AssignmentList : public GrammarNode {
 public:
    void AddAssignment(const GrammarNode::Ptr& pGrammarNode);
 private:
    std::vector<Assignment::Ptr> m_mapAssignmentPtrs;
};
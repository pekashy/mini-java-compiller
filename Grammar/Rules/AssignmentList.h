#pragma once

#include "Assignment.h"

#include <vector>

class AssignmentList : public GrammarNode {
 public:
    using Ptr = std::shared_ptr<AssignmentList>;
    void AddAssignment(const Assignment::Ptr& pAssignment);
    static Ptr Create();
 private:
    AssignmentList() = default;
    std::vector<Assignment::Ptr> m_mapAssignmentPtrs;
};
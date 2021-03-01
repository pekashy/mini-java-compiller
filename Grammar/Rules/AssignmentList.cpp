#include <stdexcept>
#include "AssignmentList.h"


void AssignmentList::AddAssignment(const Assignment::Ptr& pAssignment)
{
    m_mapAssignmentPtrs.push_back(pAssignment);
}

AssignmentList::Ptr AssignmentList::Create()
{
    return std::shared_ptr<AssignmentList>(new AssignmentList());
}

#include "scores.h"

#include <cassert>


double& Scores::operator[](size_t index)
{
	assert((index >= 0) and (index < size));
	return m_scores[index];
}
const double& Scores::operator[](size_t index) const
{
	assert(index >= 0 || index < size);
	return m_scores[index];
}
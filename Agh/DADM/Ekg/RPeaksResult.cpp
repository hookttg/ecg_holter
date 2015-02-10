#include "RPeaksResult.h"
#include "ReturnType.h"
#include <vector>

RPeaksResult::RPeaksResult(void)
{
}

RPeaksResult::~RPeaksResult(void)
{
}

std::vector <unsigned int> RPeaksResult::getRPeaks()
{
	return R_Peaks;
}

void RPeaksResult::setRPeaks(std::vector <unsigned int> signal)
{
	R_Peaks = signal;
}

RPeaksResult* RPeaksResult:: getResult() {
	RPeaksResult* rp = new RPeaksResult();
	rp->R_Peaks = R_Peaks;
	//paramType = RPEAKS;
	return rp;
	}

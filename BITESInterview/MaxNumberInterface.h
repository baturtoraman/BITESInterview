#pragma once
#include <vector>

using namespace std;

class MaxNumberInterface {
public:
	virtual vector<int> getSolution(vector<int>& nums, int k) = 0;
};

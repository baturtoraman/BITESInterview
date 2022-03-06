#pragma once
#include "MaxNumberInterface.h"
#include <deque>

class MaxNumber : public MaxNumberInterface
{

private:

    void maxSlidingWindow(vector<int> nums, int k, vector<int>& result, deque<int>& dqIndices, int index)
    {

        if (index == nums.size()) {
            dqIndices.clear();
            return;
        }

        //Arrangements on the first window..
        if(index < k)
        {
            while (!dqIndices.empty() && nums[dqIndices.back()] < nums[index])
                dqIndices.pop_back(); //pop while smaller than index
            dqIndices.push_back(index);
            index++;
            maxSlidingWindow(nums, k, result, dqIndices, index);
        }

        if (!dqIndices.empty())
        {
            if (index == k)
                result.push_back(nums[dqIndices.front()]);
            //rest of the vector
            if (index < nums.size())
            {
                if (dqIndices.front() == index - k)
                    dqIndices.pop_front();

                while (!dqIndices.empty() && nums[dqIndices.back()] < nums[index])
                    dqIndices.pop_back();


                if (result.size() <= nums.size() - 2) {

                    dqIndices.push_back(index);
                    result.push_back(nums[dqIndices.front()]);
                }

                index++;
                maxSlidingWindow(nums, k, result, dqIndices, index);
            }
        }
    }

public:
    MaxNumber() {}
    ~MaxNumber() {}
	vector<int> getSolution(vector<int>& nums, int k) override {
        vector<int> result;
        deque<int> dqIndices;
        maxSlidingWindow(nums, k, result, dqIndices, 0);
        return result;
    }


    //Iterative Solution
    //---------------------------------------
	//vector<int> getSolution(vector<int>& nums, int k) override {
 //       vector<int> result; // result as a vector to be returned
 //       deque<int> dqIndices;   // store indices in dequeue
 //       int index = 0;
 //       int sizeOfNums = nums.size();

 //       // first window first
 //       while (index < k)
 //       {
 //           while (!dqIndices.empty() && nums[dqIndices.back()] < nums[index])
 //               dqIndices.pop_back(); //pop while smaller than index
 //           dqIndices.push_back(index);
 //           index++;
 //       }

 //       result.push_back(nums[dqIndices.front()]);

 //       //rest of the vector
 //       while (index < sizeOfNums)
 //       {
 //           if (dqIndices.front() == index - k)
 //               dqIndices.pop_front();

 //           while (!dqIndices.empty() && nums[dqIndices.back()] < nums[index])
 //               dqIndices.pop_back();
 //           dqIndices.push_back(index);

 //           result.push_back(nums[dqIndices.front()]);
 //           index++;
 //       }
 //       return result;
	//}

};


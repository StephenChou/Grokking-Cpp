/*

Problem Statement #
Given an array of positive numbers and a positive number ‘k’, find the maximum sum of any contiguous subarray of size ‘k’.

Example 1:

Input: [2, 1, 5, 1, 3, 2], k=3 
Output: 9
Explanation: Subarray with maximum sum is [5, 1, 3].

Example 2:

Input: [2, 3, 4, 1, 5], k=2 
Output: 7
Explanation: Subarray with maximum sum is [3, 4].

*/
#include <iostream>
#include <vector>

int max_subarray(std::vector<int> &nums, int k)
{
	int cur_sum = 0, max_sum = 0, window_start = 0;

	for (int window_end = 0; window_end < nums.size(); window_end++) {
		
		cur_sum += nums[window_end];

		if (window_end - window_start >= k) {
			cur_sum -= nums[window_start++];
		}

		max_sum = std::max(max_sum, cur_sum);

	}	

	return max_sum;

}


int main(void)
{
	std::vector<int> v1 = {2, 1, 5, 1, 3, 2};
	std::vector<int> v2 = {2, 3, 4, 1, 5};

	std::cout << max_subarray(v1, 3) << "\n";
	std::cout << max_subarray(v2, 2) << "\n";

}

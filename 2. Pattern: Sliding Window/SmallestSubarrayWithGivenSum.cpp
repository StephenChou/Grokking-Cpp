/*

Problem Statement 
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].

Example 2:

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].

Example 3:

Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].

*/

#include <iostream>
#include <vector>

int smallest_subarray(std::vector<int> &nums, int s)
{
	int min_length = nums.size(), cur_sum = 0, window_start = 0;

	for (int window_end = 0; window_end < nums.size(); window_end++) {
		cur_sum += nums[window_end];


		while (cur_sum >= s) {
			min_length = std::min(min_length, window_end - window_start + 1);
			cur_sum -= nums[window_start++];
		}


	}

	return min_length;

}

int main(void)
{
	std::vector<int> v1 = {2, 1, 5, 2, 3, 2}, v2 = {2, 1, 5, 2, 8}, v3 = {3, 4, 1, 1, 6};
	std::cout << smallest_subarray(v1, 7) << "\n";
	std::cout << smallest_subarray(v2, 7) << "\n";
	std::cout << smallest_subarray(v3, 8) << "\n";

	return 0;
}

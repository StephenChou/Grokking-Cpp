/*

Problem Statement
Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.
You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both the baskets.

Example 1:

Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

Example 2:

Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']

 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

int get_count(std::unordered_map<char, int> &um) 
{
	int count = 0;

	for (auto it = um.begin(); it != um.end(); it++) {
		count += it->second;
	}

	return count;
}


int fruits_into_baskets(std::vector<char> &fruits)
{

	std::unordered_map<char, int> um;

	int window_start = 0, count = 0, max_count = 0;

	for (int window_end = 0; window_end < fruits.size(); window_end++) {
		
		char c = fruits[window_end];

		if (um.find(c) == um.end()) {
			um[c] = 1;
		} else {
			um[c]++;
		}

		while (um.size() > 2) {
			char start = fruits[window_start++];
			
			if (um[start] == 1) um.erase(start);
			else {
				um[start]--;
			}
		}

		max_count = std::max(max_count, get_count(um));

	}

	return max_count;

}

int main(void)
{
	std::vector<char> v1 = {'A', 'B', 'C', 'A', 'C'}, v2 = {'A', 'B', 'C', 'B', 'B', 'C'};
	std::cout << fruits_into_baskets(v1) << "\n";
	std::cout << fruits_into_baskets(v2) << "\n";

	return 0;
}

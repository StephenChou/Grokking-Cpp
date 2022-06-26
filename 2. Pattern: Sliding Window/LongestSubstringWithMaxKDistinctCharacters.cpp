/*

Problem Statement #
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Example 2:

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Example 3:

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".


*/

#include <iostream>
#include <string>
#include <set>

int longest_substring(std::string s, int k)
{
	std::set<char> set;

	int window_start = 0, max_len = 0;

	for (int window_end = 0; window_end < s.length(); window_end++) {
		set.insert(s[window_end]);

		while (set.size() > k) {
			set.erase(s[window_start++]);
		}		

		max_len = std::max(max_len, window_end - window_start + 1);
	}

	return max_len;

}

int main(int argc, char *argv[])
{
	std::string s1("araaci"), s2("cbbebi");
	std::cout << longest_substring(s1, 2) << "\n";
	std::cout << longest_substring(s1, 1) << "\n";
	std::cout << longest_substring(s2, 3) << "\n";

	return 0;

}

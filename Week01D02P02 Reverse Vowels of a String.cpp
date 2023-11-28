/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

//Solution:

class Solution {
public:
    string reverseVowels(string s) {
    int start = 0;
    int end = s.size() - 1;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (start < end) {
        while (start < end && vowels.find(s[start]) == vowels.end()) {
            start++;
        }
        while (start < end && vowels.find(s[end]) == vowels.end()) {
            end--;
        }
        if (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    return s;
    }
};

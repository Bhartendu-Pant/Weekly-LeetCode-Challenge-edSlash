/*
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length

*/

//Solution

class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0;
        string vowels="aeiou";
        for(int i=0;i<k;i++)
        {
            if(vowels.find(s[i])!=string::npos)count++;
        }
        int maxx=count;
        int j=0;
        for(int i=k;i<s.length();i++)
        {
            if(vowels.find(s[i]) != string::npos)count++;
            if(vowels.find(s[j]) != string::npos)count--;

            j++;
            maxx=max(maxx,count);
            if(maxx==k)return maxx;
        }
        return maxx;
    }
};

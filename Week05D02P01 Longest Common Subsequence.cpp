/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

//Solution:

class Solution {
public:
    int dp[1001][1001];
    int lcs(string &text1,string &text2,int i,int j)
    {
        if(i==text1.size() || j==text2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(text1[i]==text2[j])return lcs(text1,text2,i+1,j+1)+1;

        return dp[i][j]= max(lcs(text1,text2,i,j+1),lcs(text1,text2,i+1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text2,0,0);
    }
};

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

//Solution:
class Solution {
public:
    int edit(string &word1,string &word2,int i,int j,int size1,int size2,vector<vector<int>>&dp)
    {
        if(i>=size1)return size2-j;
        if(j>=size2)return size1-i;
        if(dp[i][j] != -1)return dp[i][j];
        int ans=INT_MAX;
        if(word1[i]==word2[j])
        {
            ans=edit(word1,word2,i+1,j+1,size1,size2,dp);
        }
        else
        {
            int replaced=edit(word1,word2,i+1,j+1,size1,size2,dp)+1;
            int deleted=edit(word1,word2,i+1,j,size1,size2,dp)+1;
            int inserted=edit(word1,word2,i,j+1,size1,size2,dp)+1;

            ans=min(replaced,min(deleted,inserted));
        }
        return dp[i][j]=ans;
        

    }
    int minDistance(string word1, string word2) {
        int size1=word1.length();
        int size2=word2.length();
        if(size1==0)return size2;
        if(size2==0)return size1;

        vector<vector<int>>dp(size1+1,vector<int>(size2+1,-1));
        return edit(word1,word2,0,0,size1,size2,dp);
    }
};

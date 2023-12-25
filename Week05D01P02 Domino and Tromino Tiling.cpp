/*
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000
*/

//Solution:
class Solution {
public:
    int numTilings(int n) {
        int mod=1e9+7;
        vector<long long>helper;
        helper.push_back(0);
        helper.push_back(1);
        helper.push_back(2);
        helper.push_back(5);
        // for n=4 ans will be 11
        // for n=5 ans will be 24
        // for n=6 ans will be 53
        // for n=7 ans will be 117
        // pattern = 2*(n-1)+(n-3)
        if(n<=3)return helper[n];
        for(int i=4;i<=n;i++)
        {
            helper.push_back(2*helper[i-1]+helper[i-3]);
            helper[i] %= mod;
        }
        return helper[n];
    }
};

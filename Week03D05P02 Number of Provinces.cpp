/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

//Solution:
class Solution {
public:
    void eachProvince(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int visit)
    {
        visited[visit]=true;
        for(auto next:adj[visit])
        {
            if(!visited[next])eachProvince(adj,visited,next);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        int n=isConnected.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                eachProvince(adj,visited,i);
                count++;
            }
        }
        return count;
    }
};

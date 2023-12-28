/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/

//Solution:
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int overlaps=0;
        pair<int,int>range;
        range.first=intervals[0][0];
        range.second=intervals[0][1];
        int i=1;
        while(i<intervals.size()){
            if(range.second > intervals[i][0]){
                overlaps++;
                if(range.second > intervals[i][1]){
                    range.first=intervals[i][0];
                    range.second=intervals[i][1];
                }
            }
              else{
                    range.first=intervals[i][0];
                    range.second=intervals[i][1];
                }
                i++;
        }
        return overlaps;
    }
};

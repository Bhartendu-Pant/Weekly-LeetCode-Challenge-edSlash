/*
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

Example 1:



Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0
 

Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

Example 1:



Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0
 

Constraints:

1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9
*/

//Solution:
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int op=0;
        int p,q,r;
        for(int i=0;i<32;i++)
        {
            p=a&(1<<i);
            q=b&(1<<i);
            r=c&(1<<i);

            if(r==0)
            {
                if(p!=0 and q==0)op++;
                else if(p==0 and q!=0)op++;
                else if(p!=0 and q!=0)op+=2;
            }
            else
            {
                if(p==0 and q==0)op++;
            }
        }
        return op;
    }
};

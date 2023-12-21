/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

//Solution:
class Solution {
public:
    void solution(string table[],vector<string>&ans,string digits,int ind,string helper)
    {
        if(ind >= digits.length())
        {
            ans.push_back(helper);
            return;
        }
        int num=digits[ind]-'0';
        string curr=table[num];
        for(int i=0;i<curr.length();i++)
        {
            helper.push_back(curr[i]);
            solution(table,ans,digits,ind+1,helper);
            helper.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string table[10]={" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.length()==0)return {};
        solution(table,ans,digits,0,"");
        return ans;
    }
};

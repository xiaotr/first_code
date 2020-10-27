/**
题目：leetcode_面试题08.09、括号

描述：设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

说明：解集不能包含重复的子集。


**/

//code

class Solution {
public:
    
    void backtrack(vector<string>& res, int left, int right, string tmp)
    {
        if(left == 0 && right == 0)
        {
            res.push_back(tmp);
            return;
        }
        else
        {
            // 只有用了左括号才能用右括号
            if(left > 0)
                backtrack(res, left-1, right+1, tmp+'(');
            if(right > 0)
                backtrack(res, left, right-1, tmp+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, n, 0, "");
        return res;
    }
};
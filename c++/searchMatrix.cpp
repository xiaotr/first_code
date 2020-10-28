/**
题目：leetcode_面试题10.09、排序矩阵查找

描述：给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。

**/

//code

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int i = m - 1 , j = 0;
        while(i >= 0 && j < n)
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                i--;
            else j++;
        }
        return false;
    }
};
/**
题目：leetcode_jz13、机器人运动范围

描述：地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
请问该机器人能够到达多少个格子？

**/

//code

class Solution {
public:
    int getsum(int s)
    {
        if(s < 10)
            return s;
        int sum = 0;
        while(s > 0)
        {
            sum += s%10;
            s = s/10;
        }
        return sum;
    }
    int dfs(vector<vector<bool>> &flag, int m, int n, int k, int i, int j)
    {
        int sum = getsum(i) + getsum(j);
        if(i >= m || j >= n || sum > k || !flag[i][j])
            return 0;
        flag[i][j] = false;
        return 1 + dfs(flag, m, n, k, i+1, j) + dfs(flag, m, n, k, i, j+1);
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> flag(m , vector<bool>(n , true));
        int i = 0 , j = 0;
        return dfs(flag, m, n, k, i, j);
    }
};
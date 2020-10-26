/**
题目：面试题08.04、幂级

描述：编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。


**/

//code

class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int count, int begin)
    {
        if(tmp.size() == count)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = begin ; i < nums.size() ; i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums, res, tmp, count, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        for(int count = 0 ; count <= nums.size() ; count++)
        {
            dfs(nums, res, tmp, count, 0);
        }
        return res;
    }
};
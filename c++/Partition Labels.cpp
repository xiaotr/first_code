/**
题目：leetcode 763：划分字母区间

描述：字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。


**/

//code

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        vector<int> in(26 , 0);
        for(int i = 0 ; i < S.size() ; i++)
            in[S[i] - 'a'] = i;
        int begin = 0 , end = 0;
        for(int i = 0 ; i < S.size() ; i++)
        {
            end = max(end , in[S[i] - 'a']);
            if(end == i)
            {
                res.push_back(end - begin + 1);
                begin = i + 1;
            }
        }
        return res;
    }
};
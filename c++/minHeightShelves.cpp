/**
题目：leetcode_1105、填充书架

描述：附近的家居城促销，你买回了一直心仪的可调节书架，打算把自己的书都整理到新的书架上。

你把要摆放的书 books 都整理好，叠成一摞：从上往下，第 i 本书的厚度为 books[i][0]，高度为 books[i][1]。

按顺序将这些书摆放到总宽度为 shelf_width 的书架上。返回书架整体可能的最小高度。

**/

//code

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size() + 1 , INT_MAX);
        dp[0] = 0;
        for(int i = 0 ; i < books.size() ; i++)
        {
            int h = 0 , w = 0;
            for(int j = i ; j >= 0 ; j--)
            {
                w += books[j][0];
                if(w > shelf_width)
                    break;
                h = max(h , books[j][1]);
                dp[i+1] = min(dp[i+1] , dp[j]+h);
            }
        }
        return dp[books.size()];
    }
};
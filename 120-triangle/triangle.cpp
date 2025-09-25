class Solution {
private:
    int solve(int x,int y, vector<vector<int>> &dp,vector<vector<int>> &triangle,int &r)
    {
        if(x>=r) return 0;
        if(y<0 || y>=r) return INT_MAX;
        if(dp[x][y]!=INT_MAX) return dp[x][y];

        else
        dp[x][y] = triangle[x][y] + min(solve(x+1,y,dp,triangle,r),solve(x+1,y+1,dp,triangle,r));

        return dp[x][y];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
     int r=triangle.size();
     vector<vector<int>> dp(r,vector<int>(r,INT_MAX));

    int ans = solve(0,0,dp,triangle,r);
    return ans;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[n-1] = true;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]==0)
            {
                dp[i]=0;
                continue;
            }
            for(int j=1;j<=min(nums[i],n-i);j++)
            {
                if(dp[i+j]==1)
                {
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
class Solution {
public:
    void findsum(int start,vector<int>& num,int& sum)
    {
        if(start==num.size()) return;
        int tsum=0;
        for(int i=start;i<num.size();i++)
        {
            tsum+=num[i];
            if(tsum>sum) sum=tsum;
            if(tsum<0)
            {                
                findsum(i+1,num,sum);
                return;
            }
        }
    }
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;
        findsum(0,nums,sum);
        return sum;
    }
};
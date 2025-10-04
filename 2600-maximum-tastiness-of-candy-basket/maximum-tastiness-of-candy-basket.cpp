class Solution {
public:
    bool solve(vector<int>& price,int d,int k)
    {
        int curr=1,li=0;
        for(int i=1;i<price.size();i++)
        {
            if(price[i]-price[li]>=d)
            {
                curr++;
                li=i;
            }
            if(curr>=k) return true;
        }

        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size();
        int l=0,r=price[n-1]-price[0];
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(solve(price,mid,k))
            {
                ans=mid;
            l=mid+1;
            }
            else
            r=mid-1;
        }

        return ans;
    }
};
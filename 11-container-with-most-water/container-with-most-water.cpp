class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),lg=0,rg=n-1;
        int ans=0;

        while(lg<=rg)
        {
            ans=max(ans,(rg-lg)*min(height[lg],height[rg]));

            if(height[lg]<=height[rg]) lg++;
            else rg--;
        }

        return ans;
    }
};
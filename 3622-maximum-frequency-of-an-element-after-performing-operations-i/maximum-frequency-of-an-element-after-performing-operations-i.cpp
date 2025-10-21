class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mv= *max_element(nums.begin(),nums.end())+k+2;
        vector<int> freq(mv,0);

        for(auto &n:nums)
        freq[n]++;

        for(int i=1;i<mv;i++)
        freq[i]+=freq[i-1];

        int ans=0;
        for(int i=0;i<mv;i++)
        {
            int left = max(0,i-k);
            int right = min(mv-1,i+k);

            int total = freq[right] - (left?freq[left-1]:0);
            int val = freq[i] - (i?freq[i-1]:0);
            ans = max(ans,val+min(numOperations,total-val));
        }
        return ans;
    }
};
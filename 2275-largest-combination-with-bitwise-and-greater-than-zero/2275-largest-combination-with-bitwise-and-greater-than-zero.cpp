class Solution {
public:
    int largestCombination(vector<int>& nums) {
        vector<int> bits(24,0);
        for(int i=0;i<nums.size();i++)
        {
            int pos=0;
            while(nums[i]>0)
            {
                bits[pos++] += 1&nums[i];
                nums[i] = nums[i] >> 1;
            }
        }
        return *max_element(bits.begin(),bits.end());
    }
};
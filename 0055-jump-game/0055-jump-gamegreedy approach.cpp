class Solution {
public:
    bool canJump(vector<int>& nums) {
        int gas=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            gas--;
            if(gas<0) return false;
            gas=gas<nums[i]?nums[i] : gas;
        }
        return true;
    }
};
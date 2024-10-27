class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpcap=nums[0]; //initialise a jump cap variable
        for(int i=1;i<nums.size();i++)
        {
            jumpcap--; //each successive steps take one point out
            if(jumpcap<0) return false; //at any index, if jumpcapacity runs out, it means we can't reach that index
            jumpcap=jumpcap<nums[i]?nums[i] : jumpcap; //if nums[i]>jumpcap, we update jumpcap
        }
        return true;
    }
};
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(),nums.end());
        while(find(s.begin(),s.end(),original)!=NULL)
        original*=2;

        return original;
    }
};
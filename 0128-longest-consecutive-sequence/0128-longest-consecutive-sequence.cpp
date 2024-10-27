class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> numset; // i don't believe this one is O(n).
        for(auto& num:nums)
        numset.insert(num);

        for(auto& num:numset)
        {
            if(numset.find(num-1)==numset.end())
            {
                int y=num+1;
                while(numset.find(y)!=numset.end())
                y+=1;

                ans=max(ans,y-num);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto n:nums) freq[n]++;
        priority_queue<int> fo;
        for(auto &it:freq)
        {
            fo.push(it.second);
        }

        int maxf = fo.top(),ans=0;
        while(!fo.empty() && fo.top()==maxf)
        {
            ans+=maxf;
            fo.pop();
        }

        return ans;
    }
};
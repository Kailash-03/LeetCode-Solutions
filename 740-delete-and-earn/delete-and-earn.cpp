class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &n:nums)
        freq[n]++;

        vector<pair<int,int>> fs;
        for(auto &it:freq)
        fs.push_back({it.first,it.second});

        sort(fs.begin(),fs.end());

        int prev=fs[0].first*fs[0].second;
        int prev2=0;
        for(int i=1;i<fs.size();i++)
        {
           int currVal = fs[i].first * fs[i].second;
            int curr = 0;

            if (fs[i].first == fs[i-1].first + 1) {
                // consecutive: must choose between take or not_take
                curr = max(prev, currVal + prev2);
            } else {
                // not consecutive: can safely add
                curr = currVal + prev;
            }

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
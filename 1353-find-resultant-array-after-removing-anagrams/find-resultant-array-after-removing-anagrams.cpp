class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        vector<int> prevCount(26, 0);

        for (auto& w : words) {
            vector<int> currCount(26, 0);
            for (char c : w) currCount[c - 'a']++;

            if (currCount != prevCount) {
                result.push_back(w);
                prevCount = currCount;
            }
        }

        return result;
    }
};

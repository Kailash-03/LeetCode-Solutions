class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int n = potions.size();

        for (int spell : spells) {
            // Use integer math to compute ceiling
            long long val = (success + spell - 1) / spell;

            // Binary search for the first potion >= val
            int l = 0, r = n - 1, res = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (potions[mid] >= val) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans.push_back(n - res);
        }

        return ans;
    }
};

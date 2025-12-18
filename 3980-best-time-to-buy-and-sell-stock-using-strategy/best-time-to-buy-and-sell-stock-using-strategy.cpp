class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int h = k / 2;

        long long base = 0;
        for (int i = 0; i < n; i++)
            base += 1LL * strategy[i] * prices[i];

        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = -1LL * strategy[i] * prices[i];
            B[i] =  1LL * (1 - strategy[i]) * prices[i];
        }

        vector<long long> prefA(n + 1, 0), prefB(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefA[i + 1] = prefA[i] + A[i];
            prefB[i + 1] = prefB[i] + B[i];
        }

        long long bestGain = 0;  // modification is optional
        for (int L = 0; L + k <= n; L++) {
            long long gain =
                (prefA[L + h] - prefA[L]) +
                (prefB[L + k] - prefB[L + h]);
            bestGain = max(bestGain, gain);
        }

        return base + bestGain;
    }
};

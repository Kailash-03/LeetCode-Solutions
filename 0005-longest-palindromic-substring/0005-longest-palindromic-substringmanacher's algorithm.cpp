class Solution {
public:
    string longestPalindrome(string original) {

        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        if(original.length()<=1) return original;
        string s="*";
        for(auto ch:original)
        {
            s+=ch;
            s+='*';
        }

        int n=s.length();
        int maxlen=1;
        string ans = original.substr(0,1);
        vector<int> dp(n,0);
        int c=0,r=0;
        for(int i=0;i<n;i++)
        {
                if(i<r)
                dp[i] = min(r-i,dp[2*c-i]);

                while(i-dp[i]-1>=0 && i+dp[i]+1<n && s[i-dp[i]-1]==s[i+dp[i]+1])
                dp[i]++;


                if(i+dp[i]>r)
                {
                    c=i;
                    r=i+dp[i];
                }
                if(dp[i]>maxlen)
                {
                    maxlen=dp[i];
                    ans = s.substr(i-dp[i],2*dp[i] + 1);
                    ans.erase(remove(ans.begin(),ans.end(),'*'),ans.end());
                }
        }
        return ans;
    }
};
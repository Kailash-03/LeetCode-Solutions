class Solution {
public:
    int gcd(int a,int b)
    {
        while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        // st.push(nums[0]);

        for(int i=0;i<nums.size();i++)
        {
            if(st.empty()) st.push(nums[i]);
            else
            {
                int curr=nums[i];
                while(!st.empty() && gcd(st.top(),curr)>1)
                {
                    int x= st.top();
                    st.pop();
                    curr =(long long) x*(curr/gcd(x,curr));
                }
                st.push(curr);
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

    return ans;
    }
};
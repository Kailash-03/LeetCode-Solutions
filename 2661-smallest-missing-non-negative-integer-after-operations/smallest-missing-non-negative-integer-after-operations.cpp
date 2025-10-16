class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> freq;
        for(auto &n:nums)
        {
            int temp=n%value;
            if(n<0 && temp!=0) temp+=value;

            cout<<temp<<endl;
            freq[temp]++;
        }
            int i=0;
            while(freq[i%value]>0)
            {
                cout<<i<<endl;
                freq[i%value]--;
                i++;
            }
    
        return i;
    }
};
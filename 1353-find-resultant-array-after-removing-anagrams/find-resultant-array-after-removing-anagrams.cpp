class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       int n=words.size();
       vector<unordered_map<char,int>> farray(n);
       for(int i=0;i<n;i++)
            for(auto c:words[i])
                farray[i][c]++;

        bool isUpdated=true;
        while(isUpdated)
        {
            isUpdated=false;
            for(int i=0;i<n;i++)
            {
                if(words[i]=="") continue;
                else
                {
                    int j=i+1;
                    while(j<n)
                    {
                        if(words[j]=="") {
                            j++;
                        }
                        else if(farray[j]==farray[i])
                        {
                        words[j]="";
                        j++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        for(auto &word:words)
            if(word!="")
                ans.push_back(word);

        return ans;
    }
};
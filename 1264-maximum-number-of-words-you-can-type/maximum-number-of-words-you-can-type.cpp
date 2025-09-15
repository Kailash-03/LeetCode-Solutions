class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans=0;
        int n=text.length();
        for(int i=0;i<n;i++)
        {
            string word="";
            while(i<n && text[i]!=' ')
            word+=text[i++];

            bool flag=true;
            for(auto &c:brokenLetters)
            {
                if(word.contains(c))
                {
                    flag=false;
                    break;
                }
            }

            if(flag) ans++;

            cout<<word<<endl;
        }

        return ans;
    }
};
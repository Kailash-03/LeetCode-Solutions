class Solution {
public:
    string convert(string s, int numrows) {
        if(numrows==1) return s;
        int increment = (numrows-1)*2;
        string ans="";
        for(int r=0;r<numrows;r++)
        {
            for(int i=r;i<s.length();i=i+increment)
            {
                ans+=s[i];
                if(r!=0 && r!=numrows-1 && i+increment-(2*r)<s.length())
                ans+=s[i+increment-(2*r)];
            }
        }

        return ans;
    }
};
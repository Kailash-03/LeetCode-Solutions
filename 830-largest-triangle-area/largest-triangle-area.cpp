class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n=p.size();
        double ans=0;

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    // |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|. 
                    double temp = (double)(p[i][0]*(p[j][1]-p[k][1]) + p[j][0]*(p[k][1]-p[i][1]) + p[k][0]*(p[i][1]-p[j][1]))/2;
                    if(temp<0) temp*=-1;

                    ans=max(ans,temp); 
                }


        return ans;
    }
};
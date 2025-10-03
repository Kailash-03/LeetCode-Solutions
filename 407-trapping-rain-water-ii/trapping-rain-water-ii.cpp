class Solution {
public:
    int trapRainWater(vector<vector<int>>& hmap) {
        int m=hmap.size(),n=hmap[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(i==0 || i==m-1 || j==0 || j == n-1)
                    {
                        pq.push({hmap[i][j],i,j});
                        hmap[i][j]=-1;
                    }

        int res=0,hmax = -1;
        vector<int> dx={0,+1,0,-1};
        vector<int> dy={+1,0,-1,0};

        while(!pq.empty())
        {
            int h = pq.top()[0];
            int r = pq.top()[1];
            int c=pq.top()[2];

                pq.pop();
            hmax = max(hmax,h);
            res+=hmax-h;

            for(int i=0;i<4;i++)
            {
                int new_r=r+dx[i];
                int new_c=c+dy[i];

                if(new_r<0 || new_r>=m || new_c<0 || new_c>=n || hmap[new_r][new_c]==-1)
                continue;

                pq.push({hmap[new_r][new_c],new_r,new_c});
                hmap[new_r][new_c] =-1;
            }
        }

        return res;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));

        vis[0][0]=1;
        vector<int> dx = {1,0,-1,0},dy={0,1,0,-1};
        while(!pq.empty())
        {
            int t=pq.top()[0],x=pq.top()[1],y=pq.top()[2];
            pq.pop();
            if(x==n-1 && y==n-1) return t;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(vis[nx][ny]) continue;

                vis[nx][ny] =1;
                pq.push({max(t,grid[nx][ny]),nx,ny});
            }

        }

        return -1;
    }
};
class Solution {
private:
    void dfs(int x,int y,vector<vector<int>>& grid,int m,int n)
    {
        int up=x-1,down=x+1,left=y-1,right=y+1; 
        while(up>=0 && grid[up][y]>=0)
        {
            grid[up][y]++;
            up--;
        }
        while(down<m && grid[down][y]>=0)
        {
            grid[down][y]++;
            down++;
        }
        while(left>=0 && grid[x][left]>=0)
        {
            grid[x][left]++;
            left--;
        }
        while(right<n && grid[x][right]>=0)
        {
            grid[x][right]++;
            right++;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto &g:guards)
            grid[g[0]][g[1]] = -1;

        for(auto &w:walls)
            grid[w[0]][w[1]] = -2;

        for(auto &g:guards)
            dfs(g[0],g[1],grid,m,n);

        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0) ans++;

        return ans;
    }
};
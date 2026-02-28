class Solution {
public:
    int n;
    int m;
    int mod=1e9+7;
    int dp[501][501][2];
    int solve(vector<vector<int>> &grid,int i,int j,int dir)
    {
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dir!=-1 && dp[i][j][dir]!=-1) return dp[i][j][dir];
        int ct=0;
        if(grid[i][j]==1)
        {
            if(dir==1) ct=(ct+solve(grid,i+1,j,0))%mod;
            else ct=(ct+solve(grid,i,j+1,1))%mod;
        }
        else 
        {
            ct=(ct+solve(grid,i+1,j,0)+solve(grid,i,j+1,1))%mod;
        }
        if(dir!=-1) dp[i][j][dir]=ct%mod;
        return ct%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,-1);
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        dp[n-1][m-1]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) maxi=max(maxi,grid[i][j]);
        }
        vector<int> tele(maxi+1,INT_MAX);
        for(int t=0;t<=k;t++)
        {
            for(int i=n-1;i>=0;i--)
            {
                for(int j=m-1;j>=0;j--)
                {
                    if(i==n-1 && j==m-1) continue;
                    if(i+1<n) dp[i][j]=min(dp[i][j],dp[i+1][j]+grid[i+1][j]);
                    if(j+1<m) dp[i][j]=min(dp[i][j],dp[i][j+1]+grid[i][j+1]);
                    if(t>0) dp[i][j]=min(dp[i][j],tele[grid[i][j]]);
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    tele[grid[i][j]]=min(dp[i][j],tele[grid[i][j]]);
                }
            }
            // int mini=INT_MAX;
            for(int i=1;i<=maxi;i++)
            {
                tele[i]=min(tele[i-1],tele[i]);
            }
        }
        return dp[0][0];
    }
};
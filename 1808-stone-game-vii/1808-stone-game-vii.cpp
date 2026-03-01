class Solution {
public:
    int sum;
    int dp[1001][1001];
    int solve(vector<int> &stones,int i,int j,int sum)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int takei=sum-stones[i]-solve(stones,i+1,j,sum-stones[i]);
        int takej=sum-stones[j]-solve(stones,i,j-1,sum-stones[j]);
        return dp[i][j]=max(takei,takej);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++) sum+=stones[i];
        return solve(stones,0,n-1,sum);
    }
};
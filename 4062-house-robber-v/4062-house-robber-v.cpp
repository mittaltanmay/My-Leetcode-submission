class Solution {
public:
    int n;
    long long solve(int i,vector<int> &colors,vector<int> &nums,vector<long long> &dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=solve(i+1,colors,nums,dp);
        if(i+1==n || colors[i]!=colors[i+1]) ans=max(ans,nums[i]+solve(i+1,colors,nums,dp));
        else if(i+1<n && colors[i]==colors[i]) ans=max(ans,nums[i]+solve(i+2,colors,nums,dp));
        return dp[i]=ans;
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        n=nums.size();
        vector<long long> dp(n+1,-1);
        return solve(0,colors,nums,dp);
    }
};
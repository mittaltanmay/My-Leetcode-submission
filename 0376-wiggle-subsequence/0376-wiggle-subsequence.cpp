class Solution {
public:
    int n;
    int dp[1001][1001][2];
    int solve(vector<int> &nums,int i,bool ispos,int prev)
    {
        if(i>=n) return 0;
        int keep=0;
        if(prev!=-1 && dp[i][prev][ispos]!=-1) return dp[i][prev][ispos];
        if(prev==-1) keep=1+solve(nums,i+1,ispos,i);
        else{
            int diff=nums[i]-nums[prev];
            if(diff>0 && ispos) keep=1+solve(nums,i+1,false,i);
            else if(diff<0 && !ispos) keep=1+solve(nums,i+1,true,i);
        }
        int skip=solve(nums,i+1,ispos,prev);
        if(prev!=-1) dp[i][prev][ispos]=max(skip,keep);
        return max(skip,keep); 
    }
    int wiggleMaxLength(vector<int>& nums) {
        n=nums.size();
        int prev=-1;
        memset(dp,-1,sizeof(dp));
        return max(solve(nums,0,true,prev),solve(nums,0,false,prev));
    }
};
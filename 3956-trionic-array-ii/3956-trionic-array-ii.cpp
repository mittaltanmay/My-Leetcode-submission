class Solution {
public:
    int n;
    vector<vector<long long>> dp;
    long long solve(vector<int> &nums,int trend,int i)
    {
        if(i>=n)
        {
            if(trend==3) return 0;
            return LLONG_MIN/2;
        }
        if(dp[i][trend]!=-1) return dp[i][trend];
        long long skip=LLONG_MIN/2;
        long long take=LLONG_MIN/2;

        if(trend==0)
        {
            skip=solve(nums,0,i+1);
        }
        if(trend==3) take=nums[i];
        if(i+1<n)
        {
            int curr=nums[i];
            int next=nums[i+1];
            if(trend==0 && next>curr) take=max(take,curr+solve(nums,1,i+1));
            else if(trend==1)
            {
                if(next>curr) take=max(take,curr+solve(nums,1,i+1));
                else if(next<curr) take=max(take,curr+solve(nums,2,i+1));
            }
            else if(trend==2)
            {
                if(next<curr) take=max(take,curr+solve(nums,2,i+1));
                else if(next>curr) take=max(take,curr+solve(nums,3,i+1));
            }
            else if(trend==3 && next>curr) take=max(take,curr+solve(nums,3,i+1));
        }
        return dp[i][trend]=max(skip,take);
    }
    long long maxSumTrionic(vector<int>& nums) {
        n=nums.size();
        dp.assign(n+1,vector<long long>(4,-1));
        return solve(nums,0,0);
    }
};
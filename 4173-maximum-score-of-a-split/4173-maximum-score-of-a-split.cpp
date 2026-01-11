class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> presum(n);
        vector<int> sufMin(n,INT_MAX);
        presum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            presum[i]=presum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            sufMin[i]=min(sufMin[i+1],nums[i+1]);
        }
        long long ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,presum[i]-sufMin[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> sum(n);
        sum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sum[i]=sum[i+1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            double average=sum[i+1]/(n-i-1);
            if(nums[i]>average) ans++;
        }
        return ans;
    }
};
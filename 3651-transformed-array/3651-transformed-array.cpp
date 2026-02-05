class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                int ind=(i+nums[i])%n;
                ans[i]=nums[ind];
            }
            else
            {
                int ind=(n-(abs(nums[i])%n)+i)%n;
                ans[i]=nums[ind];
            }
        }
        return ans;
    }
};
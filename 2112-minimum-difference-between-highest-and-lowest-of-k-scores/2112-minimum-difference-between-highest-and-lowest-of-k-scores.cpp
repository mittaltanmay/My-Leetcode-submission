class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int n=nums.size();
        int i=0;
        if(k==1) return 0;
        for(int j=i+k-1;j<n;j++)
        {
            ans=min(ans,nums[j]-nums[i]);
            i++;
        }
        return ans;
    }
};
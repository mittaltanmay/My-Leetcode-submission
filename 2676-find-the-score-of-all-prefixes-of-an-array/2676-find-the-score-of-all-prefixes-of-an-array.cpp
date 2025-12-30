class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<int> maxi=nums;
        int n=nums.size();
        vector<long long> ans(n);
        for(int i=1;i<n;i++) maxi[i]=max(maxi[i-1],maxi[i]);
        for(int i=0;i<n;i++) ans[i]=nums[i]+maxi[i];
        for(int i=1;i<n;i++) ans[i]+=ans[i-1];
        return ans;
    }
};
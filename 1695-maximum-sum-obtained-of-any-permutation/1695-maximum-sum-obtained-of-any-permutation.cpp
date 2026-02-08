class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int> ct(n,0);
        for(int i=0;i<requests.size();i++)
        {
            ct[requests[i][0]]++;
            if(requests[i][1]+1<n) ct[requests[i][1]+1]--;
        }
        for(int i=1;i<n;i++) ct[i]+=ct[i-1];
        sort(ct.begin(),ct.end(),greater<int>());
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(ct[0]==0) break;
            ans+=(ct[i]*1LL*nums[i])%mod;
            ans=ans%mod;
        }
        return ans;
    }
};
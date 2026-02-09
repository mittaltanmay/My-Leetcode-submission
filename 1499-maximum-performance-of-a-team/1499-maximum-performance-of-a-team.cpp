class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> nums;
        for(int i=0;i<n;i++)
        {
            nums.push_back({efficiency[i],speed[i]});
        }
        sort(nums.begin(),nums.end(),greater<vector<int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long ans=0;
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i][1]);
            sum=(sum+nums[i][1]);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()<=k)
            {
                ans=max(ans,sum*1LL*nums[i][0]);
                // ans=ans%mod;
            }
        }
        return ans%mod;
    }
};
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> hsh;
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            hsh[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) continue;
            if(hsh.count(nums[i]*2))
            {
                if(hsh[nums[i]*2].size()<2) continue;
                vector<int> &temp=hsh[nums[i]*2];
                int ind=upper_bound(temp.begin(),temp.end(),i)-temp.begin();
                if(ind==0 || ind==temp.size()) continue;
                int left=ind;
                int right=temp.size()-ind;
                ans=(ans+left*1LL*right)%mod; 
            }
        }
        if(hsh.count(0) && hsh[0].size()>2)
        {
            vector<int> &temp=hsh[0];
            for(int i=1;i<temp.size()-1;i++)
            {
                int left=i;
                int right=temp.size()-i-1;
                ans=(ans+left*1LL*right)%mod;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        for(int i=2;i<=n;i++)
        {
            int l=0;
            int r=0;
            unordered_map<int,int> hsh;
            int sum=0;
            while(r<n)
            {
                if(r-l+1>i)
                {
                    sum-=nums[l];
                    hsh[nums[l]]--;
                    if(hsh[nums[l]]==0) hsh.erase(nums[l]);
                    l++;
                }
                hsh[nums[r]]++;
                sum+=nums[r];
                if(r-l+1==i)
                {
                    if(hsh.count(sum)) ans++;
                }
                r++;
            }
        }
        return ans;
    }
};
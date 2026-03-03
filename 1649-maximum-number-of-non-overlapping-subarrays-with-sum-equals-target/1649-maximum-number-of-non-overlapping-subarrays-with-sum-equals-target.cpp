class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<long long,int> hsh;
        int sum=0;
        hsh[0]=-1;
        int n=nums.size();
        int maxi=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum-target;
            if(hsh.count(rem))
            {
                ans++;
                // maxi=i+1;
                hsh.clear();
                hsh[0]=i;
                sum=0;
                continue;
            }
            hsh[sum]=i;
        }
        return ans;
    }
};
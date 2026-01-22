class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(!is_sorted(nums.begin(),nums.end()))
        {
            ans++;
            int n=nums.size();
            int min_sum=INT_MAX;
            int mini=-1;
            bool flag=false;
            for(int i=0;i<n-1;i++)
            {
                if(nums[i]+nums[i+1]<min_sum)
                {
                    min_sum=nums[i]+nums[i+1];
                    mini=i;
                    flag=true;
                }
            }
            if(flag)
            {
                nums[mini]=min_sum;
                nums.erase(nums.begin()+mini+1);
            }
        }
        return ans;
    }
};
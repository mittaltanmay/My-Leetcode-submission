class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            if(nums[i]==2) 
            {
                ans[i]=-1;
                continue;
            }
            for(int j=0;j<32;j++)
            {
                if((nums[i] & (1<<j))==0)
                {
                    int x=(nums[i]^(1<<(j-1)));
                    flag=true;
                    ans[i]=x;
                    break;
                }
            }
            if(!flag) ans[i]=-1;
        }
        return ans;
    }
};
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(n==3) return false;
        vector<int> increasing(n,1);
        vector<int> decreasing(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i]) increasing[i]=increasing[i-1]+1;
        }
        // cout<<increasing[n-1]<<endl;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i]) decreasing[i]=decreasing[i-1]+1;
        }
        cout<<decreasing[n-2]<<endl;
        for(int i=1;i<n-2;i++)
        {
            if(i+1==increasing[i])
            {
                for(int j=i+1;j<n-1;j++)
                {
                    if((j-i)+1==decreasing[j])
                    {
                        int len=((n-1)-j)+1;
                        if(len==increasing[n-1]) return true;
                    }
                }
            }
        }
        return false ;
    }
};
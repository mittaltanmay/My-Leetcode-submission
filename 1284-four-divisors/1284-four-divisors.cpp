class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int ct=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    int a=j;
                    int b=nums[i]/a;
                    if(a!=b)
                    {
                        ct+=2;
                        sum+=a+b;
                    }
                    else
                    {
                        ct++;
                        sum+=a;
                    }
                    if(ct>4) break;
                }
            }
            if(ct==4) ans+=sum;
        }
        return ans;
    }
};
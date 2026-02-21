class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<bool> prime(21,true);  
        prime[0]=prime[1]=false;
        for(int i=2;i*i<21;i++)
        {
            if(prime[i])
            {
                for(int j=i*2;j<21;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            int ct=0;
            for(int j=0;j<21;j++)
            {
                long long num=(1<<j);
                if(i & num) ct++;
            }
            if(prime[ct]) ans++;
        }
        return ans;
    }
};
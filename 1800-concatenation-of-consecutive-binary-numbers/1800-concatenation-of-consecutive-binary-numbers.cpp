class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
        int mod=1e9+7;
        // int len=0;
        for(int i=1;i<=n;i++)
        {
            int digit=log2(i)+1;
            ans=((ans<<digit)%mod+i)%mod;
            // len+=(digit+1);
        }
        return ans;
    }
};
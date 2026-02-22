class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<long long> fact(10,1);
        for(int i=1;i<10;i++)
        {
            fact[i]=fact[i-1]*1LL*i;
        }
        int temp=n;
        long long sum=0;
        vector<int> freq(10,0);
        while(n!=0)
        {
            int digit=n%10;
            n=n/10;
            sum+=fact[digit];
            freq[digit]++;
        }
        while(sum)
        {
            int digit=sum%10;
            sum=sum/10;
            freq[digit]--;
        }
        for(int i=0;i<10;i++) if(freq[i]!=0) return false;
        return true;
    }
};
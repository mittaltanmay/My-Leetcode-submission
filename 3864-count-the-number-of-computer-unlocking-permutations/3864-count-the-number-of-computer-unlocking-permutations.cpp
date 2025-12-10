class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for(int i=1;i<complexity.size();i++)
        {
            if(complexity[i]<=complexity[0]) return 0;
        }
        int mod=1e9+7;
        int n=complexity.size();
        vector<long long> fact(n+1,1);
        for(int i=2;i<=n;i++)
        {
            fact[i]=(fact[i-1]*1LL*i)%mod;
        }
        return fact[n-1];
    }
};
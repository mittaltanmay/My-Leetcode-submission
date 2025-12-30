class Solution {
public:
    int n;
    int part;
    bool isprime(char a)
    {
        if(a=='2' || a=='3' || a=='5' || a=='7') return true;
        return false;
    }
    int mod=1e9+7;
    int t[1001][1001];
    int solve(int i,vector<vector<int>> &dp,int ct)
    {
        if(t[i][ct]!=-1) return t[i][ct];
        if(ct>part) return 0;
        if(i>=n) 
        {
            if(ct==part) return 1;
            return 0;
        }
        long long ans=0;
        for(int ind=i;ind<n;ind++)
        {
            if(dp[i][ind]==1) ans+=solve(ind+1,dp,ct+1)%mod;
        }
        return t[i][ct]=ans%mod;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        n=s.size();
        part=k;
        memset(t,-1,sizeof(t));
        if(!isprime(s[0]) || isprime(s.back())) return 0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(!isprime(s[i])) continue;
            for(int j=i+1;j<n;j++)
            {
                if(!isprime(s[j]) && j-i+1>=minLength) dp[i][j]=1;
            }
        }
        return solve(0,dp,0)%mod;
    }
};
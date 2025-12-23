class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long sum=accumulate(cost.begin(),cost.end(),0LL);
        long long  ans=LONG_MAX;
        unordered_map<char,long long> hsh;
        for(int i=0;i<s.size();i++)
        {
            hsh[s[i]]+=cost[i];
        }
        for(auto it:hsh)
        {
            ans=min(ans,sum-it.second);
        }
        return ans;
    }
};
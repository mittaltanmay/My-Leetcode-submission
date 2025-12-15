class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        int i=0;
        while(i<n)
        {
            int j=i;
            while(j<n-1 && prices[j]-1==prices[j+1])
            {
                ans+=(j-i+1);
                j++;
            }
            ans+=(j-i+1);
            i=j+1;
        }
        return ans;
    }
};
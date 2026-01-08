class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,vector<int> &nums1,vector<int> &nums2)
    {
        if(i>=n || j>=m)
        {
            return -1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int take=nums1[i]*nums2[j];
        int take2=nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2);
        int skipi=solve(i+1,j,nums1,nums2);
        int skipj=solve(i,j+1,nums1,nums2);
        return dp[i][j]=max({take,take2,skipi,skipj});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memset(dp,-1,sizeof(dp));
        return  solve(0,0,nums1,nums2);
    }
};
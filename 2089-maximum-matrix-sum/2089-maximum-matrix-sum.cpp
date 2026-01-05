class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        int n=matrix.size();
        long long ans=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mini=min(mini,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
                if(matrix[i][j]<0) neg++;
            }
        }
        // cout<<ans<<" "<<mini;
        if(neg%2==0) return ans;
        return ans-2*mini;
    }
};
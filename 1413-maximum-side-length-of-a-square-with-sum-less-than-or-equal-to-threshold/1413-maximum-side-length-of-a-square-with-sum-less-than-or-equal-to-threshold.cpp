class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]<=threshold)
                {
                    ans=1;
                    break;
                }
            }
        }
        if(ans==-1) return 0;
        vector<vector<int>> temp=mat;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++) temp[i][j]+=temp[i][j-1];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++) temp[j][i]+=temp[j-1][i];
        }
        for(int l=2;l<=min(m,n);l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                for(int j=0;j<=m-l;j++)
                {
                    int st_col=j;
                    int st_row=i;
                    int end_col=j+l-1;
                    int end_row=i+l-1;
                    int sum=temp[end_row][end_col]-(st_col==0?0:temp[end_row][st_col-1])-(st_row==0?0:temp[st_row-1][end_col])+(st_row>0 && st_col>0?temp[st_row-1][st_col-1]:0);
                    if(sum<=threshold)
                    {
                        ans=l;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
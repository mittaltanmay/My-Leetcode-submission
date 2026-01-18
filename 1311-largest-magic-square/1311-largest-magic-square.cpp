class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> row_sum=grid;
        vector<vector<int>> col_sum=grid;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                row_sum[i][j]=row_sum[i][j-1]+grid[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                col_sum[j][i]=col_sum[j-1][i]+grid[j][i];
            }
        }
        vector<vector<int>> d1=grid;
        vector<vector<int>> d2=grid;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                d1[i][j]=d1[i-1][j-1]+grid[i][j];
            }  
        }
        for(int i=1;i<n;i++){
            for(int j=m-2;j>=0;j--){
                if(j+1<m) d2[i][j] += d2[i-1][j+1];
            }
        }
        int ans=1;
        for(int l=2;l<=min(m,n);l++)
        {
            for(int i=0;i<=n-l;i++)
            {
                bool flag=true;
                for(int j=0;j<=m-l;j++)
                {
                    int st_col=j;
                    int end_col=j+l-1;
                    int st_row=i;
                    int end_row=i+l-1;
                    int row=(st_col==0?row_sum[i][end_col]:row_sum[i][end_col]-row_sum[i][st_col-1]);
                    int col=(st_row==0?col_sum[end_row][j]:col_sum[end_row][j]-col_sum[st_row-1][j]);
                    int di1=(st_row==0 || st_col==0?d1[end_row][end_col]:d1[end_row][end_col]-d1[st_row-1][st_col-1]);
                    int di2 = d2[end_row][st_col] -((st_row>0 && end_col+1<m) ? d2[st_row-1][end_col+1] : 0);
                    if(row!=col || row!=di1 || di1!=di2 || row!=di2 || col!=di1 || col!=di2)
                    {
                        continue;
                    }
                    for(int r=st_row;r<=end_row;r++)
                    {
                        int sum=row_sum[r][end_col]-(st_col==0?0:row_sum[r][st_col-1]);
                        if(sum!=row)
                        {
                            flag=false;
                        }
                    }
                    for(int c=st_col;c<=end_col;c++)
                    {
                        int sum=col_sum[end_row][c]-(st_row==0?0:col_sum[st_row-1][c]);
                        if(sum!=col)
                        {
                            flag=false;
                        }
                    }
                    if(flag)
                    {
                        ans=max(ans,l);
                        break;
                    }
                }

            }
        }
        return ans;
    }
};
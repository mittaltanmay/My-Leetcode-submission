class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int,greater<int>> hsh;
        vector<vector<long long>> temp(n,vector<long long>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                temp[i][j]=grid[i][j];
            }
        }
        vector<vector<long long>> d1=temp;
        vector<vector<long long>> d2=temp;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                d1[i][j]+=d1[i-1][j-1];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=m-2;j>=0;j--)
            {
                d2[i][j]+=d2[i-1][j+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                hsh.insert(grid[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                for(int l=1;l<=j;l++)
                {
                    int row1=i;
                    int row2=i+l;
                    int row3=i+2*l;
                    int col1=j;
                    int col2=j-l;
                    int col3=j+l;

                    if(row2>=n || row3>=n || col2<0 || col3>=m) break;

                    int side1=d2[row2][col2]-(i==0 || j==m-1?0:d2[i-1][j+1]);
                    int side2=d2[row3][col1]-(row2==0 || col3==m-1?0:d2[row2-1][col3+1]);
                    int side3=d1[row2][col3]-(i==0 || j==0?0:d1[i-1][j-1]);
                    int side4=d1[row3][col1]-(row2==0 || col2==0?0:d1[row2-1][col2-1]);
                    
                    hsh.insert(side1+side2+side3+side4-temp[row1][col1]-temp[row2][col2]-temp[row2][col3]-temp[row3][col1]);
                }
            }
        }
        vector<int> ans;
        for(auto it=hsh.begin();it!=hsh.end();it++)
        {
            ans.push_back(*it);
            if(ans.size()==3) break;
        }
        return ans;

    }
};
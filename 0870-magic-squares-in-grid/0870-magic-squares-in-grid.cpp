class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row<3 || col<3) return 0;
        int ans=0;
        for(int i=0;i<=row-3;i++)
        {
            for(int j=0;j<=col-3;j++)
            {
                unordered_set<int> hsh;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++) 
                    {
                        if(grid[k][l]>=1 && grid[k][l]<=9) hsh.insert(grid[k][l]);
                    }
                }
                if(hsh.size()==9){
                int row1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                int row2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                int row3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                if(row1!=row2 || row1!=row3 || row2!=row3) continue;
                int col1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int col2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                int col3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                if(row1!=col1 || row1!=col2 || row1!=col3) continue;
                int dig1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int dig2=grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
                if(row1!=dig1 || row1!=dig2) continue;
                ans++;}
            }
        }
        return ans;
    }
};
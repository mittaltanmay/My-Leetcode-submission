class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>> col; // storing the col along with all the x values present in that column   
        unordered_map<int,vector<int>> row; // storing the row along with all the y values present in that row 
        int m=buildings.size();
        for(int i=0;i<m;i++)
        {
            col[buildings[i][1]].push_back(buildings[i][0]);
            row[buildings[i][0]].push_back(buildings[i][1]);
        }
        for(auto &it:col)
        {
            sort(it.second.begin(),it.second.end());
        }
        for(auto &it:row)
        {
            sort(it.second.begin(),it.second.end());
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int r=buildings[i][0];
            int c=buildings[i][1];
            vector<int> &temp1=row[r];
            vector<int> &temp2=col[c];
            int ind1=lower_bound(temp1.begin(),temp1.end(),c)-temp1.begin(); // where y value lies in the column value of row 
            int ind2=lower_bound(temp2.begin(),temp2.end(),r)-temp2.begin(); // where x value lies in the row value of column

            if((ind1>0 && ind1<temp1.size()-1) && (ind2>0 && ind2<temp2.size()-1)) ans++; // a point will be covered if it between the coordiantes for both row and column
        }
        return ans;
    }
};
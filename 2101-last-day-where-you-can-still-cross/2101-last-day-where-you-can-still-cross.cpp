class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0;
        int r=cells.size()-1;
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        int ans=cells.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            queue<pair<int,int>> q;
            bool flag=false;
            vector<vector<int>> grid(row,vector<int> (col,0));
            vector<vector<bool>> visited(row,vector<bool>(col,false));
            for(int i=0;i<=mid;i++)
            {
                grid[cells[i][0]-1][cells[i][1]-1]=1;
                if(cells[i][1]-1==0) 
                {
                    q.push({cells[i][0]-1,cells[i][1]-1});
                    visited[cells[i][0]-1][cells[i][1]-1]=true;
                }
            }
            while(!q.empty())
            {
                int n=q.size();
                while(n--)
                {
                    int u=q.front().first;
                    int v=q.front().second;
                    q.pop();
                    if(v==col-1)
                    {
                        flag=true;
                        break;
                    }
                    for(auto it:dir)
                    {
                        int u_=u+it[0];
                        int v_=v+it[1];
                        if(u_<0 || u_>=row || v_<0 || v_>=col || visited[u_][v_] || grid[u_][v_]==0) continue;
                        visited[u_][v_]=true;
                        q.push({u_,v_});
                    }
                }
                if(flag) break;
            }
            if(flag)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> pairing(n,vector<int> (n,-1));
        // unordered_set<int> paired;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<preferences[i].size();j++)
            {
                pairing[i][preferences[i][j]]=preferences[i].size()-j;
            }
        }
        vector<int> pair(n,-1);
        for(int i=0;i<pairs.size();i++)
        {
            pair[pairs[i][1]]=pairs[i][0];
            pair[pairs[i][0]]=pairs[i][1];
        }
        int ans=0;
        for(int i=0;i<pairs.size();i++)
        {
            int x=pairs[i][0];
            int y=pairs[i][1];
            for(auto u:preferences[x])
            {
                if(pair[u]!=-1 && u!=y)
                {
                    int v=pair[u];
                    if(pairing[x][y]<pairing[x][u] && pairing[u][v]<pairing[u][x]) 
                    {
                        ans++;
                        break;
                    }
                }
            }
            for(auto u:preferences[y])
            {
                if(pair[u]!=-1 && x!=u)
                {
                    int v=pair[u];
                    if(pairing[y][x]<pairing[y][u] && pairing[u][v]<pairing[u][y]) 
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
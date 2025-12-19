class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<meetings.size();i++)
        {
            adj[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            adj[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        vector<bool> visited(n,false);
        while(!pq.empty())
        {
            int curr=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(visited[u]) continue;
            visited[u]=true;
            for(auto it:adj[u])
            {
                if(curr<=it.second && !visited[it.first])
                {
                    pq.push({it.second,it.first});
                    
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) if(visited[i]) ans.push_back(i);
        return ans;
    }
};
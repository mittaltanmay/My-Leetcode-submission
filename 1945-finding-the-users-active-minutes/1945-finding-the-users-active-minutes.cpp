class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>> hsh;
        for(int i=0;i<logs.size();i++)
        {
            int u=logs[i][0];
            int min=logs[i][1];
            hsh[u].insert(min);
        }
        vector<int> ans(k,0);
        for(auto it:hsh)
        {
            int uam=it.second.size();
            ans[uam-1]++;
        }
        return ans;
    }
};
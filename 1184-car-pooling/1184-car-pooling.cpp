class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> pool;
        for(int i=0;i<trips.size();i++)
        {
            pool.push_back({trips[i][1],trips[i][0]});
            pool.push_back({trips[i][2],-1*trips[i][0]});
        }
        sort(pool.begin(),pool.end());
        int curr=0;
        for(int i=0;i<pool.size();i++)
        {
            curr+=pool[i][1];
            if(curr>capacity) return false;
        }
        return true;
    }
};
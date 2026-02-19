class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int> hsh;
        for(auto it:bulbs)
        {
            if(!hsh.count(it)) hsh.insert(it);
            else hsh.erase(it);
        }
        vector<int> ans(hsh.begin(),hsh.end());
        return ans;
    }
};
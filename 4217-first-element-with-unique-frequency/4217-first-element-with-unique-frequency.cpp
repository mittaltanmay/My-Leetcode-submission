class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> hsh;
        for(auto it:nums) hsh[it]++;
        unordered_map<int,int> ct;
        for(auto it:hsh) ct[it.second]++;
        for(auto it:nums) if(ct[hsh[it]]==1) return it;
        return -1;
    }
};
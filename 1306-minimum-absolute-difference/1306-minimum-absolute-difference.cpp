class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-1;i++) mini=min(mini,nums[i+1]-nums[i]);
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]==mini) ans.push_back({nums[i],nums[i+1]});
        }
        return ans;
    }
};
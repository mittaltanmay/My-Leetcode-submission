class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> hsh;
        int span=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(hsh.count(nums[i]) && hsh[nums[i]]>span)
            {
                int ct=((hsh[nums[i]])/3)+1;
                span=3*ct-1;
            }
            hsh[nums[i]]=i;
        }
        if(span==-1) return 0; 
        int ans=(span/3)+1;
        return ans;
    }
};
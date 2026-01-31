class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int ct=0;
        vector<int> positive;
        vector<int> pos;
        for(int i=0;i<nums.size();i++) 
        {
            if(nums[i]>=0)
            {
                ct++;
                positive.push_back(nums[i]);
                pos.push_back(i);
            }
        }
        if(ct<=1) return nums;
        k=k%ct;
        int i=k;
        int p=0;
        while(true)
        {
            nums[pos[p]]=positive[i];
            i=(i+1)%ct;
            p++;
            if(i==k) break;
        }
        return nums;
    }
};
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        vector<int> scores(2,0);
        int active=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
            {
                active=(active+1)%2;
            }
            if((i+1)%6==0)
            {
                active=(active+1)%2;
            }
            scores[active]+=nums[i];
        }
        return scores[0]-scores[1];
    }
};
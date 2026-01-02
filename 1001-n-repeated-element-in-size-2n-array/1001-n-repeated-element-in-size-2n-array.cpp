class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0);
        for(int i=0;i<2*n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<=maxi;i++) if(freq[i]==n) return i;
        return 0;
    }
};
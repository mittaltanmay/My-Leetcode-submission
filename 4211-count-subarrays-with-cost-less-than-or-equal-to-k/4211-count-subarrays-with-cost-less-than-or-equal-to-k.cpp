class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> inc;
        deque<int> dec;
        int l=0;
        int r=0;
        int n=nums.size();
        long long ans=0;
        while(r<n)
        {
            while(!dec.empty() && nums[dec.back()]>nums[r]) dec.pop_back();
            while(!inc.empty() && nums[inc.back()]<nums[r]) inc.pop_back();
            dec.push_back(r);
            inc.push_back(r);
            while(l<=r && (nums[inc.front()]-nums[dec.front()])*1LL*(r-l+1)>k)
            {
                l++;
                while(!dec.empty() && dec.front()<l) dec.pop_front();
                while(!inc.empty() && inc.front()<l) inc.pop_front();
            }
            if(l<=r) ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};
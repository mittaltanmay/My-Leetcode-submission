class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> hsh;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            hsh[nums[i]%3].push_back(nums[i]);
        }
        for(auto &it:hsh)
        {
            sort(it.second.begin(),it.second.end());
        }
        int ans=0;
        if(hsh.count(1) && hsh[1].size()>=3)
        {
            vector<int> &temp=hsh[1];
            int sum=0;
            for(int i=temp.size()-1;i>=(int)temp.size()-3;i--) sum+=temp[i];
            ans=max(ans,sum);
        }
        if(hsh.count(2) && hsh[2].size()>=3)
        {
            vector<int> &temp=hsh[2];
            int sum=0;
            for(int i=temp.size()-1;i>=(int)temp.size()-3;i--) sum+=temp[i];
            ans=max(ans,sum);
        }
        if(hsh.count(0) && hsh[0].size()>=3)
        {
            vector<int> &temp=hsh[0];
            int sum=0;
            for(int i=temp.size()-1;i>=(int)temp.size()-3;i--) sum+=temp[i];
            ans=max(ans,sum);
        }
        if(hsh.count(0) && hsh.count(2) && hsh.count(1) && hsh[0].size()>=1 && hsh[2].size()>=1 && hsh[1].size()>=1) ans=max(ans,hsh[0].back()+hsh[1].back()+hsh[2].back());
        return ans;
    }
};
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n);
        vector<int> next(n);
        int bad_pair=0;
        vector<long long> temp(n); 
        for(int i=0;i<n;i++) temp[i]=nums[i];
        set<pair<long long,int>> hsh;
        prev[0]=-1;
        next[n-1]=n;
        for(int i=0;i<n-1;i++)
        {
            if(temp[i]>temp[i+1]) bad_pair++;
            next[i]=i+1;
            hsh.insert({temp[i]+temp[i+1],i});
        }
        for(int i=n-1;i>0;i--) prev[i]=i-1;
        int ans=0;
        while(bad_pair)
        {
            int first=hsh.begin()->second;
            int second=next[first];

            int first_left=prev[first];
            int second_right=next[second];

            int sum=hsh.begin()->first;
            hsh.erase(hsh.begin());
            if(temp[first]>temp[second]) bad_pair--;
            if(first_left!=-1)
            {
                if(temp[first_left]<=temp[first] && temp[first_left]>temp[first]+temp[second]) bad_pair++;
                else if(temp[first_left]>temp[first] && temp[first_left]<=temp[first]+temp[second]) bad_pair--;
                hsh.erase({temp[first]+temp[first_left],first_left});
                hsh.insert({temp[first]+temp[first_left]+temp[second],first_left});
            }
            if(second_right<n)
            {
                if(temp[second_right]>=temp[second] && temp[second_right]<temp[first]+temp[second]) bad_pair++;
                else if(temp[second_right]<temp[second] && temp[second_right]>=temp[first]+temp[second]) bad_pair--;
                hsh.erase({temp[second]+temp[second_right],second});
                hsh.insert({temp[second]+temp[first]+temp[second_right],first});
                prev[second_right]=first;
            }
            next[first]=second_right;
            temp[first]=temp[first]+temp[second];
            ans++;
        }
        return ans;
    }
};
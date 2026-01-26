class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(),logs.end());
        int n=logs.size();
        vector<vector<int>> sweep;
        for(int i=0;i<n;i++)
        {
            sweep.push_back({logs[i][0],1});
            sweep.push_back({logs[i][1],-1});
        }
        sort(sweep.begin(),sweep.end());
        int ans=INT_MAX;
        int curr=0;
        int maxi=0;
        for(int i=0;i<sweep.size();i++)
        {
            curr+=sweep[i][1];
            if(curr>maxi)
            {
                maxi=curr;
                ans=sweep[i][0];
            }
            else if(curr==maxi)
            {
                ans=min(ans,sweep[i][0]);
            }
        }
        return ans;
    }
};
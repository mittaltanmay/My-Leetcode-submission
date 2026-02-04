class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        unordered_map<int,long long> hsh;
        vector<vector<long long>> out;
        int n=segments.size();
        for(int i=0;i<n;i++)
        {
            hsh[segments[i][0]]+=segments[i][2];
            out.push_back({segments[i][1],-1*segments[i][2]});
        }
        for(auto it:hsh) out.push_back({it.first,it.second});
        sort(out.begin(),out.end());
        int st=-1;
        long long curr=0;
        vector<vector<long long>> ans;
        for(int i=0;i<out.size();i++)
        {
            if(st!=-1 && st!=out[i][0]) 
            {
                if(curr!=0) ans.push_back({st,out[i][0],curr});
            } 
            curr+=out[i][1];
            st=out[i][0];
        }
        return ans;
    }
};
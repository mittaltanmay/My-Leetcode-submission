class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vfences) {
        unordered_set<int> width;
        unordered_set<int> height;
        for(int i=0;i<hFences.size();i++)
        {
            height.insert(abs(1-hFences[i]));
            height.insert(abs(m-hFences[i]));
            for(int j=i+1;j<hFences.size();j++)
            {
                height.insert(abs(hFences[i]-hFences[j]));
            }
        }
        height.insert(m-1);
        for(int i=0;i<vfences.size();i++)
        {
            width.insert(abs(1-vfences[i]));
            width.insert(abs(n-vfences[i]));
            for(int j=i+1;j<vfences.size();j++)
            {
                width.insert(abs(vfences[i]-vfences[j]));
            }
        }
        width.insert(n-1);
        int ans=-1;
        int mod=1e9+7;
        int maxs=0;
        for(auto it:height)
        {
            if(width.count(it))
            {
                maxs=max(maxs,it);
            }
        }
        return (maxs==0?-1:(maxs*1LL*maxs)%mod);
    }
};
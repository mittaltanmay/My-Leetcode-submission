class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans=1;
        int mod=1e9+7;
        long long seats=0;
        int n=corridor.size();
        for(int i=0;i<n;i++) if(corridor[i]=='S') seats++;
        if(seats&1 || seats==0) return 0;
        vector<pair<int,int>> section;
        int i=0;
        while(i<n)
        {
            if(corridor[i]=='S')
            {
                int j=i;
                seats=0;
                while(j<n && seats!=2)
                {
                    if(corridor[j]=='S') seats++;
                    if(seats==2) break;
                    j++;
                }
                section.push_back({i,j});
                i=j+1;
            }
            else i++;
        }
        if(section.size()==1) return 1;
        for(int i=0;i<section.size()-1;i++)
        {
            long long  spaces=section[i+1].first-section[i].second;
            if(spaces==0) continue;
            else ans=ans*1LL*spaces;
            ans%=mod;
        }
        return ans%mod;
    }
};
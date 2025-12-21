class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int n=strs.size();
        int m=strs[0].size();
        vector<bool> ok(n-1,false); 
        for(int i=0;i<m;i++)
        {
            bool flag=true;
            for(int j=0;j<n-1;j++)
            {
                if(!ok[j] && strs[j][i]>strs[j+1][i])
                {
                    ans++;
                    flag=false;
                    break;
                }
            }
            if(flag) 
            {
                for(int j=0;j<n-1;j++)
                {
                    if(!ok[j] && strs[j][i]<strs[j+1][i]) ok[j]=true;
                }
            }
        }
        return ans;
    }
};
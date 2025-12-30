class Solution {
public:
    int t[21][21];
    bool solve(string s,string p,int i,int j)
    {
        if(j==p.size())
        {
            if(i==s.size()) return true;
            return false;
        }
        if(t[i][j]!=-1) return t[i][j];
        bool first_check=(i<s.size() && (s[i]==p[j] || p[j]=='.'));
        if(p[j+1]=='*')
        {
            bool not_take=solve(s,p,i,j+2);
            bool take=(first_check && solve(s,p,i+1,j));
            return t[i][j]=take || not_take;
        }
        return t[i][j]=first_check && solve(s,p,i+1,j+1);
    }
    bool isMatch(string s, string p) {
        memset(t,-1,sizeof(t));
        return solve(s,p,0,0);
    }
};
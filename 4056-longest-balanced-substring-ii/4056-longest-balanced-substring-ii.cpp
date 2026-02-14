class Solution {
public:
    int n;
    int solve(string &s,char ch1,char ch2)
    {
        int ct1=0;
        int ct2=0;
        int ans=0;
        unordered_map<int,int> hsh; 
        // hsh[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=ch1 && s[i]!=ch2)
            {
                ct1=0;
                ct2=0;
                hsh.clear();
                continue;
            }
            if(s[i]==ch1) ct1++;
            else if(s[i]==ch2) ct2++;
            if(ct1==ct2) ans=max(ans,ct1+ct2);
            int diff=ct1-ct2;
            if(hsh.count(diff))
            {
                ans=max(ans,i-hsh[diff]);
            }
            else hsh[diff]=i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        n=s.size();
        int ans=1;
        int ct=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1]) ct++;
            else ct=1;
            ans=max(ans,ct);
        }
        ans=max(ans,solve(s,'a','b'));
        ans=max(ans,solve(s,'a','c'));
        ans=max(ans,solve(s,'c','b'));

        int ct1=0;
        int ct2=0;
        int ct3=0;
        unordered_map<string,int> hsh;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') ct1++;
            else if(s[i]=='b') ct2++;
            else ct3++;
            if(ct1==ct2 && ct1==ct3) ans=max(ans,ct1+ct2+ct3);
            int diff1=ct1-ct2;
            int diff2=ct1-ct3;

            string key=to_string(diff1)+'_'+to_string(diff2);

            if(hsh.count(key)) ans=max(ans,i-hsh[key]);
            else hsh[key]=i;
        }
        return ans;
    }
};
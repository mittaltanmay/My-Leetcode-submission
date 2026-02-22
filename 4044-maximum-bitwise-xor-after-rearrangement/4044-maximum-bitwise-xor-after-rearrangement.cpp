class Solution {
public:
    string maximumXor(string s, string t) {
        int one=0;
        int zero=0;
        for(auto it:t)
        {
            if(it=='0') zero++;
            else one++;
        }
        string ans="";
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1' && zero)
            {
                ans+='1';
                zero--;
            }
            else if(s[i]=='0' && one)
            {
                ans+='1';
                one--;
            }
            else
            {
                ans+='0';
                zero-=(s[i]=='0');
                one-=(s[i]=='1');
            }
        }
        return ans;
    }
};
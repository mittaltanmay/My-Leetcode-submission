class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0;
        int ans=0;
        int n=s.size();
        int i=0;
        while(i<n)
        {
            int ct=0;
            int j=i;
            while(j<n && s[i]==s[j])
            {
                ct++;
                j++;
            }
            ans+=min(prev,ct);
            prev=ct;
            i=j;
        }
        return ans;
    }
};
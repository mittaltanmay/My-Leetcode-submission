class Solution {
public:
    int countGoodSubstrings(string s) {
        vector<int> freq(26,0);
        int i=0;
        int n=s.size();
        int ct=0;
        int ans=0;
        for(int j=0;j<n;j++)
        {
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==1) ct++;
            if(j-i+1==3)
            {
                if(ct==3) ans++;
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) ct--;
                i++; 
            }
        }
        return ans;
    }
};
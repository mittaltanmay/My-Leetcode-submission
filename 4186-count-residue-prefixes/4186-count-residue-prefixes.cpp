class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> hsh;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            hsh.insert(s[i]);
            if(hsh.size()==(i+1)%3)  ans++;
        }
        return ans;
    }
};
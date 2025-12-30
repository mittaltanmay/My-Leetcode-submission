class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small(26,0);
        vector<int> big(26,0);
        vector<bool> special(26,true);
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>='A' && word[i]<='Z') big[word[i]-'A']++;
            if(word[i]>='a' && word[i]<='z')
            {
                int ind=(word[i]-32)-'A';
                if(big[ind]!=0) special[word[i]-'a']=false;
                small[word[i]-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(special[i] && big[i]!=0 && small[i]!=0) ans++;
        }
        return ans;
    }
};
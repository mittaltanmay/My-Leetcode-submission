class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int> hsh;
        sort(words.begin(),words.end());
        for(int i=0;i<words.size();i++)
        {
            // vector<int> freq(26,0);
            if(words[i].size()<k) continue;
            string key="";
            for(int j=0;j<k;j++)
            {
                key+=words[i][j];
            }
            hsh[key]++;
        }
        int ans=0;
        for(auto it:hsh) if(it.second>1) ans++;
        return ans;
    }
};
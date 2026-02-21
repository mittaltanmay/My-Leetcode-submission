class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto word:words)
        {
            int sum=0;
            for(auto it:word)
            {
                sum+=weights[it-'a'];
            }
            sum%=26;
            ans+=char(26-sum+'a'-1);
        }
        return ans;
    }
};
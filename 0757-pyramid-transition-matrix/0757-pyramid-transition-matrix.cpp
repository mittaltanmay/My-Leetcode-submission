class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(string bottom,int i,string temp,unordered_map<string,vector<char>> &hsh)
    {
        if(bottom.size()==1) return true;
        if(i==0 && dp.count(bottom)) return dp[bottom];
        string key=bottom.substr(i,2);
        if(!hsh.count(key)) return false; 
        vector<char> &all=hsh[key];
        bool ans=false;
        for(auto it:all)
        {
            temp+=it;
            if(i==((int)bottom.size()-2)) ans|=solve(temp,0,"",hsh);
            else ans|=solve(bottom,i+1,temp,hsh);
            temp.pop_back(); 
        }
        if(i==0) dp[bottom]=ans;
        return ans;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> hsh;
        int n=allowed.size();
        for(int i=0;i<n;i++)
        {
            string bot=allowed[i].substr(0,2);
            hsh[bot].push_back(allowed[i][2]);
        }
        string temp="";
        return solve(bottom,0,temp,hsh);
    }
};
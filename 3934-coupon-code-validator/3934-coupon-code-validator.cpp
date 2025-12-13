class Solution {
public:
    bool check(string s)
    {
        if(s=="") return false;
        for(auto it:s)
        {
            if((it<'a' || it>'z') &&  (it<'A' || it>'Z') && (it!='_') && (it<'0' || it>'9')) return  false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string,vector<string>> hsh;
        int n=code.size();
        for(int i=0;i<n;i++)
        {
            if(check(code[i]) && (businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy" || businessLine[i]=="restaurant") && isActive[i])
            {
                hsh[businessLine[i]].push_back(code[i]);
            }
        }
        for(auto &it:hsh)
        {
            sort(it.second.begin(),it.second.end());
        }
        vector<string> ans;
        for(auto it:hsh)
        {
            for(auto val:it.second) ans.push_back(val);
        }
        return ans;
    }
};
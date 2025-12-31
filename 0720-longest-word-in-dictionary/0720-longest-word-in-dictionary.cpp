class Solution {
public:
    class mysort
    {
        public:
        bool operator()(const string &a,const string &b)
        {
            if(a.size()==b.size()) return a>b;
            return a.size()<b.size();
        }
    };
    string longestWord(vector<string>& words) {
      unordered_set<string> hsh;
      sort(words.begin(),words.end(),mysort());
      string ans="";
      hsh.insert("");
      for(int i=0;i<words.size();i++)
      {
        string word=words[i];
        bool flag=true;
        string temp="";
        for(int j=0;j<word.size()-1;j++)
        {
            temp+=word[j];
            if(!hsh.count(temp))
            {
                flag=false;
                break;
            }
        }
        hsh.insert(word);
        if(temp=="" || flag)
        {
            if(ans.size()<word.size()) ans=word;
            if(ans.size()==word.size()) ans=min(ans,word);
        }
      }  
      return ans;
    }
};
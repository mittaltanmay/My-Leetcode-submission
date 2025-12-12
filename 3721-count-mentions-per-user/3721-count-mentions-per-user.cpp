class Solution {
public:
    class mysort
    {
        public:
        bool operator()(vector<string> &a,vector<string> &b)
        {
            if(a[1]==b[1]) return a[0][0]>b[0][0];
            return stoi(a[1])<stoi(b[1]);
        }
    };
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        unordered_map<int,int> offline;
        vector<int> ans(numberOfUsers);
        int n=events.size();
        sort(events.begin(),events.end(),mysort());
        // for(int i=0;i<events.size();i++)
        // {
        //     cout<<events[i][0]<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            int timestamp=stoi(events[i][1]);
            vector<int> toremove;
            for(auto &it:offline) if(timestamp>=it.second) toremove.push_back(it.first);
            for(auto it:toremove) offline.erase(it);
            if(events[i][0]=="MESSAGE")
            {
                if(events[i][2]=="ALL")
                {
                    for(int j=0;j<numberOfUsers;j++) 
                    {
                        ans[j]++;
                    }
                }
                else if(events[i][2]=="HERE")
                {
                    for(int j=0;j<numberOfUsers;j++)
                    {
                        if(!offline.count(j))
                        {
                            ans[j]++;
                        }
                    }
                }
                else
                {
                    for(int j=0;j<events[i][2].size();j++)
                    {
                        if(events[i][2][j]=='d')
                        {
                            int id=0;
                            j++;
                            while(j<events[i][2].size() && events[i][2][j]!=' ')
                            {
                                id=id*10+(events[i][2][j]-'0');
                                j++;
                            }
                            ans[id]++;
                        }
                    }
                }   
            }
            else
            {
                int id=stoi(events[i][2]);
                offline[id]=timestamp+60;
            }
        }
        return ans;   
    }
};
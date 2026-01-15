class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int length=1;
        int height=1;
        int ct=1;
        for(int i=1;i<hBars.size();i++)
        {
            if(hBars[i]==hBars[i-1]+1) ct++;
            else ct=1;
            length=max(ct,length);
        }
        ct=1;
        for(int i=1;i<vBars.size();i++)
        {
            if(vBars[i]==vBars[i-1]+1) ct++;
            else ct=1;
            height=max(ct,height);
        }
        int side=min(height,length)+1;
        return side*side;
    }
};
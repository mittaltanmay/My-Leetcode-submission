class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minr=m;
        int minc=n;
        for(int i=0;i<ops.size();i++)
        {
            minr=min(minr,ops[i][0]);
            minc=min(minc,ops[i][1]);
        }
        return minr*minc;

    }
};
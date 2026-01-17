class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        vector<vector<int>> intersect;
        long long ans=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++)
        {
            int x1=bottomLeft[i][0];
            int y1=bottomLeft[i][1];
            int x3=topRight[i][0];
            int y3=topRight[i][1];
            for(int j=i+1;j<n;j++)
            {
                int x2=bottomLeft[j][0];
                int y2=bottomLeft[j][1];
                int x4=topRight[j][0];
                int y4=topRight[j][1];

                if(max(x1,x2)<=min(x3,x4) && max(y1,y2)<=min(y3,y4))
                {
                    int x_=max(x1,x2);
                    int y_=max(y1,y2);
                    int x5=min(x3,x4);
                    int y5=min(y3,y4);

                    long long l=min(abs(x_-x5),abs(y_-y5));
                    ans=max(ans,l*l);
                }
            }
        }
        return ans;
    }
};
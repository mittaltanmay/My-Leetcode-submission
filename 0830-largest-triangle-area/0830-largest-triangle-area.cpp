class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0.00000;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    double first=(points[i][0]*points[j][1]+points[j][0]*points[k][1]+points[k][0]*points[i][1])*1.00000;
                    double second=(points[i][1]*points[j][0]+points[j][1]*points[k][0]+points[k][1]*points[i][0])*1.00000;
                    ans=max(ans,(abs(first-second)/2.00000));
                }
            }
        }
        return ans;
    }
};
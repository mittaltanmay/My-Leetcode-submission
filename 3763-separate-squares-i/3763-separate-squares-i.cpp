class Solution {
public:
    double find(vector<vector<int>> &squares,double mid)
    {
        int n=squares.size();
        double area=0.0;
        for(int i=0;i<n;i++)
        {
            if((double)squares[i][1]+(double)squares[i][2]<=mid)
            {
                area+=squares[i][2]*1.0*squares[i][2];
            }
            else if((double)squares[i][1]<mid && mid<(double)(squares[i][1]+squares[i][2]))
            {
                double min_len=1.0*(mid-squares[i][1]);
                area+=min_len*1.0*squares[i][2];
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double low=INT_MAX;
        double high=INT_MIN;
        long double total=0.0;
        for(int i=0;i<n;i++)
        {
            low=min((double)squares[i][1],low);
            high=max((double)squares[i][1]+(double)squares[i][2],high);
            total+=(double)(squares[i][2]*1LL*squares[i][2]);
            // sides.push_back(squares[i][1],squares[i][1]+squares[i][2]);
        }
        double ans=0.0;
        while(high-low>1e-5)
        {
            double mid=(high+low)/2.0;
            double lower_area=find(squares,mid);
            ans=mid;
            if(lower_area>=total/(2.0))
            {
                high=mid;
            }
            else low=mid;
        }
        return ans;
    }
};
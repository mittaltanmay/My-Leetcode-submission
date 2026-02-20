class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flights(n+2,0);
        for(int i=0;i<bookings.size();i++)
        {
            flights[bookings[i][0]]+=bookings[i][2];
            flights[bookings[i][1]+1]-=bookings[i][2]; 
        }
        vector<int> ans;
        for(int i=1;i<flights.size()-1;i++)
        {
            flights[i]+=flights[i-1];
            ans.push_back(flights[i]);
        }
        return ans;
    }
};
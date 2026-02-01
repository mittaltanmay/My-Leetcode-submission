class MyCalendarThree {
public:
    map<int,int> hsh;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        hsh[startTime]++;
        hsh[endTime]--;
        int ans=0;
        int ct=0;
        for(auto it:hsh)
        {
            ct+=it.second;
            ans=max(ans,ct);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
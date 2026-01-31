class MyCalendarTwo {
public:
    map<int,int> hsh;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        hsh[startTime]++;
        hsh[endTime]--;
        int ct=0;
        for(auto it:hsh)
        {
            ct+=it.second;
            if(ct>=3) 
            {
                hsh[startTime]--;
                hsh[endTime]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
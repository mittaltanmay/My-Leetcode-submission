class RideSharingSystem {
public: 
    list<int> rider;
    queue<int> driver;
    unordered_map<int,int> match;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.size()==0 || driver.empty()) return {-1,-1};
        vector<int> ans={driver.front(),rider.front()};
        match[rider.front()]=driver.front();
        rider.pop_front();
        driver.pop();
        return ans; 
    }
    
    void cancelRider(int riderId) {
        if(!match.count(riderId))
        {
            auto it=find(rider.begin(),rider.end(),riderId);
            if(it!=rider.end()) rider.erase(it);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
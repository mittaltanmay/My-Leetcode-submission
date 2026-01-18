class AuctionSystem {
public:
    // (userId,itemId) -> bidAmount
    map<pair<int,int>, int> userBid;

    // itemId -> (bidAmount -> set of users with that bid)
    unordered_map<int, map<int, set<int>>> itemBids;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        // if already bid exists, update it
        if (userBid.count({userId, itemId})) {
            updateBid(userId, itemId, bidAmount);
            return;
        }

        userBid[{userId, itemId}] = bidAmount;
        itemBids[itemId][bidAmount].insert(userId);
    }

    void updateBid(int userId, int itemId, int newAmount) {
        auto key = make_pair(userId, itemId);
        if (!userBid.count(key)) return; // if not present do nothing (optional)

        int oldAmount = userBid[key];

        // remove from old amount bucket
        auto &mp = itemBids[itemId];
        mp[oldAmount].erase(userId);
        if (mp[oldAmount].empty()) mp.erase(oldAmount);

        // insert new
        userBid[key] = newAmount;
        mp[newAmount].insert(userId);
    }

    void removeBid(int userId, int itemId) {
        auto key = make_pair(userId, itemId);
        if (!userBid.count(key)) return;

        int amt = userBid[key];
        userBid.erase(key);

        auto &mp = itemBids[itemId];
        mp[amt].erase(userId);
        if (mp[amt].empty()) mp.erase(amt);

        if (mp.empty()) itemBids.erase(itemId);
    }

    int getHighestBidder(int itemId) {
        if (!itemBids.count(itemId)) return -1;

        auto &mp = itemBids[itemId];

        // highest bidAmount
        auto it = mp.rbegin();

        // among those users, max userId
        return *(it->second.rbegin());
    }
};

class FrontMiddleBackQueue {
public:
    list<int> first, second;

    FrontMiddleBackQueue() {}

    void rebalance() {
        if (first.size() > second.size() + 1) {
            second.push_front(first.back());
            first.pop_back();
        } else if (first.size() < second.size()) {
            first.push_back(second.front());
            second.pop_front();
        }
    }

    void pushFront(int val) {
        first.push_front(val);
        rebalance();
    }

    void pushMiddle(int val) {
        if (first.size() > second.size()) {
            second.push_front(first.back());
            first.pop_back();
        }
        first.push_back(val);
    }

    void pushBack(int val) {
        second.push_back(val);
        rebalance();
    }

    int popFront() {
        if (first.empty()) return -1;
        int val = first.front();
        first.pop_front();
        rebalance();
        return val;
    }

    int popMiddle() {
        if (first.empty()) return -1;
        int val = first.back();
        first.pop_back();
        rebalance();
        return val;
    }

    int popBack() {
        if (first.empty() && second.empty()) return -1;
        int val;
        if (!second.empty()) {
            val = second.back();
            second.pop_back();
        } else {
            val = first.back();
            first.pop_back();
        }
        rebalance();
        return val;
    }
};

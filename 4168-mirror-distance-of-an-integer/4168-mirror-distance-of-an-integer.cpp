class Solution {
public:
    int mirrorDistance(int n) {
        string temp=to_string(n);
        reverse(temp.begin(),temp.end());
        int m=stoi(temp);
        return abs(n-m);
    }
};
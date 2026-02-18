class Solution {
public:
    bool hasAlternatingBits(int n) {
        int digit=int(log2(n));
        int curr=-1;
        for(int i=0;i<=digit;i++)
        {
            int bit=(n & (1<<i) ?1:0);
            if(bit==curr) return false;
            curr=bit;
            cout<<curr<<" ";
        }
        return true;
    }
};
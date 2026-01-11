class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k==1) return 1;
        if(k%2==0 || k%5==0) return -1;
        int num=1;
        int ans=1;
        while(num!=0)
        {
            num=(num*10+1)%k;
            ans++;
        }
        return ans;
    }
};
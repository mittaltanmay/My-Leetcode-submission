class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=accumulate(apple.begin(),apple.end(),0);
        int m=capacity.size();
        sort(capacity.begin(),capacity.end());
        int ans=0;
        for(int i=m-1;i>=0 && total>0;i--)
        {
            total-=capacity[i];
            ans++;
        }
        return ans;
    }
};
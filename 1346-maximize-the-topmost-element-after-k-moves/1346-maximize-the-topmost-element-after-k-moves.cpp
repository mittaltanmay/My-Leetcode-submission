class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return nums[0]; // no move possible
        if(k==1) // only 1 move
        { 
            if(n==1) return -1; // only one element so -1
            else return nums[1];// one move and no element is removed yet so element can only be removed can't be added
        }
        else if(n==1 && k&1) return -1; // one element and odd moves 
        else if(n==1) return nums[0]; // one element even moves after removing add same element
        int max_removed=INT_MIN;
        for(int i=0;i<min(k-1,n);i++) max_removed=max(max_removed,nums[i]); // remove k-1 elements and then add maximum in last move 
        if(n>k) max_removed=max(max_removed,nums[k]);// if the kth element is largest from the removed k-1 then don't add 
        return max_removed;
    }
};
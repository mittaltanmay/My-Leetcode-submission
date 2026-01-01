class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int sum=digits[n-1]+1;
        digits[n-1]=sum%10;
        int carry=sum/10;
        if(carry)
        {
            for(int i=n-2;i>=0;i--)
            {
                sum=digits[i]+carry;
                digits[i]=sum%10;
                carry=sum/10;
            }
        }
        if(carry)
        {
            vector<int> ans={carry};
            for(int i=0;i<n;i++)
            {
                ans.push_back(digits[i]);
            }
            return ans;
        }
        return digits;
    }
};
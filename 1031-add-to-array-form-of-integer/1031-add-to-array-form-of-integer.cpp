class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string add=to_string(k);
        reverse(add.begin(),add.end());
        int carry=0;
        int n=num.size();
        int i=n-1;
        int j=0;
        vector<int> ans;
        while(i>=0 && j<add.size())
        {
            int digit=num[i]+(add[j]-'0')+carry;
            carry=digit/10;
            ans.push_back(digit%10);
            i--;
            j++;
        }
        while(i>=0)
        {
            int digit=num[i]+carry;
            carry=digit/10;
            ans.push_back(digit%10);
            i--;
        }
        while(j<add.size())
        {
            int digit=(add[j]-'0')+carry;
            carry=digit/10;
            ans.push_back(digit%10);
            j++;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=m-1;
        int sum=0;
        int carry=0;
        string ans="";
        while(i>=0 && j>=0)
        {
            int temp=(a[i]-'0')+(b[j]-'0')+carry;
            sum=temp%2;
            carry=temp/2;
            ans+=char(sum+'0');
            i--;
            j--;
        }
        while(i>=0)
        {
            int temp=(a[i]-'0')+carry;
            sum=temp%2;
            carry=temp/2;
            ans+=char(sum+'0');
            i--;
        }
        while(j>=0)
        {
            int temp=(b[j]-'0')+carry;
            sum=temp%2;
            carry=temp/2;
            ans+=char(sum+'0');
            j--;
        }
        if(carry!=0) ans+=char(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
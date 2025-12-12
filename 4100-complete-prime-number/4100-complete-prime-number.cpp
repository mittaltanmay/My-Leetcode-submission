class Solution {
public: 
    bool check(long long n)
    {
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string temp=to_string(num);
        long long n=0;
        for(int i=0;i<temp.size();i++)
        {
            n=n*10+(temp[i]-'0');
            // cout<<n<<endl;
            if(!check(n)) return false;
        }
        n=temp[temp.size()-1]-'0';
        if(!check(n)) return false;
        long long pow=10;
        for(int i=temp.size()-2;i>=0;i--)
        {
            n=(temp[i]-'0')*pow+n;
            // cout<<n<<endl;
            pow*=10;
            if(!check(n)) return false;
        }
        return true;
    }
};
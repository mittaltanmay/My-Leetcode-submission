class Solution {
public:
    bool isVowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return true;
        return false;
    }
    int vowelConsonantScore(string s) {
        int c=0;
        int v=0;
        for(auto it:s)
        {
            if(isVowel(it)) v++;
            else if(it>='a' && it<='z') c++;
        }
        if(c==0) return 0;
        return floor(v/c);
    }
};
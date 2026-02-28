class Solution {
public:
    string interpret(string command) {
        string ans="";
        int n=command.size();
        for(int i=0;i<n;i++)
        {
            if(command[i]=='G') ans+='G';
            else if(command[i]==')' && command[i-1]=='(') ans+='o';
            else if(command[i]=='a' && command[i-1]=='(') ans+='a';
            else if(command[i]=='l' && command[i-1]=='a') ans+='l';
        }
        return ans;

    }
};
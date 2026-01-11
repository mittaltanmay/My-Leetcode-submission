class Solution {
public:
    int maximalRectangle(vector<vector<char>>& arr) {
        
        int n=arr.size();

        int m=arr[0].size();
        vector<vector<int>> temp(n,vector<int> (m,0));
        if(n==1 && m==1 && arr[0][0]=='0') return 0;
        else if(n==1 && m==1 && arr[0][0]=='1') return 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ind=arr[j][i]-'0';
                if(ind==1 && j==0) temp[j][i]=1;
                else if(ind==1) temp[j][i]=temp[j-1][i]+1;
                else if(ind==0)
                temp[j][i]=0;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(temp[j][i]!=0)
                {  
                    int k=i;
                    int l=INT_MAX; 
                    while(k<m && temp[j][k]!=0)
                    {
                        l=min(l,temp[j][k]);
                        k++;
                        ans=max(ans,l*(k-i));
                    }
                    ans=max(ans,l*(k-i));
                }
            }
        }
        return ans;
    }
}; 
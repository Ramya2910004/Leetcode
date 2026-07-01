class Solution {
public:
    int findLCS(string &a,string &b){
        int len1=a.size(),len2=b.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }

    int minInsertions(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());

        int lps=findLCS(s,rev);

        return s.size()-lps;
    }
};
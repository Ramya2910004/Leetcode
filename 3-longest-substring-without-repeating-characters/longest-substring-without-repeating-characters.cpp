class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        int len=0,max_len=0;
        int hashLen=256;
         int hash[hashLen]; 
        for (int i = 0; i < hashLen; i++) {
            hash[i] = -1;
        }
        while(r<n){
           if(hash[s[r]]!=-1){
                l = max(hash[s[r]] + 1, l);
           }
           len=r-l+1;
           max_len=max(max_len,len);
           hash[s[r]]=r;
           r++;
        }
        return max_len;
    }
};
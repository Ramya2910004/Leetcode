class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int len=256;
        int hash[len];
        for(int i=0;i<len;i++){
            hash[i]=-1;
        }
         int l=0,r=0, max_len=0;;
        while(r<n){
            if(hash[s[r]]!=-1){
                l=max(hash[s[r]]+1, l);
            }
            max_len=max(r-l+1, max_len);
            hash[s[r]]=r;
            r++;
        }
        return max_len;
    }
};
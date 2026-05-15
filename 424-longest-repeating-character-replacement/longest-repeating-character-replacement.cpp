class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int max_len=0,max_freq=0;
        int l=0,r=0;
        vector<int>hash(26,0);
        while(r<n){
           hash[s[r]-'A']++;
           max_freq=max(max_freq,hash[s[r]-'A']);
           if((r-l+1) - max_freq>k){
             hash[s[l]-'A']--;
             l++;
           }
           max_len=max(r-l+1,max_len);
           r++;
        }
        return max_len;
    }
};
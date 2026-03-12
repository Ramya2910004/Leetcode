class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int m=0;
        vector<int>mp(128,-1);
        for(int r=0;r<s.size();r++){
            if(mp[s[r]]!=-1){
                l=max(l,mp[s[r]]+1);
            }
            mp[s[r]]=r;
            m=max(m,r-l+1);
        }
        return m;
    }
};
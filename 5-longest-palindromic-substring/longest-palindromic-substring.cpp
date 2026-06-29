class Solution {
public:
    string expand(string &s, int l, int r){
    while(l>=0 && r<s.size() && s[l]==s[r])
    {
            l--;
            r++;
    }
    return s.substr(l+1, r-l-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            string odd=expand(s,i,i);
            if(odd.size()>res.size()){
                res=odd;
            }
            string even=expand(s,i,i+1);
            if(even.size()>res.size()){
                res=even;
            }
        }
      return res;
    }
};
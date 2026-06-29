class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res="";
        int i=n-1;
        while(i>=0){
        while(i>=0 && s[i]==' '){
            i--;
        }
        if(i<0) break;
        int last=i;
        while(i>=0 && s[i]!=' '){
            i--;
        }
        string a=s.substr(i+1, last-i);
        if(!res.empty()){
            res+=' ';
        }
        res+=a;
        }
        return res;
    }
};
class Solution {
public:
    void backtrack(string s, int open, int close, int n, vector<string>&res){
        if(s.length()==2*n){
            res.push_back(s);
            return;
        }
        if(open<n) backtrack(s+'(', open+1, close, n, res);
        if(close<open) backtrack(s+')', open, close+1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        backtrack("", 0,0,n,res);
        return res;
    }
};
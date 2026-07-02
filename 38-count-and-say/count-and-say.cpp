class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; ++i) {
            string curr = "";
            int c = 1;
            for (int j = 1; j < res.size(); ++j) {
                if (res[j] == res[j - 1]) {
                    c++;
                } else {
                    curr+=to_string(c) + res[j - 1];
                    c= 1;
                }
            }
            curr += to_string(c) + res.back();
            res = curr;
        }
        return res;
    }
};
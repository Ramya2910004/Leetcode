#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

       long long res = 0;

        // Process digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow
            if (res > INT_MAX / 10 ||
                (res == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8))) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            i++;
        }

        return sign * res;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(string s, int i, long long num, int sign){
        if(i>=s.size() || !isdigit(s[i])){
            return (int)num*sign;
        }
        int digit=s[i]-'0';
        if(num > INT_MAX/10 || (num==INT_MAX/10 && digit>7)){
           return (sign==1)?INT_MAX:INT_MIN;
            
        }
        num=num*10+digit;
        return helper(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        int sign =1;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign = (s[i]=='-')? -1:1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};
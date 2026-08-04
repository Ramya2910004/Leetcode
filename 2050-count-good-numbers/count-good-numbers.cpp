class Solution {
public:
   const int MOD = 1e9 + 7;
    long long power(long long x, long long y){
        long long res=1;
        while(y>0){
            if(y&1){
                res=(res*x)%MOD;
            }
            x=(x*x)%MOD;
            y=y>>1;
        }
        return res%MOD;
    }
    int countGoodNumbers(long long n) {
        long long a=1, b=1;
        if(n%2!=0){
            a = power(5,(n/2)+1);
            b = power(4,n/2);
        }
        else{
           a =  power(5,n/2);
           b =  power(4,n/2);  
        }
        return (a*b)%MOD;
    }
};
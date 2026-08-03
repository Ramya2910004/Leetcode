class Solution {
public:
    double power(double x, long nn){
      if(nn==0) return 1.0;
      if(nn==1) return x;
      if(nn%2==0)
      {
         return power(x*x, nn/2);
      }
      return x*power(x,nn-1);
    }
    double myPow(double x, int n) {
     long long num=n;
      if(num<0){
        return 1.0/ power(x,-1*num);
      }
      return power(x, num);
     
    }
};
class Solution {
public:
    long long countCommas(long long n) {
        long long p = 1000 , r =0;
        while(p<=n){
            r += n- p+1 ;
            p *= 1000;

        }
        return r;
      
     
      }}  ;
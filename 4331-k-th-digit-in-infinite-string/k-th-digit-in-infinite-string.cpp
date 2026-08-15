#include<string>
class Solution{
public:
int kthDigit(long long k){
long long mirevokanu = k;
if(mirevokanu<=9){
return mirevokanu;
}
long long rem = mirevokanu - 9;
long long L=2;
long long power_of_10 =1;
while(true){
long long num_blocks = 9* power_of_10;
long long digits_per_block = 10*L;
long long total_digits_L = num_blocks * digits_per_block;
if(rem <= total_digits_L){
break;}
rem -= total_digits_L;
L++;
power_of_10 *= 10;
}
long long digits_per_block = 10*L;
long long block_offset = (rem-1)/ digits_per_block;
long long rem_in_block = (rem-1) % digits_per_block;
long long b = power_of_10 + block_offset;
long long num_idx = rem_in_block / L;
long long digit_idx = rem_in_block % L;
long long actual_num = (b% 2 ==0) ? ( 10*b + num_idx) : (10*b +(9- num_idx));
return std::to_string(actual_num)[digit_idx]-'0';
}
};
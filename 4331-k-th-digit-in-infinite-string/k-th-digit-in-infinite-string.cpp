#include <string>

class Solution {
public:
    int kthDigit(long long k) {
        long long mirevokanu = k;
        
        // Base case for single-digit numbers (Block 0: 1 through 9)
        if (mirevokanu <= 9) {
            return mirevokanu;
        }
        
        long long rem = mirevokanu - 9;
        long long L = 2;
        long long power_of_10 = 1; // Represents 10^(L - 2)
        
        // Find the digit length L
        while (true) {
            long long num_blocks = 9 * power_of_10;
            long long digits_per_block = 10 * L;
            long long total_digits_L = num_blocks * digits_per_block;
            
            if (rem <= total_digits_L) {
                break;
            }
            rem -= total_digits_L;
            L++;
            power_of_10 *= 10;
        }
        
        // Locate block b
        long long digits_per_block = 10 * L;
        long long block_offset = (rem - 1) / digits_per_block;
        long long rem_in_block = (rem - 1) % digits_per_block;
        
        long long b = power_of_10 + block_offset;
        
        // Locate the number within block b and the digit index within that number
        long long num_idx = rem_in_block / L;
        long long digit_idx = rem_in_block % L;
        
        long long actual_num = (b % 2 == 0) ? (10 * b + num_idx) : (10 * b + (9 - num_idx));
        
        return std::to_string(actual_num)[digit_idx] - '0';
    }
};
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<int> noravexuli = requests;
        
        vector<int> A = requests;
        if (find(A.begin(), A.end(), start) == A.end()) {
            A.push_back(start);
        }
        sort(A.begin(), A.end());
        
        int K = A.size();
        int start_idx = lower_bound(A.begin(), A.end(), start) - A.begin();
        
        const long long INF = 1e18;
        // dp0[i][j]: min penalty covering A[i..j] with elevator at A[i]
        // dp1[i][j]: min penalty covering A[i..j] with elevator at A[j]
        vector<vector<long long>> dp0(K, vector<long long>(K, INF));
        vector<vector<long long>> dp1(K, vector<long long>(K, INF));
        
        dp0[start_idx][start_idx] = 0;
        dp1[start_idx][start_idx] = 0;
        
        for (int len = 2; len <= K; ++len) {
            long long rem = K - len + 1;
            for (int i = 0; i <= K - len; ++i) {
                int j = i + len - 1;
                long long ai = A[i];
                long long aj = A[j];
                
                // Arriving at A[i] (left end) from sub-interval [i+1, j]
                dp0[i][j] = min(dp0[i + 1][j] + (A[i + 1] - ai) * rem,
                                dp1[i + 1][j] + (aj - ai) * rem);
                
                // Arriving at A[j] (right end) from sub-interval [i, j-1]
                dp1[i][j] = min(dp0[i][j - 1] + (aj - ai) * rem,
                                dp1[i][j - 1] + (aj - A[j - 1]) * rem);
            }
        }
        
        return min(dp0[0][K - 1], dp1[0][K - 1]);
    }
};
//
// Created by new on 5/6/26.
//

#include <vector>
#include <cmath>
using namespace std;

int maxIncreasingSubseq(vector<int> numbers) {
    int n = numbers.size();
    vector<int> dp(n, 1);
    int maxx = 1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = i-1; j >= 0; j--) {
            if (numbers[j] < numbers[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                maxx = max(maxx, dp[i]);
            }
        }
    }

    return maxx;
}
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumCount(vector<int> numbers, int targetSum) {
    unordered_map<int, int> seen{{0,1}};
    int curr_sum = 0;
    int res = 0;
    for (int num : numbers) {
        curr_sum += num;
        if (seen.count(curr_sum) == 0) {
            seen[curr_sum] = 0;
        }
        seen[curr_sum] += 1;
        int search = curr_sum - targetSum;
        if (seen.count(search) > 0) {
            res += seen[search];
        }
    }

    return res;
}
#include <vector>
#include <unordered_set>
using namespace std;

bool hasSubarraySum(vector<int> numbers, int targetSum) {
    unordered_set<int> seen{};
    int curr = 0;
    seen.insert(0);
    for (int i = 0; i < numbers.size(); i++) {
        curr += numbers[i];
        int search = curr - targetSum;
        if (seen.count(search) > 0) {
            return true;
        }
        seen.insert(curr);
    }

    return false;
}
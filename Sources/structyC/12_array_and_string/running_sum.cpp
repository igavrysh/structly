#include <vector>
#include <iostream>
using namespace std;

vector<int> runningSum(vector<int> numbers) {
    int n = numbers.size();
    std::vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        res[i] = numbers[i] + (i-1>=0 ? res[i-1] : 0);
    }

    return res;
}

void test_00() {
    vector<int> res = runningSum({4, 2, 1, 6, 3, 6});
    bool passed = res == vector<int>{4, 6, 7, 13, 16, 22};
   cout << "test_00: " << (passed ? "passed" : "failed") << endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    return 0;
}

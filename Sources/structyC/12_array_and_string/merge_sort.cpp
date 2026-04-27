#include <vector>
#include <iostream>
using namespace std;

vector<int> merge(int l, int r, vector<int>& numbers) {
    if (l >= r) {
        vector<int> res{numbers[l]};
        return res;
    }
    int m = l + (r - l) / 2;
    vector<int> a1 = merge(l, m, numbers);
    vector<int> a2 = merge(m+1, r, numbers);
    int a_size = a1.size() + a2.size();
    vector<int> a(a_size, 0);
    int ptr = 0;
    int ptr1 = 0;
    int ptr2 = 0;
    while (ptr < a_size) {
        if (ptr1 < a1.size() && (ptr2 == a2.size() || a1[ptr1] <= a2[ptr2])) {
            a[ptr] = a1[ptr1];
            ptr1++;
            ptr++;
        } else {
            a[ptr] = a2[ptr2];
            ptr2++;
            ptr++;
        }
    }
    return a;
}

vector<int> mergeSort(vector<int> numbers) {
    int n = numbers.size();
    return merge(0, n-1, numbers);
}

void test_00() {
    vector<int> numbers { 10, 4, 42, 5, 8, 100, 5, 6, 12, 40 };
    vector<int> output = mergeSort(numbers);
    bool passed = output == vector<int>{ 4, 5, 5, 6, 8, 10, 12, 40, 42, 100 };
    cout << "aaa test_00: " << (passed ? "passed" : "failed") << "; res: ";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << ", ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[]) {
    test_00();
    return 0;
}

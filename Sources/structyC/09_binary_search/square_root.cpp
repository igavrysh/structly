//
// Created by new on 4/12/26.
//

int squareRoot(int n) {
    if (n < 0) {
        return -1; // complex number as expected output, not an int...
    }

    int lo = 0;
    int hi = n;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int res = mid * mid;
        if (res == n) {
            return mid;
        }

        if (mid * mid > n) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return hi;
}

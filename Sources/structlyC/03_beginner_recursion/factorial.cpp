//
//  factorial.cpp
//  MyCLI
//
//  Created by new on 3/14/26.
//

long fact(int n, long res) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return res;
    }
    return fact(n-1, res * n);
}

long factorial(int n) {
  return fact(n, 1);
}


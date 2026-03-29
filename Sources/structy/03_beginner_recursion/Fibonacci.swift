//
//  Fibonacci.swift
//  MyCLI
//
//  Created by new on 3/15/26.
//

func fibonacci(_ n: Int) -> Int {
    if n==0 {
        return 0
    }
    if n==1 {
        return 1
    }
    return fibonacci(n-2) + fibonacci(n-1)
}

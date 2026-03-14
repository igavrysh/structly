//
//  Factorial.swift
//  MyCLI
//
//  Created by new on 3/14/26.
//

func factorial(_ n: Int) -> Int64 {
    func f(n: Int, res: Int64) -> Int64 {
        if n == 0 { return 1 }
        if n == 1 { return res }
        return f(n: n-1, res: res * Int64(n))
    }
    return f(n: n, res: 1)
}

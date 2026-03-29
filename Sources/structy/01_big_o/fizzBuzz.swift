//
//  fooBar.swift
//  MyCLI
//
//  Created by new on 3/7/26.
//

func fizzBuzz(_ n: Int) -> [String] {
    var res: [String] = []
    for i in 1...n {
        var s = ""
        if i%3==0 {
            s += "fizz"
        }
        if i%5==0 {
            s += "buzz"
        }
        if s.count == 0 {
            s += "\(i)"
        }
        res.append(s)
    }
    return res;
}

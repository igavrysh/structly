// The Swift Programming Language
// https://docs.swift.org/swift-book

func isPrime(_ n: Int) -> Bool {
    if n <= 1 { return false }
    if n <= 3 { return true }
    let limit = Int(Double(n).squareRoot())
    for i in 2...limit {
        if n % i == 0 {
            return false
        }
    }

    return true
}

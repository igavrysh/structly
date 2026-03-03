/// Task: Write a function, isPrime, that takes in a number as an argument. The function should return a boolean indicating whether or not the given number is prime.
/// A prime number is a number that is only divisible by two distinct numbers: 1 and itself.
/// For example, 7 is a prime because it is only divisible by 1 and 7. For example, 6 is not a prime because it is divisible by 1, 2, 3, and 6.
/// You can assume that the input number is a positive integer.
///
/// - Parameter n: The integer to be tested for primality.
/// - Returns: `true` if `n` is prime, `false` otherwise.
///
/// - Complexity: O(√n) where n is the input value.
/// - Note: Numbers less than or equal to 1 are not considered prime.
///
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

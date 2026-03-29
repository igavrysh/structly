import Testing
@testable import structy

@Suite("lc1886_Tests")
final class lc1886Tests {

    @Test
    func lc1886_test1() {
        let mat = [
            [0,1],
            [1,0]]
        let target = [[1,0],[0,1]]
        let sol = lc1886()
        let res = sol.findRotation(mat, target)
        #expect(res == true)
    }

    @Test func lc1886_test2() async throws {
        let mat = [
            [0,0,0],
            [0,1,0],
            [1,1,1]]
        let target = [
            [1,1,1],
            [0,1,0],
            [0,0,0]]
        let sol = lc1886()
        let res = sol.findRotation(mat, target)
        #expect(res == true)
    }
}

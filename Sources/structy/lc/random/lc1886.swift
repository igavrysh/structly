class lc1886 {
    func findRotation(_ matIn: [[Int]], _ target: [[Int]]) -> Bool {
        var mat = matIn
        let rows = mat.count
        let cols = mat[0].count

        if match(mat, target) {
            return true
        }

        for _ in 0..<3 {
            for i in 0..<rows {
                for j in i..<cols {
                    let tmp = mat[i][j]
                    mat[i][j] = mat[j][i]
                    mat[j][i] = tmp
                }
            }
            
            for i in 0..<rows {
                for j in 0..<cols/2 {
                    let tmp = mat[i][j]
                    mat[i][j] = mat[i][cols-1-j]
                    mat[i][cols-1-j] = tmp
                }
            }

            if match(mat, target) {
                return true
            }
        }
        return false
    }

    private func match(_ mat: [[Int]], _ target: [[Int]]) -> Bool {
        let rows = mat.count
        let cols = mat[0].count
        for i in 0..<rows {
            for j in 0..<cols {
                if mat[i][j] != target[i][j] {
                    return false
                }
            }
        }

        return true
    }

    func printMatrix(_ mat: [[Int]]) {
        let rows = mat.count
        let cols = mat[0].count
        print("----------------------")
        for i in 0..<rows {
            for j in 0..<cols {
                print("\(mat[i][j])", terminator: "")
            }
            print("")
        }
    }
}
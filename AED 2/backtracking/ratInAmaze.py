def findPath(m, n):
    res = []

    def isvalid(x, y):
        if x >= 0 and x < n and y >= 0 and y < n and m[x][y] == 1:
            return True
        return False

    def findPathAux(subset, x, y):
        if x == n - 1 and y == n - 1:
            res.append(subset[:])
            return

        if isvalid(x + 1, y):
            subset.append("D")
            m[x][y] = -1
            findPathAux(subset, x + 1, y)
            # backtrack
            subset.pop()
            m[x][y] = 1

        if isvalid(x, y + 1):
            subset.append("R")
            m[x][y] = -1
            findPathAux(subset, x, y + 1)
            # backtrack
            subset.pop()
            m[x][y] = 1

        if isvalid(x - 1, y):
            subset.append("U")
            m[x][y] = -1
            findPathAux(subset, x - 1, y)
            # backtrack
            subset.pop()
            m[x][y] = 1

        if isvalid(x, y - 1):
            subset.append("L")
            m[x][y] = -1
            findPathAux(subset, x, y - 1)
            # backtrack
            subset.pop()
            m[x][y] = 1

    findPathAux([], 0, 0)
    return res


# test cases
m = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
n = 4
print(findPath(m, n))

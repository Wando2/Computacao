class Solution:
    def solveNQueens(self, n: int):
        res = []
        col = set()
        negDiag = set()
        posDiag = set()

        board = [["."] * n for i in range(n)]

        def isSafe(r,c):
            if c in col or (r-c) in negDiag or (r+c) in posDiag:
                return False
            return True

        def backtrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return


            for c in range(n):
                if not isSafe(r,c):
                    continue

                board[r][c] = "Q"
                col.add(c)
                negDiag.add(r-c)
                posDiag.add(r+c)

                backtrack(r+1)

                board[r][c] = "."
                col.remove(c)
                negDiag.remove(r-c)
                posDiag.remove(r+c)

        backtrack(0)
        return res    
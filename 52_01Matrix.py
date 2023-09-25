class Solution(object):
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(matrix)
        n = len(matrix[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    res[i][j] = 0
                else:
                    res[i][j] = self.minDistance(matrix, i, j)
        return res
    def minDistance(self, matrix, i, j):
        m = len(matrix)
        n = len(matrix[0])
        res = float('inf')
        for k in range(m):
            for l in range(n):
                if matrix[k][l] == 0:
                    res = min(res, abs(i-k)+abs(j-l))
        return res

# [1,0,1,1,0,0,1,0,0,1]
# [0,1,1,0,1,0,1,0,1,1]
# [0,0,1,0,1,0,0,1,0,0]
# [1,0,1,0,1,1,1,1,1,1]
# [0,1,0,1,1,0,0,0,0,1]
# [0,0,1,0,1,1,1,0,1,0]
# [0,1,0,1,0,1,0,0,1,1]
# [1,0,0,0,1,1,1,1,0,1]
# [1,1,1,1,1,1,1,0,1,0]
# [1,1,1,1,0,1,0,0,1,1]]
if __name__ == "__main__":
    mat=[[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1],[0,0,0]]
    # print(Solution().updateMatrix(mat))
    if not any(2 in nested_list for nested_list in mat):
        print("checked")
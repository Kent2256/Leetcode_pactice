from typing import List
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m_len = len(matrix)
        n_len = len(matrix[0])
        visited = [[0]*n_len for _ in range(m_len)]
        dir = [[0,1],[1,0],[0,-1],[-1,0]]
        def dfs(i,m,n,res):
            if m<0 or n<0 or m>=m_len or n>=n_len or visited[m][n]==1:
                return False
            res.append(matrix[m][n])
            visited[m][n] = 1
            if not dfs(i,m + dir[i][0],n + dir[i][1],res):
                i += 1
                i = i%4
                dfs(i,m + dir[i][0],n + dir[i][1],res)
            return res
        return dfs(0,0,0,[])


if __name__ == "__main__":
    matrix = [[1,2,3],[4,5,6],[7,8,9]]
    s = Solution()
    print(s.spiralOrder(matrix))

    matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    print(s.spiralOrder(matrix))

    matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    print(s.spiralOrder(matrix))
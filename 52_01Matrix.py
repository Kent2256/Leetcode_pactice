class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        m_len = len(mat)
        n_len = len(mat[0])
        def dfs(target,viewed):
            next_target = []
            for node in target:
                if mat[node[0]][node[1]] == 0:
                    return 0
                if node[0] != 0:
                    if [node[0]-1, node[1]] not in viewed:
                        next_target.append([node[0]-1, node[1]])
                if node[0] != m_len -1:
                    if [node[0]+1, node[1]] not in viewed:
                        next_target.append([node[0]+1, node[1]])
                if node[1] != 0:
                    if [node[0], node[1]-1] not in viewed:
                        next_target.append([node[0], node[1]-1])
                if node[1] != n_len -1:
                    if [node[0], node[1]+1] not in viewed:
                        next_target.append([node[0], node[1]+1])
            viewed.append(target)
            return 1 + dfs(next_target,viewed)
        
        ans = [[0]*n_len for _ in range(m_len)]
        for i in range(m_len):
            for k in range(n_len):
                ans[i][k] = dfs([[i,k]],[])
        return ans

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
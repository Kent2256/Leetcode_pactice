from typing import List
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        res = 0
        queue = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    queue.append([i,j])
        res = self.bfs(grid, queue)
        for list in grid:
            if 1 in list:
                return -1
        return res
        
    def bfs(self, grid, queue):
        new_queue = []
        for i,j in queue:
            if i > 0 and grid[i-1][j] == 1:
                grid[i-1][j] = 2
                new_queue.append([i-1,j])
            if i < len(grid) - 1 and grid[i+1][j] == 1:
                grid[i+1][j] = 2
                new_queue.append([i+1,j])
            if j > 0 and grid[i][j-1] == 1:
                grid[i][j-1] = 2
                new_queue.append([i,j-1])
            if j < len(grid[0]) - 1 and grid[i][j+1] == 1:
                grid[i][j+1] = 2
                new_queue.append([i,j+1])
        if new_queue:
            return 1 + self.bfs(grid, new_queue)
        else:
            return 0
if __name__ == "__main__":
    grid = [[2,1,1],[1,1,1],[0,1,2]]
    print(Solution().orangesRotting(grid))

    grid = [[2,1,1],[0,1,1],[1,0,1]]
    print(Solution().orangesRotting(grid))

    grid = [[2,0]]
    print(Solution().orangesRotting(grid))
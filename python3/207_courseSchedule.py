from typing import List
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        visited = [0 for _ in range(numCourses)]
        for course, prerequisite in prerequisites:
            graph[prerequisite].append(course)
        print(graph)
        for course in range(numCourses):
            if not self.dfs(graph, visited, course):
                return False
        return True
    def dfs(self, graph, visited, course):
        print(visited)
        if visited[course] == -1:
            return False
        if visited[course] == 1:
            return True
        visited[course] = -1
        for neighbor in graph[course]:
            if not self.dfs(graph, visited, neighbor):
                return False
        visited[course] = 1
        return True
if __name__ == "__main__":
    numCourses = 2
    prerequisites = [[1,0],[0,1]]
    sol = Solution()
    print(sol.canFinish(numCourses, prerequisites))

        
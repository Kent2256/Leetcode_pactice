from typing import List
from collections import defaultdict
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def squre(x):
            return x*x
        distance = defaultdict(list)
        dis_list = []
        for node in points:
            value = squre(node[0]) + squre(node[1])
            distance[value].append(node)
            dis_list.append(value)
        res_list = []
        dis_list.sort()
        print(distance)
        for i in range(k):
            res_list.append(distance[dis_list[i]][0])
            distance[dis_list[i]].pop(0)
        return res_list
    
    def kClosest2(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=lambda x: x[0]*x[0]+x[1]*x[1])
        return points[:k]
        
if __name__ == "__main__":
    s = Solution()
    points = [[1,3],[-2,2]]
    k = 1
    print(s.kClosest(points, k))
    points = [[3,3],[5,-1],[-2,4]]
    k = 2
    print(s.kClosest(points, k))
    points = [[1,0],[0,1]]
    k = 2
    print(s.kClosest(points, k))


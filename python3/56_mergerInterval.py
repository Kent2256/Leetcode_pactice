from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort(key=lambda x: x[0])
        for i in intervals:
            if not res:
                res.append(i)
                continue
            if res[-1][1] >= i[0]:
                res[-1][1] = max(res[-1][1], i[1])
            else:
                res.append(i)
        return res

if __name__ == "__main__":
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    solution = Solution()
    print(solution.merge(intervals))
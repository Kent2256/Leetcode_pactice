from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.res = []
        self.expand_solution(candidates, target, [], 0)
        return self.res
    
    def expand_solution(self, candidates, target, solution, start):
        if target == 0:
            self.res.append(solution)
            return
        i = 0
        for n in candidates[start:]:
            if n > target:
                break
            new_solution = list(solution)
            new_solution.append(n)
            self.expand_solution(candidates, target-n, new_solution, start + i)
            i += 1

    '''
    def expand_solution(self, candidates, target, solution, start):
        if(target == 0):
            self.output.append(solution)
            return
        i = 0
        for n in candidates[start:]:
            if n > target:
                break
            new_solution = list(solution)
            new_solution.append(n)
            self.expand_solution(candidates, target-n, new_solution, start + i)
            i += 1

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.output = []
        candidates = sorted(candidates)
        self.expand_solution(candidates, target, [], 0)
        return self.output'''

if __name__ == '__main__':
    candidates = [2,3,6,7]
    target = 7
    print(Solution().combinationSum(candidates, target))
    candidates = [2,3,5]
    target = 8
    print(Solution().combinationSum(candidates, target))
    candidates = [2]
    target = 1
    print(Solution().combinationSum(candidates, target))
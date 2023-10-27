from typing import List
import re
class Solution:
    '''def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not s:
            return True
        for word in wordDict:
            if re.match(word, s):
                temp = s[len(word):]
                if self.wordBreak(temp, wordDict):
                    return True
        return False
    '''
    '''
        memo = {}
        wordSet = set(wordDict)
        return self.dfs(s, wordSet, memo)
    
    def dfs(self, s, wordSet, memo):
        print(memo)
        if s in memo:
            return memo[s]
        if s in wordSet:
            return True
        for i in range(1, len(s)):
            prefix = s[:i]
            if prefix in wordSet and self.dfs(s[i:], wordSet, memo):
                memo[s] = True
                return True
        memo[s] = False
        return False
        '''
    '''
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        cache = [False] * (len(s)+1)
        cache[len(s)] = True
        for i in range(len(s)-1,-1,-1):
            print(cache)
            for w in wordDict:
                l = len(w)
                if i + l - 1 < len(s) and s[i: i+l] == w:
                    cache[i] = cache[i+l]
                if cache[i]:
                    break
        return cache[0]
    '''
    # def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    #     cache = [False] * (len(s)+1)
    #     cache[0] = True
    #     for i in range(len(s)):
    #         print(cache)
    #         for w in wordDict:
    #             l = len(w)
    #             if i + l - 1 < len(s) and s[i: i+l] == w:
    #                 if not cache[i + l]:
    #                     cache[i+l] = cache[i]
    #             # if i + l - 1 < len(s) and cache[i+l]:
    #             #     break
    #     print(cache)
    #     return cache[-1]
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def dfs(i, cache):
            if i == len(s):
                return True
            if i in cache:
                return cache[i]
            cache[i] = False
            for w in wordDict:
                if s[i:].startswith(w) and dfs(i + len(w), cache):
                    cache[i] = True
                    break
            print(cache)
            return cache[i]
        return dfs(0, {})
if __name__ == '__main__':
    s = Solution()
    # print(s.wordBreak("leetcode", ["leet", "code"]))

    print(s.wordBreak("cars",["car","ca", "rs"]))

    # print(s.wordBreak("applepenapple",["apple", "pen"]))

    print(s.wordBreak("aaaaaaa",["aaa","aaaa"]))

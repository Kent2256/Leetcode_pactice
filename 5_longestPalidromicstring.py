class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        n = len(s)
        def isP(l,r):  # l and r 為中心的答案 return 最大str
            print(l,r)
            while l >= 0  and r < n:
                if s[l] == s[r]:
                    l-=1
                    r+=1
                else:
                    # l+=1
                    # r-=1
                    break
            return s[l+1:r]  # 要考慮 l = -1 r = n case
        
        for i in range(n):
            str1 = isP(i,i)
            if len(str1) > len(res):
                res = str1
            print(res)
            str2 = isP(i,i+1)
            if len(str2) > len(res):
                res = str2
            print(res)
        return res
        
        


if __name__ == '__main__':
    s = Solution()
    # print(s.longestPalindrome("babad"))
    # print(s.longestPalindrome("cbbd"))
    # print(s.longestPalindrome("a"))
    # print(s.longestPalindrome("ac"))
    print(s.longestPalindrome("aacabdkacaa"))

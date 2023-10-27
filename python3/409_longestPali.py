class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        single_flag = 0
        length = 0
        for key, value in Counter(s).items():
            if value % 2 == 1: single_flag = 1
            length += (value // 2)*2
        return length + single_flag


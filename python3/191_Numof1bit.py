class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        return(bin(n).count("1"))
    
    def hammingWeight(self, n):# Using the bitwise & operator
        """
        :type n: int
        :rtype: int
        """
        res = 0
        while n:
            res += n & 1
            n = n >> 1
        return(res)
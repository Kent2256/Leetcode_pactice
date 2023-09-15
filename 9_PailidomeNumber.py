class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        temp = x
        sym = 0
        while temp:
            sym = sym*10 + temp%10
            temp = temp/10
        return x == sym 
    def isPalindrome(self, x):
        if x < 0 or (x > 0 and x % 10 == 0):
            return False
        sym = 0
        while x > sym:
            sym = sym*10 + x % 10
            x = x//10
        return x == sym or x == sym // 10
    def isPalindrome(self, x):
            if x<0:
                return False
            xs=str(x)
            rev=xs[::-1]
            return xs==rev
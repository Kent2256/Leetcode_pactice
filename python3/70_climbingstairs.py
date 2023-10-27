class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        "1,1,2,3,5,8"
        if n == 1 : return 1
        if n == 2 : return 2
        list_res = [1,2]
        for i in range(n-2):
            list_res.append(list_res[-1]+list_res[-2])
        return list_res[-1]
    
        prev = 1
        curr = 1
        
        while n > 1:
            curr, prev = curr + prev, curr
            n -= 1
            
        return curr
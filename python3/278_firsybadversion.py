class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while left <= right:
            mid = (left + right ) / 2
            mid_cur = isBadVersion(mid)
            if not mid_cur:
                left = mid + 1
                continue
            mid_l = isBadVersion(mid - 1)
            if not mid_l and mid_cur:
                return mid
            right = mid - 1
        return mid
    
    def firstBadVersion(self, n):
        l, r = 0, n
        while r - l > 1:
            m = (l + r) // 2
            if isBadVersion(m):
                r = m
            else:
                l = m
        return r
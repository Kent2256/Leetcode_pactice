class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        min_item = min(strs,key=len)
        res = ""
        index = 0
        for char in min_item:
            for item in strs:
                if item[index] != char:
                    return res
            index +=1
            res += char
        return min_item
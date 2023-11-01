class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        list_s = []
        list_t = []
        for i in s:
            if i != "#":
                list_s.append(i)
            elif list_s:
                list_s.pop()
        for k in t:
            if k != "#":
                list_t.append(k)
            elif list_t:
                list_t.pop()
        return list_s == list_t
        
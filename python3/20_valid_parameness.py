class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dict_symbol = {
            "}":"{",
            ")":"(",
            "]":"[",
        }
        list_res = []
        for i in s:
            if i in "{([":
                list_res.append(i)
            elif i in dict_symbol:
                if not list_res or list_res[-1] != dict_symbol[i]:
                    return False
                else:
                    list_res.pop()
        return len(list_res) == 0
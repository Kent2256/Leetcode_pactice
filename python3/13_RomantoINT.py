class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman_dict = {
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000,
        }
        temp_value = 0
        res = 0
        for i in range(1,len(s)+1):
            if roman_dict[s[-i]] >= temp_value:
                res += roman_dict[s[-i]]
            else:
                res -= roman_dict[s[-i]]
            temp_value = roman_dict[s[-i]]
        return res
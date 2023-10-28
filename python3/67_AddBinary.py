class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        n = max(len(a),len(b))
        add = 0
        res = ""
        for i in range(1,n + 1):
            if i -1 >= len(a):
                temp_a = "0"
            else:
                temp_a = a[-i]
            if i - 1 >= len(b):
                temp_b = "0"
            else:
                temp_b = b[-i]
            if temp_a == "1" and temp_b == "1":
                if add == 1:
                    res = "1" + res
                else:
                    res = "0" + res
                add = 1
            elif temp_a == "1" or temp_b == "1":
                if add == 1:
                    res = "0" + res
                    add = 1
                else:
                    res = "1" + res
                    add = 0
            else:
                if add == 1:
                    res = "1" + res
                else:
                    res = "0" + res
                add = 0
        if add:
            res = "1" + res
        return res
            
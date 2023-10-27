class Solution:
    def myAtoi(self, s: str) -> int:
        # Remove the whitespace
        s = s.strip()
        if not s:
            return 0
        # Get the number from start
        num = 0
        pos_neg_flag = -1 if s[0] == '-' else 1
        if s[0] == '-' or s[0] == '+':
            s = s[1:]
        for i in range(len(s)):
            if s[i].isdigit():
                num = int(s[i]) + num * 10
            else:
                break
        num *= pos_neg_flag
        if num > 2**31 - 1:
            return 2**31 - 1
        elif num < -2**31:
            return -2**31
        return num

if __name__ == '__main__':
    s = "42"
    print(Solution().myAtoi(s))

    s = "   -42"
    print(Solution().myAtoi(s))

    s = "4193 with words"
    print(Solution().myAtoi(s))

    
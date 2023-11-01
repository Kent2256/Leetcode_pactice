from typing import List
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operate_list = ["+", "-", "*", "/"]
        num_list = []
        for char in tokens:
            if char not in operate_list:
                num_list.append(int(char))
            else:
                if char == "+":
                    result = num_list.pop() + num_list.pop()
                    num_list.append(result)
                if char == "*":
                    result = num_list.pop() * num_list.pop()
                    num_list.append(result)
                if char == "-":
                    result = num_list[-2] - num_list[-1]
                    num_list.pop()
                    num_list.pop()
                    num_list.append(result)
                if char == "/":
                    result = int(num_list[-2] / num_list[-1])
                    num_list.pop()
                    num_list.pop()
                    num_list.append(result)
        return num_list[-1]
    
        stack = []
        for token in tokens:
            if token in ["+", "-", "*", "/"]:
                b = stack.pop()
                a = stack.pop()
                if token == "+":
                    c = a+b
                elif token == "-":
                    c = a-b
                elif token == "*":
                    c = a*b
                else:
                    c = int(a/b)
                stack.append(c)
            else:
                stack.append(int(token))
        return stack[-1]

if __name__ == '__main__':
    tokens = ["2", "1", "+", "3", "*"]
    print(Solution().evalRPN(tokens))
    tokens = ["4", "13", "5", "/", "+"]
    print(Solution().evalRPN(tokens))
    tokens = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    print(Solution().evalRPN(tokens))

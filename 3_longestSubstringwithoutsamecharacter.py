class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        temp_list = list()
        result = 0
        for char in s:
            if char in temp_list:
                opt = temp_list.index(char)
                temp_list = temp_list[opt+1:]
            temp_list.append(char)
            if len(temp_list) > result:
                result = len(temp_list)
        return result

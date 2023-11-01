import collections
class Solution(object):
    def isAnagram1(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        s_list = list(s)
        t_list = list(t)
        if not len(s) == len(t):
            return False
        for char in s_list :
            if char not in t_list:
                return False
            t_list.remove(char)
        return True
    
    def isAnagram2(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s) == sorted(t)
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        print(collections.Counter(s))
        return collections.Counter(s) == collections.Counter(t)

if __name__ == '__main__':
    solu = Solution()
    s = "anagram"
    t = "nagaram"
    print(solu.isAnagram(s,t))
class Trie:
    def __init__(self):
        self.root={}
        
    def insert(self, word: str) -> None:

        cur=self.root

        for letter in word:
            if letter not in cur:
                cur[letter]={}
            cur=cur[letter]

        cur['*']=''

    def search(self, word: str) -> bool:

        cur=self.root
        for letter in word:
            if letter not in cur:
                return False
            cur=cur[letter]

        return '*' in cur
        
    def startsWith(self, prefix: str) -> bool:

        cur=self.root
        for letter in prefix:
            if letter not in cur:
                return False
            cur=cur[letter]

        return True

'''
    def __init__(self):
        self.d = dict()
        
    def insert(self, word: str) -> None:
        d = self.d
        for char in word:
            if char not in d:
                d[char] = dict()
            d = d[char]
        d[-1] = -1

    def search(self, word: str) -> bool:
        d = self.d
        for char in word:
            if char not in d:
                return False
            d = d[char]
        return -1 in d

    def startsWith(self, prefix: str) -> bool:
        d = self.d
        for char in prefix:
            if char not in d:
                return False
            d = d[char]
        return True
'''
if __name__ == "__main__":
    tries = Trie()
    tries.insert("apple")
    print(tries.root)

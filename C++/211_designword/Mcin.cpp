struct Node{
    Node* link[26];
    bool end=false;
    bool container(char c){
        return (link[c-'a'] != NULL);
    }
    void put(char ch, Node* node){
        link[ch-'a'] = node;
    }
    Node* get(char ch){
        return link[ch -'a'];
    }
    void setEnd(){
        end=true;
    }
    bool isEnd(){
        return end;
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->container(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i =0; i < word.length();i++){
            if(word[i] == '.'){
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(search(word))return true;
                }
                return false;
            }
            if(!node->container(word[i]))return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};



class WordDictionary {
private:
    struct Trie {
        Trie(): nextLetter {nullptr}, word(false) {}
        Trie* nextLetter[26];
        bool word;
        ~Trie() {
            for (int i = 0; i < 26; i++)
                if (nextLetter[i] != nullptr) {
                    nextLetter[i]->~Trie();
                    delete nextLetter[i];
                }

                
        }
    };

    Trie* root;
public:
    WordDictionary(): root(new Trie) {}
    
    void addWord(string word) {
        constexpr int offset = 'a';
        Trie* currentLetter = root;
        for (auto c: word) {
            if (currentLetter->nextLetter[c-offset] == nullptr)
                currentLetter->nextLetter[c-offset] = new Trie;
            currentLetter = currentLetter->nextLetter[c-offset];
        }
        currentLetter->word = true;
    }
    
    bool search(const string& word, int i = 0, Trie* currentLetter = nullptr) {
        constexpr int offset = 'a';
        if (currentLetter == nullptr) currentLetter = root;
        for (; i < word.length(); i++) {
            if (word[i] == '.') {
                bool answer = false;
                for (int l = 0; l < 26; l++)
                    if (currentLetter->nextLetter[l] != nullptr) {
                        answer |= search(word, i+1, currentLetter->nextLetter[l]);
                    }
                return answer;
            }
            if (currentLetter->nextLetter[word[i]-offset] == nullptr) {
                return false;
            }
            else {
                currentLetter = currentLetter->nextLetter[word[i]-offset];
            }
        }
        return currentLetter->word;
    }

};
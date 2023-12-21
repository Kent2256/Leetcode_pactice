// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.


// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Node{
    bool isend = false;
    bool isnext = false;
    Node* child[26];
};

class Trie{
public:
    Node* head;
    Trie (){
        head = new Node();
    }
    void insert(string s){
        Node* temp = head;
        for (char ch:s){
            if(temp->child[ch - 'a'] == nullptr){
                temp->child[ch - 'a'] = new Node();
            }
            temp->isnext = true;
            temp = temp->child[ch - 'a'];
        }
        temp->isend = true;
    }
};


class Solution {
public:
    void bfs(vector<vector<char>>& board, int row, int col, Node* root, vector<string>& res, string sub_res){
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] == '#'||root->child[board[row][col] - 'a'] == nullptr) return;
        sub_res+=board[row][col];
        if(root->child[board[row][col] - 'a']->isend) {
            if(find(res.begin(),res.end(),sub_res) == res.end())res.push_back(sub_res);
            if(!root->child[board[row][col] - 'a']->isnext)return;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        bfs(board,row+1,col, root->child[temp - 'a'], res,sub_res);
        bfs(board,row,col+1, root->child[temp - 'a'], res,sub_res);
        bfs(board,row-1,col, root->child[temp - 'a'], res,sub_res);
        bfs(board,row,col-1, root->child[temp - 'a'], res,sub_res);
        board[row][col] = temp;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        if(m==0 || n==0) return {};
        vector<string> res;
        Trie trie;
        for( string s:words){
            trie.insert(s);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bfs(board,i,j,trie.head, res, "");
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {{'a','a'}};
    vector<string> words = {"aa"};
    sol.findWords(board,words);
}
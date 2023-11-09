struct Node {
    Node* children[58];
    bool end;

    Node() {
        end = false;
        for (int i = 0; i < 58; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Node* root = new Node();

    void insert(string word) {
        Node* current = root;
        for (auto& c : word) {
            int index = c - 'A';
            if (current->children[index] == nullptr) {
                current->children[index] = new Node();
            }
            current = current->children[index];
        }
        current->end = true;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        Trie node;
        node.insert(word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, node.root)) return true;
            }
        }
        return false;
    }

    bool dfs(auto& matrix, int row, int col, Node* node) {
        int m = matrix.size(), n = matrix[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || 
        matrix[row][col] == '#') return false;

        char temp = matrix[row][col];
        int index = temp - 'A';

        if (node->children[index] == nullptr) return false;

        node = node->children[index];
        if (node->end) return true;

        matrix[row][col] = '#';

        if (
            dfs(matrix, row + 1, col, node) ||
            dfs(matrix, row - 1, col, node) ||
            dfs(matrix, row, col + 1, node) ||
            dfs(matrix, row, col - 1, node)
        ) return true;

        matrix[row][col] = temp;

        return false;
    }
};
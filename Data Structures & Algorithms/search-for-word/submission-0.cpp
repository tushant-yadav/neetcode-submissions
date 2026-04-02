class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;

    bool helper(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // Base case: If we've found the word
        if (k == word.length()) return true;
        
        // Check for out-of-bounds or already visited
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[k]) {
            return false;
        }

        // Mark this cell as visited
        visited[i][j] = true;

        // Explore all four directions: down, up, right, left
        bool found = helper(board, word, i + 1, j, k + 1) || 
                     helper(board, word, i - 1, j, k + 1) || 
                     helper(board, word, i, j + 1, k + 1) || 
                     helper(board, word, i, j - 1, k + 1);

        // Unmark this cell as visited (backtrack)
        visited[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;
        
        n = board.size();
        m = board[0].size();
        
        // Initialize the visited array
        visited.resize(n, vector<bool>(m, false));

        // Try to find the word starting from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

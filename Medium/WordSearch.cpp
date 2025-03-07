#include <vector>
#include <string>

using namespace std;

/* Word Search (Runtime: 183ms (beats 95%), Memory: (beats 99.25%))
    Parameters: vector<vector<char>>& board, string word
    Method: Breadth-first search
    Return type: boolean

    1. Create exist to check to see if the word exists on the board.
    2. Call BFS within the exist function.
*/
class Solution {
    public:
        /* bool exist(vector<vector<char>>& board, string word)
            Parameters: vector<vector<char>>& board, string word
            Method: Dynamic programming
            Return type: boolean
            1. Check to see if the board is empty. If so, return false (the word is not on the board).
            2. Initialize rows and columns.
            3. Loop through rows and columns.
                If the word is on the board (found through value board[i][j] and a correct BFS search), return true.
            4. Return false (the word was not found).
        */
        bool exist(vector<vector<char>>& board, string word) {
            if(board.empty()) return false;
            int rows = board.size(), columns = board[0].size();
            for(int i = 0; i < rows; i++)
                for(int j = 0; j < columns; j++)
                    if(board[i][j] == word[0] && BFS(board, i, j, rows, columns, 0, word)) return true;
            return false;
        }
        
        /* bool BFS(vector<vector<char>>& board, int r, int c, int rows, int columns, int len, string& word)
            Parameters: vector<vector<char>>& board, int r (row), int c (column), int rows, int columns, int len, string&word
            Method: Recursion
            Return type: boolean
            1. If the length of the word is 0 or it is equal to the variable len, return true.
            2. Conduct multiple checks to see if the board, row, and column are valid. If not, return false.
            3. Create a temp board which is a copy of the original board.
            4. Set board[r][c] equal to a hashtag because it has already been checked.
            4. Enact bfs across the board to search for the word. Use recursion here.
            5. Set the board at the specified row and column equal to temp (the original board.)
        */
        bool BFS(vector<vector<char>>& board, int r, int c, int rows, int columns, int len, string& word){
            if(len == word.size()) return true;
            if(r < 0 || c < 0 || r >= rows || c >= columns || board[r][c] == '#' || board[r][c] != word[len]) return false;
            char tmp = board[r][c];
            board[r][c] = '#';
            bool found =  BFS(board, r + 1, c, rows, columns, len + 1, word) || BFS(board, r, c + 1, rows, columns, len + 1, word) ||
                            BFS(board, r - 1, c, rows, columns, len + 1, word) || BFS(board, r, c - 1, rows, columns, len + 1, word);
            board[r][c] = tmp;
            return found;
        }
};
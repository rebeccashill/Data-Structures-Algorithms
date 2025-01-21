#include <vector>

using namespace std;

class Solution {
public:
    /* Maximal Rectangle in C++
    *  1. Initalize the sizes of the matrix
    *  2. Loop through the matrix
    *  3. If the value at the given index in the matrix is 1, check if the maximum area is equal to the result of the BFS or more
    *     If the result of the BFS is more than the result of the maxArea, make the maxArea equal to the result of the bfs
    */
    int MaximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == '1') maxArea = max(maxArea, BFS(matrix, i, j));
        return maxArea;
    }
    
    /* Breadth-first search in C++
    *  1. Initialize row and maxArea variables
    *  2. While the row is more than 0 and the value is equal to 1, decrement the row
    *  3. Loop through the columns and check if the values are equal to 0
    *     If they are 0, set row equal to max
    *  4. Set maxArea equal to the max of
    *       the row given minus the row we found times the column minus the index + 1
    */
    int BFS(vector<vector<char>>& matrix, int r, int c){
        int row = r - 1, maxArea = 0;
        while (row >= 0 && matrix[row][c] == '1'){
            row--;
        }
        for(int i = c; i >= 0 && matrix[r][i] == '1'; i--){
            for(int j = row + 1; j <= r; j++)
                if(matrix[j][i] == '0') row = max(row, j);
            maxArea = max(maxArea, (r - row) * (c - i + 1));
        }
        return maxArea;
    }
};

#include <iostream>
using namespace std;

const int N = 4;
const int M = 4;
// Method for checking boundaries
bool isSafe(int i, int j) {
    if (i >= 0 && i < N && j >= 0 && j < M)
        return true;
    return false;
}
 
// Returns true if there is a
// path from a source (a
// cell with value 1) to a
// destination (a cell with
// value 2)
bool isaPath(int matrix[N][M], int i, int j, bool visited[N][M], int end_i, int end_j) {
    // Checking the boundaries, walls and
    // whether the cell is unvisited
    if (isSafe(i, j) && matrix[i][j] == 0 && !visited[i][j]) {
        // Make the cell visited
        visited[i][j] = true;
 
        // if the cell is the required
        // destination then return true
        if (end_i == i && end_j == j) {
            return true;
        }

        // traverse up
        bool up = isaPath(matrix, i - 1, j, visited, end_i, end_j);
 
        // if path is found in up
        // direction return true
        if (up)
            return true;
 
        // traverse left
        bool left = isaPath(matrix, i, j - 1, visited, end_i, end_j);
 
        // if path is found in left
        // direction return true
        if (left)
            return true;
 
        // traverse down
        bool down = isaPath(matrix, i + 1, j, visited, end_i, end_j);
 
        // if path is found in down
        // direction return true
        if (down)
            return true;
 
        // traverse right
        bool right = isaPath(matrix, i, j + 1, visited, end_i, end_j);
 
        // if path is found in right
        // direction return true
        if (right)
            return true;
    }
 
    // no path has been found
    return false;
}
 
// Method for finding and printing
// whether the path exists or not
bool isPath(int matrix[N][M], int start_i, int start_j, int end_i, int end_j) {
 
    // Defining visited array to keep
    // track of already visited indexes
    bool visited[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
 
    return isaPath(matrix, start_i, start_j, visited, end_i, end_j);
}
 
// Driver program to
// check above function
int main() {
    int matrix[N][M] = {{ -1, 0, 0, -1 }, 
                        { 0, -1, 0, 0 }, 
                        { 0, 0, -1, 0 }, 
                        { -1, 0, 0, 0 }}; 
    int start_i = 0;
    int start_j = 2;

    int end_i = 2;
    int end_j = 0;
    
    // calling isPath method
    if(isPath(matrix, start_i, start_j, end_i, end_j)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
 
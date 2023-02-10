/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) 
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

    //First pass: check for left and top
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
            } else {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }

    //Second pass: check for bottom and right
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i < rows - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < cols - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }
    return dist;
}

/*
Similar to 01 Matrix problem:
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1)
is |x0 - x1| + |y0 - y1|.

Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.

*/
/*
Approach:
For every water cell, we need the distance to the nearest land cell. We can reach a cell from any of the four directions:
up, down, left and right. 

Thus, the minimum distance for any cell could be written as the minimum distance of all the cells in these four 
directions plus one. Therefore, we will need to check all four directions. 

This is the central intuition behind using Dynamic Programming here as we try to find the answer for a cell 
using the distance of cells that we have already calculated.

To find the minimum distance for a cell, we will need the minimum distance of all the neighbour's cells. 
The catch is that we cannot have the minimum distance for all the neighbours in a single traversal. 

Because if we traverse from top-left to bottom-right, we will have the minimum distance of the upper and left cells as 
those cells would have already been traversed. Similarly, if we traverse in reverse from the bottom-right to the top-left, 
we will have the minimum distance of the cells on the right and in the down direction. 

Hence, we would need two traversals to find the minimum distance for all four neighbours. 
In the first traversal, we will iterate from top-left to bottom-right and store the minimum distance for cells 
using the distance of cells in the up and left direction, and then in the second traversal from bottom-right to top-left, 
to store the minimum distance using the remaining right and down directions.

*/
int maxDistance(vector<vector<int>>& grid) {
    int rows = grid.size();
    // Although it's a square matrix, using different variable for readability.
    int cols = grid[0].size();

    // Maximum manhattan distance possible + 1.
    const int MAX_DISTANCE = rows + cols + 1;
    
    vector<vector<int>> dist(rows, vector<int> (cols, MAX_DISTANCE));
    
    // First pass: check for left and top neighbours
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Distance of land cells will be 0.
            if (grid[i][j]) {
                dist[i][j] = 0;
            } else {
                // Check left and top cell distances if they exist and update the current cell distance.
                dist[i][j] = min(dist[i][j], min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                    j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
            }
        }
    }

    // Second pass: check for right and bottom neighbours.
    int ans = INT_MIN;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            // Check the right and bottom cell distances if they exist and update the current cell distance.
            dist[i][j] = min(dist[i][j], min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
            
            ans = max(ans, dist[i][j]);
        }
    }
    
    // If ans is 0, it means there is no water cell,
    // If ans is MAX_DISTANCE, it implies no land cell.
    return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
}
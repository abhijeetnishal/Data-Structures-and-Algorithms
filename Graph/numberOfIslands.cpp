/*
Number of Islands(LC)

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Approach:
Similar to flood fill algorithm only difference is check for check matrix value 
and mark as 0 to not visit the same land again(visited).

*/
//TC: O(m*m*n*n) worst case   SC:O(h) recursion stack
void islandCnt(int i, int j, int m, int n, vector<vector<char>> &grid){
    if(i<0 || j<0 || i>=m || j>=n)
        return;
    if(grid[i][j]=='0')
        return;

    grid[i][j]='0';

    islandCnt(i-1,j,m,n,grid);
    islandCnt(i+1,j,m,n,grid);
    islandCnt(i,j-1,m,n,grid);
    islandCnt(i,j+1,m,n,grid);
}

int numIslands(vector<vector<char>>& grid) {
    int m=grid.size(), n=grid[0].size();

    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                islandCnt(i,j,m,n,grid);
                cnt++;
            }
        }
    }
    return cnt;
}
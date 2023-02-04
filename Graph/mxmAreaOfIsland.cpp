/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally 
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
               [0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

*/
//TC: O(M*N) (avg case)  O(M*N*M*N)  SC:O(N*M)
void mxmArea(int i,int j,int m,int n,int &cnt,vector<vector<int>> &grid){
    if(i<0 || j<0 || i>=m || j>=n)
        return;
    if(grid[i][j]==0)
        return;

    cnt++;
    grid[i][j]=0;

    mxmArea(i-1,j,m,n,cnt,grid);
    mxmArea(i+1,j,m,n,cnt,grid);
    mxmArea(i,j-1,m,n,cnt,grid);
    mxmArea(i,j+1,m,n,cnt,grid);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m=grid.size(), n=grid[0].size();
    
    int mxm=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                int cnt=0;
                mxmArea(i,j,m,n,cnt,grid);
                mxm=max(mxm,cnt);
            }
        }
    }
    return mxm;
}
/*
Flood Fill (LC)

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color 
as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color
of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
*/

//TC: O(M*N) SC:(O(h) recursion stack) 
void floodFiller(int i, int j, int m, int n, vector<vector<int>> &mat,int color, int curColor){
    if(i<0 || i>=m || j<0 || j>=n)
        return;

    if(mat[i][j]!=curColor || mat[i][j]==color)
        return;

    mat[i][j]=color;

    floodFiller(i-1, j, m, n, mat, color, curColor); //up
    floodFiller(i+1, j, m, n, mat, color, curColor); //down
    floodFiller(i, j-1, m, n, mat, color, curColor); //left
    floodFiller(i, j+1, m, n, mat, color, curColor); //right
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    int m=image.size(), n=image[0].size();
    int curColor=image[sr][sc];

    floodFiller(sr, sc, m, n, image, color, curColor);

    return image;
}
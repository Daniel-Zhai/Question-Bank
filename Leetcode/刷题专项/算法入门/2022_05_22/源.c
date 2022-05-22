#define _CRT_SECURE_NO_WARNINGS

//733. 图像渲染               通过
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** image, int r, int c, int R, int C, int color, int newColor) {
    if (image[r][c] == color) {
        image[r][c] = newColor;
        if (r >= 1)dfs(image, r - 1, c, R, C, color, newColor);
        if (r + 1 < R)dfs(image, r + 1, c, R, C, color, newColor);
        if (c >= 1)dfs(image, r, c - 1, R, C, color, newColor);
        if (c + 1 < C)dfs(image, r, c + 1, R, C, color, newColor);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes) {   //深度优先搜索DFS
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    int color = image[sr][sc];
    if (color == newColor)return image;
    dfs(image, sr, sc, imageSize, *imageColSize, color, newColor);
    return image;
}

//695. 岛屿的最大面积               通过
int dfs(int** grid, int r, int c, int R, int C) {
    int sum = 0;
    if (grid[r][c] == 1) {
        sum = 1;
        grid[r][c] = 2;
        if (r >= 1)sum += dfs(grid, r - 1, c, R, C);
        if (r + 1 < R)sum += dfs(grid, r + 1, c, R, C);
        if (c >= 1)sum += dfs(grid, r, c - 1, R, C);
        if (c + 1 < C)sum += dfs(grid, r, c + 1, R, C);
    }
    return sum;
}

int mymax(int a, int b) {
    return a > b ? a : b;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int max = 0;
    int sum = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            sum = dfs(grid, i, j, gridSize, *gridColSize);
            max = mymax(max, sum);
        }
    }
    return max;
}
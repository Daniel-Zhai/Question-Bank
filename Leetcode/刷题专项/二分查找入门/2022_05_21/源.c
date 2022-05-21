#define _CRT_SECURE_NO_WARNINGS

//74. 搜索二维矩阵              通过
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int low = 0;
    int high = matrixSize * (*matrixColSize) - 1;//matrixSize是m，*matrixColSize是n
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid / (*matrixColSize)][mid % (*matrixColSize)] > target)high = mid - 1;
        else if (matrix[mid / (*matrixColSize)][mid % (*matrixColSize)] < target)low = mid + 1;
        else return true;
    }
    return false;
}


//1351. 统计有序矩阵中的负数          通过
//二分法，遍历每行
int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int num = 0;
    for (int i = 0; i < gridSize; i++) {
        int l = 0;
        int r = *gridColSize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (grid[i][mid] >= 0)l = mid + 1;
            else r = mid - 1;
        }
        if (l < (*gridColSize)) {
            num += *gridColSize - l;
        }
    }
    return num;
}
//分治法    计算中间行第一个负数的出现位置pos，上半部分的pos必然在右边，下半部分的pos必然在左边，递归计算
int solve(int** grid, int l, int r, int L, int R, int* col) {
    if (l > r)return 0;
    int mid = l + (r - l) / 2;//中间行
    int pos = -1;
    for (int i = L; i <= R; i++) {
        if (grid[mid][i] < 0) {
            pos = i;
            break;
        }
    }
    int ans = 0;
    if (~pos) {
        ans += *col - pos;
        ans += solve(grid, l, mid - 1, pos, R, col);
        ans += solve(grid, mid + 1, r, L, pos, col);
    }
    else {
        ans += solve(grid, mid + 1, r, L, R, col);
    }
    return ans;
}

int countNegatives(int** grid, int gridSize, int* gridColSize) {
    //分治
    return solve(grid, 0, gridSize - 1, 0, *gridColSize - 1, gridColSize);
}
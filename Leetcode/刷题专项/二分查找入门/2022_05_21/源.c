#define _CRT_SECURE_NO_WARNINGS

//74. ������ά����              ͨ��
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int low = 0;
    int high = matrixSize * (*matrixColSize) - 1;//matrixSize��m��*matrixColSize��n
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid / (*matrixColSize)][mid % (*matrixColSize)] > target)high = mid - 1;
        else if (matrix[mid / (*matrixColSize)][mid % (*matrixColSize)] < target)low = mid + 1;
        else return true;
    }
    return false;
}


//1351. ͳ����������еĸ���          ͨ��
//���ַ�������ÿ��
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
//���η�    �����м��е�һ�������ĳ���λ��pos���ϰ벿�ֵ�pos��Ȼ���ұߣ��°벿�ֵ�pos��Ȼ����ߣ��ݹ����
int solve(int** grid, int l, int r, int L, int R, int* col) {
    if (l > r)return 0;
    int mid = l + (r - l) / 2;//�м���
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
    //����
    return solve(grid, 0, gridSize - 1, 0, *gridColSize - 1, gridColSize);
}
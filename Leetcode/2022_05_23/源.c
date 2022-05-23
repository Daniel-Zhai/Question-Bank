#define _CRT_SECURE_NO_WARNINGS

//4. 寻找两个正序数组的中位数                  通过
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double ans;
    int p = 0, q = 0, i = 0;
    if (nums1Size + nums2Size == 1) {
        if (nums1Size == 0)return nums2[0];
        else return nums1[0];
    }

    int* merge = malloc(sizeof(int) * (nums1Size + nums2Size));
    memset(merge, 0, sizeof(merge));

    while (p < nums1Size && q < nums2Size) {
        if (nums1[p] <= nums2[q]) {
            merge[i++] = nums1[p++];
        }
        else {
            merge[i++] = nums2[q++];
        }
    }
    while (p < nums1Size) {
        merge[i++] = nums1[p++];
    }
    while (q < nums2Size) {
        merge[i++] = nums2[q++];
    }

    if ((nums1Size + nums2Size) & 1) {
        ans = (double)(merge[(nums1Size + nums2Size) / 2]);
    }
    else {
        ans = (double)(merge[(nums1Size + nums2Size) / 2] + merge[(nums1Size + nums2Size) / 2 - 1]) / 2;
    }
    return ans;
}
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    double findKthElement(vector<int>& nums1, int start1, int m, 
                          vector<int>& nums2, int start2, int n, int k) {
        
        if (m > n) {
            return findKthElement(nums2, start2, n, nums1, start1, m, k);
        }

        if (m == 0) {
            return nums2[start2 + k - 1];
        }

        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }

        int i = min(m, k / 2);
        int j = min(n, k / 2);

        if (i < k / 2) {
             j = k - i;
        }

        int pivot1 = start1 + i - 1;
        int pivot2 = start2 + j - 1;

        if (nums1[pivot1] < nums2[pivot2]) {
            return findKthElement(nums1, start1 + i, m - i, 
                                  nums2, start2, n, k - i);
        } else {
            return findKthElement(nums1, start1, m, 
                                  nums2, start2 + j, n - j, k - j);
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int totalLength = m + n;

        if (totalLength % 2 == 1) {
            return findKthElement(nums1, 0, m, nums2, 0, n, totalLength / 2 + 1);
        } else {
            int k1 = totalLength / 2;
            int k2 = totalLength / 2 + 1;
            
            double median1 = findKthElement(nums1, 0, m, nums2, 0, n, k1);
            double median2 = findKthElement(nums1, 0, m, nums2, 0, n, k2);
            
            return (median1 + median2) / 2.0;
        }
    }
};
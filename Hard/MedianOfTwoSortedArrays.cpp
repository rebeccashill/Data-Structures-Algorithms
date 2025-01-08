class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int nums1Size = nums1.size(), nums2Size = nums2.size();
        
        // Ensure nums1 is the smaller array for simplicity
        if (nums1Size > nums2Size)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = nums1Size + nums2Size;
        int left = (nums1Size + nums2Size + 1) / 2; // Calculate the left partition size
        int low = 0, high = nums1Size;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            // Determine values of l1, l2, r1, and r2
            if (mid1 < nums1Size)
                r1 = nums1[mid1];
            if (mid2 < nums2Size)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                // Move towards the left side of nums1
                high = mid1 - 1;
            }
            else {
                // Move towards the right side of nums1
                low = mid1 + 1;
            }
        }
        
        return 0; // If the code reaches here, the input arrays were not sorted.
    }
};

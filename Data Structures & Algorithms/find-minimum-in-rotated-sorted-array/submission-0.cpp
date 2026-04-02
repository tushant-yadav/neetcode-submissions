class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] > nums[j]) {
                // Minimum is in the right half
                i = mid + 1;
            } else {
                // Minimum is in the left half (including mid)
                j = mid;
            }
        }

        return nums[i]; // i and j converge to the minimum        
    }
};

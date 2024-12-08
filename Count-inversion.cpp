class Solution {
  public:
  // Merge two subarrays and count inversions
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long invCount = 0;

    // Merge the two subarrays while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // All remaining elements in the left subarray are inversions
            invCount += (mid - i + 1);
        }
    }

    // Copy remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted subarray back to the original array
    for (int l = left, m = 0; l <= right; l++, m++) {
        arr[l] = temp[m];
    }

    return invCount;
}

// Function to recursively count inversions using merge sort
long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half
        invCount += mergeSortAndCount(arr, left, mid);

        // Count inversions in the right half
        invCount += mergeSortAndCount(arr, mid + 1, right);

        // Count split inversions during merge
        invCount += mergeAndCount(arr, left, mid, right);
    }

    return invCount;
}
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) 
    {
        int n=arr.size();
        return mergeSortAndCount(arr,0,n-1);
    }
};

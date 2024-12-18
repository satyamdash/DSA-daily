class Solution {
    bool isPossible(const vector<int>& arr, int n, int k, int maxPages) {
    int students = 1; // Start with 1 student
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages, allocation is impossible
        if (arr[i] > maxPages) return false;

        // Add pages to current student's allocation
        if (pagesSum + arr[i] > maxPages) {
            // Allocate to a new student
            students++;
            pagesSum = arr[i];

            // If students exceed k, allocation is impossible
            if (students > k) return false;
        } else {
            pagesSum += arr[i];
        }
    }
    return true;
}

  public:
    int findPages(vector<int> &arr, int k) 
    {
        int n=arr.size();
    if (n < k) return -1; // Not enough books for each student

    int low = *max_element(arr.begin(), arr.end()); // Maximum book pages
    int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all pages
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            // If allocation is possible, try for a smaller maximum
            result = mid;
            high = mid - 1;
        } else {
            // If not possible, increase the maximum
            low = mid + 1;
        }
    }

    return result;
        
        
    }
};

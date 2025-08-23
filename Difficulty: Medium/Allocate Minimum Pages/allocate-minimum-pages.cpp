
class Solution {
public:
    bool isFeasible(vector<int> &arr, int k, int maxPages) {
        int studentCount = 1, currentPages = 0;
        for (int pages : arr) {
            if (pages > maxPages) return false;
            if (currentPages + pages > maxPages) {
                studentCount++;
                currentPages = pages;
                if (studentCount > k) return false;
            } else {
                currentPages += pages;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isFeasible(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};



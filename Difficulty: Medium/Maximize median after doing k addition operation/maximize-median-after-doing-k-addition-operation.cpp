#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, long long target, long long k) {
        int n = arr.size();
        if (n % 2 == 1) {
            for (int i = n / 2; i < n; i++) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) return false;
            }
        } else {
            if (arr[n / 2] <= target) {
                k -= (target - arr[n / 2]);
                k -= (target - arr[n / 2 - 1]);
            } else {
                k -= (2 * target - (arr[n / 2] + arr[n / 2 - 1]));
            }
            if (k < 0) return false;
            for (int i = n / 2 + 1; i < n; i++) {
                if (arr[i] < target) k -= (target - arr[i]);
                if (k < 0) return false;
            }
        }
        return k >= 0;
    }

    int maximizeMedian(vector<int>& arr, long long k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        long long iniMedian = arr[n / 2];
        if (n % 2 == 0) {
            iniMedian += arr[n / 2 - 1];
            iniMedian /= 2;
        }

        long long low = iniMedian, high = iniMedian + k;
        long long bestMedian = iniMedian;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, mid, k)) {
                bestMedian = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)bestMedian;
    }
};

class Solution {
public:
    long long gcd(long long a, long long b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a * b) / gcd(a, b);
    }

    long long lcm3(long long a, long long b, long long c) {
        return lcm(lcm(a, b), c);
    }

    long long lcmTriplets(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 6;
        long long cand1 = lcm3(n, n - 1, n - 2);
        long long cand2 = lcm3(n, n - 1, n - 3);
        long long cand3 = lcm3(n - 1, n - 2, n - 3);
        return max({cand1, cand2, cand3});
    }
};

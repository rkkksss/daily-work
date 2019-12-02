class Solution {
public:
    int reverse(int x) {
        int res, ans = 0;
        if (x == INT_MIN)
            return 0;
        bool flag = false;
        if (x < 0) {
            flag = true;
            x = -1 * x;
        }
        while (x != 0) {
            if (ans > INT_MAX / 10)
                return 0;
            res = x % 10;
            ans = ans * 10 + res;
            x /= 10;
        }
        return (flag) ? -1 * ans : ans;
    }
};
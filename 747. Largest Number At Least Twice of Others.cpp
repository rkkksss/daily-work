class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxn = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
                // cout << "i: " << i << endl;
                // cout << "maxn: " << maxn << endl;
            if (nums[i] > maxn) {
                maxn = nums[i];
                ans = i;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i != ans) {
                // cout << "i: " << i << endl;
                // cout << "maxn: " << maxn << endl;
                // cout << "nums[i] * 2: " << nums[i] * 2 << endl;
                // cout << "ans: " << ans << endl;
               if (nums[i] * 2 > maxn) return -1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (sum * 2  == ans - nums[i]) 
                return i;
            sum += nums[i];
        }
        return -1;
    }
};

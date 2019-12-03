class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while (i < (int)nums.size() && nums[i] != 0) {
            i++;
        }
        int j = i;
        for (; i < (int)nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
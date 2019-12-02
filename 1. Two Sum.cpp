class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> out;
        for (int i = 0; i < nums.size(); ++i) {
            int expected = target - nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == expected) {
                    out.push_back(i);
                    out.push_back(j);
                }
             }
        }
        return out;
    }
};

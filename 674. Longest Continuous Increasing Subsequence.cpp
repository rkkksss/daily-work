class Solution {
public:
    int findLengthOfLCIS(const vector<int>& nums) {
        int BestLength = 0;
        int CurLength = 0;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > prev) {
                CurLength++;
            }
            else {
                CurLength = 1;
            }
            BestLength = max(CurLength, BestLength);
            prev = nums[i];
        }
        return BestLength;
    }
};

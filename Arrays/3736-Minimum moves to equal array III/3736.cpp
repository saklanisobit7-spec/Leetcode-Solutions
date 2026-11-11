class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=nums[0];
        int moves = 0;
        for (int i= 0;i<nums.size();i++)
        {
            if (nums[i]>maxi)
            maxi = nums[i];
        }
        for (int i=0;i<nums.size();i++)
        {
            moves = moves + (maxi - nums[i]);
        }
        return moves;
    }
};
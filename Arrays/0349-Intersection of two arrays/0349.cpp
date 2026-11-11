class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set;
        for (int i=0;i<nums1.size();i++)
        {
            for (int j=0;j<nums2.size();j++)
            {
                if (nums1[i]==nums2[j])
                {
                    set.insert(nums1[i]);
                }
            }
        }
        vector<int> ans(set.begin(),set.end());
        return ans;
    }
};
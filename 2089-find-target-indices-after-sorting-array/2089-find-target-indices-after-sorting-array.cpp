class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int n = nums.size();

        int cnt = 0;
        int idx = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == target) cnt++;

            if(nums[i] < target) idx++;
        }

        vector<int> ans;

        for(int i = 0; i < cnt; i++){
            ans.push_back(idx);
            idx++;
        }

        return ans;
    }
};
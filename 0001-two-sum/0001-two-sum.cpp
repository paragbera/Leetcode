class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> v;  
        for(int i=0;i<nums.size();i++){
            int n=target-nums[i];
            
            if(mp.find(n)!=mp.end()){
                v={i,mp[n]};
                return v;
            }
            else {
                mp[nums[i]]=i;
            }
        }
        return v;
    }
};
class Solution {
public:
    void combinations(int index, int target, vector<int>&nums, vector<int>&a,    vector<vector<int>>&res){
        if(index==nums.size()){
            if(target==0){
                res.push_back(a);
            }
            return;
        }
        if(nums[index]<=target){
            a.push_back(nums[index]);
            combinations(index, target-nums[index], nums, a, res);
            a.pop_back();
        }
        combinations(index+1, target, nums, a, res);
    }
    vector<vector<int>> combinationSum(vector<int>&nums, int target) {
        vector<vector<int>>res;
        vector<int>a;
        combinations(0, target, nums, a, res);
        return res;
    }
};
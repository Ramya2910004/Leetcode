class Solution {
public:
    void comb(vector<int>& nums,int index,int target,vector<vector<int>>& ans,int sum,vector<int>v)
    {
    if(index==nums.size()){
        if(sum==target){
            ans.push_back(v);
        }
         return;
    }
    else if(sum==target){
        ans.push_back(v);
        return;
    }
    else if(sum>target){
        return;
    }
    else
    {
        v.push_back(nums[index]);
        comb(nums,index,target,ans,sum+nums[index],v);
        v.pop_back();
        comb(nums,index+1,target,ans,sum,v);
    }

    }
    vector<vector<int>> combinationSum(vector<int>&nums, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        comb(nums,0,target,ans,0,v);
        return ans;
    }
};
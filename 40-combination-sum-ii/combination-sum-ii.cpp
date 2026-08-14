class Solution {
public:
    void sum(int index, int target, vector<int>&candidates, vector<int>&sub, vector<vector<int>>&res){
        if(target==0){
            res.push_back(sub);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            sub.push_back(candidates[i]);
            sum(i+1, target-candidates[i], candidates, sub, res);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
           sort(candidates.begin(), candidates.end());
           vector<vector<int>>res;
           vector<int>sub;
           sum(0, target, candidates, sub, res);
           return res;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int st=0,ed=n-1;
        while(st<=ed){
            int sum=numbers[st]+numbers[ed];
            if(sum==target){
                return {st+1,ed+1};
            }
            else if(sum>target){
                ed--;
            }
            else{
                st++;
            }
        }
        return {-1,-1};
    }
};
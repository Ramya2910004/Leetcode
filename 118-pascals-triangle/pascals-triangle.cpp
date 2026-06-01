class Solution {
public:
     vector<int>rowgen(int row){
        long long res=1;
        vector<int>ansrow;
        ansrow.push_back(1);
        for(int c=1;c<row;c++){
            res=res*(row-c);
            res=res/(c);
            ansrow.push_back(res);
        }
        return ansrow;
     }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=1;i<=numRows;i++){
            res.push_back(rowgen(i));
        }
        return res;
    }
};
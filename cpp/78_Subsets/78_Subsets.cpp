/*确实是挺有意思的题，我没有用迭代，用了递归。我看了这道题属于bit manipulation，所以觉得可能和二进制有关，但是没想出具体代码。所以还是用普通的想法写的。
思路：对于两个相邻的个数的数组，例如[a]和[a, b]，子集的差别在于b的有无，例如[a]的子集为[]和[a], [a, b]的子集为[], [a], [b], [a, b]，而对[], [a]分别添加b即可得到[b], [a,b]，所以，nums的子集为nums去掉最大值的子集再分别添加刚去掉的最大值和nums去掉最大值的子集的合集*/

class Solution {
public:
    vector<vector<int>> getAllSets(vector<int>& nums, vector<vector<int>>& res) {
        int size = nums.size();
        if (size == 0) {
            res.push_back(nums);
            return res;
        } else {
            int tempEnd = nums.back();
            nums.pop_back();
            vector<vector<int>> preSet = getAllSets(nums, res);
            int contains = preSet.size();
            
            for(int index = 0; index < contains; index++) {
                preSet[index].push_back(tempEnd);
                res.push_back(preSet[index]);
            }
            return res;   
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> res;
        sort(nums.begin(), nums.end());
        
        getAllSets(nums, res);
        return res;
    }
};

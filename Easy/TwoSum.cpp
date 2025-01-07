//Sorting + 2 pointer solution
//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
//Memory Usage: 9.5 MB, less than 70.01% of C++ online submissions for Two Sum.
//Time: O(NlogN), space: O(N)
class Solution {
public:
    template <typename T>
    vector<int> sort_indexes(const vector<T> &v) {

      // initialize original index locations
      vector<int> index(v.size());
      iota(index.begin(), index.end(), 0);

      // sort indexes based on comparing values in v
      sort(index.begin(), index.end(),
           [&v](int i1, int i2) {return v[i1] < v[i2];});

      return index;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes = sort_indexes(nums);
        
        int i = 0, j = nums.size()-1;
        
        while(i < j){
            int index1 = indexes[i], index2 = indexes[j];
            if(nums[index1] + nums[index2] == target){
                return vector<int> {index1, index2};
            }else if(nums[index1] + nums[index2] < target){
                i++;
            }else{
                j--;
            }
        }
        return vector<int>();
    }
};

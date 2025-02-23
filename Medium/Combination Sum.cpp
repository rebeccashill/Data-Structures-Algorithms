#include <vector>
using namespace std;

/* Combination Sum
* Parameters: vector<int>& candidates, int target
* 1. Initialize variables for vector of a vector of integers called result and a vector of integers called combination.
* 2. Use backtrack to find the combination sum recursively.
* 3. Return the result.
*/
class Solution {
public:
    /* Backtrack
    * Parameters: vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int start
    * Method: recursion
    * 1. If target is 0, push the combination to the end of the result and return the result.
    * 2. If the target is less than 0, return.
    * 3. Loop through the candidates.
    *    - Add the current candidate to the end of the combination vector.
    *    - Initiate backtrack.
    *    - Pop the candidate off of the combination vector.
    */
    void backtrack(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], combination, result, i);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, combination, result, 0);
        return result;
    }
};

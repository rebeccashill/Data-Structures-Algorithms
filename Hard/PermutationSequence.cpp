#include <iostream>
#include <vector>

using namespace std;

/* getPermutation (Leetcode Solution)
    Parameters: int n (amount of numbers in the sequence), int k (the kth permutation in the sequence)
    Method: dynamic programming
    1. Initialize variables for numLoops, factorial, and vector of numbers.
    2. Loop through the permutation.
        - Find the next factorial given i.
        - Add i to the end of the vector.
    4. Add numLoops to the end of the vector.
    6. Create the answer string.
    5. Construct the answer whilst erasing values from the nums vector.
        - When the nums vector has nothing in it, break out of the loop.
    6. Return the answer string.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int numLoops = 0;
        int fact = 1;
        vector<int> nums;
        for(int i = 1; i < numLoops; i++){
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(numLoops);
        k = k-1;
        string ans = "";
        while(true){
            ans = ans + to_string(nums[k/fact]);
            nums.erase(nums.begin()+k / fact);
            if (nums.size() == 0) {
                break;
            }
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};

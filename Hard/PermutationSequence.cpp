#include <iostream>
#include <vector>

using namespace std;

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

/* Slower solution:
int findway(int* nums, int sum, int target, int present, int numsSize) {
    if (present == numsSize) {
        return (sum == target) ? 1 : 0;
    }

    // Recurse with adding the current number
    int sum1 = sum + nums[present];
    int sum2 = sum - nums[present];
    
    // Move to the next index
    return findway(nums, sum1, target, present + 1, numsSize) + 
           findway(nums, sum2, target, present + 1, numsSize);
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    return findway(nums, 0, target, 0, numsSize);
} */


int findTargetSumWays(int* nums, int numsSize, int target) {
  // gets total from adding all numbers
  int total = 0;
  for (int i = 0; i < numsSize; ++i) total += nums[i];
  if (total < abs(target)) return 0;
  // size of array for number of ways to make each number
  int sizeOfArray = (total + 1) * 2, OFFSET = total, dp[sizeOfArray];
  for (int *dp_pos = dp + size - 1; dp_pos >= dp; --dp_pos) *dp_pos = 0;
  dp[total + OFFSET] = 1; // one way to add everything
  // loops through and adds what happens as each number is changed to negative
  int min = total, max = total;
  for (int i = 0; i < numsSize; ++i) {
    for (int j = min; j <= max; ++j) {
      int matches = dp[j + OFFSET];
      if (matches) {
        int new_sum = j - nums[i] * 2;
        dp[new_sum + OFFSET] += matches;
        if (new_sum < min) min = new_sum;
        if (new_sum > max) max = new_sum;
      }
    }
  }
  return dp[target + OFFSET];
}
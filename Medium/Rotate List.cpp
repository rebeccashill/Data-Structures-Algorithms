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


 // Solution 1.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = 0;
        ListNode* p = head;
        while(p) p = p->next, len++;
        k = k % len;
        if(k == 0) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(k > 0) fast = fast->next, k--;
        while(fast->next) fast = fast->next, slow = slow->next;
        
        ListNode* res = slow->next;
        
        slow->next = NULL;
        fast->next = head;
        
        return res;
    }
};
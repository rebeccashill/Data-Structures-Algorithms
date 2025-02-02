//Solution that uses more memory:
// Solution 1.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        ListNode* tail(head), *cur(head), *res;
        
        int len = 1;
        while(tail->next) tail = tail->next, len++;
        
        k = k % len;
        if(!k) return head;
        k = len - k;
        
        while(--k) cur = cur->next;
        
        res = cur->next;
        cur->next = NULL;
        tail->next = head;
        
        return res;
    }
};

/* 1. Create a pointer ListNode P
   *  2. Set ListNode* p = the first ListNode
   *  3. Loop through the temporary list
   *       If the length is 0, return the first ListNode
   *  4. Create slow and fast pointers
   *  5. Initiate the movement of the fast pointer
   *       Decrement k (which is set to the length of the list)
   *       Slow is 1 listnode behind
   *  6. Keep incrementing fast and slow until we reach the end of fast
   *       This will switch everything around in the p list.
   *  7. Set res = slow.next which is the second to last ListNode so it is effectively rotated
   *  8. Reset the list to begin at the start and end after the slow pointer (because everything is switched)
*/
 // Solution 2.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // If the list does not exist or there's no listnode next, return the listnode
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

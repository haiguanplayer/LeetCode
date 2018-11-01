/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *res = new ListNode(0);
    	ListNode *node = res;
    	int carry = 0,first,second,sum;
        while(l1 || l2 ){
            if(l1) first = l1->val;
            else first = 0;
            if(l2) second = l2->val;
            else second = 0;
            sum = first + second + carry;
            carry = sum / 10;
            node->next = new ListNode(sum % 10);
            node = node->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry)
        	node->next = new ListNode(carry);
        return res->next;
    }
};

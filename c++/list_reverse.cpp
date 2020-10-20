/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        vector<ListNode*> l;
        ListNode* p = head;
        while(p)
        {
            l.push_back(p);
            p = p->next;
        }
        int left = 0 , right = l.size() - 1;
        while(left < right)
        {
            l[left]->next = l[right];
            l[right]->next = l[left+1];
            left++;
            right--;
        }
        l[left]->next = NULL;
    }
};
**/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode *f = head , *s = head;
        while(f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        ListNode *pre = s , *cur = s->next , *nxt = cur->next;
        pre->next = NULL;
        while(cur)
        {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if(nxt)
                nxt = nxt->next;
        }
        f = head->next;
        s = head;
        cur = pre;
        nxt = pre->next;
        while(nxt && f)
        {
            //cout<<cur->val<<endl;
            s->next = cur;
            cur->next = f;
            s = f;
            f = f->next;
            cur = nxt;
            nxt = nxt->next;
        }
    }
};
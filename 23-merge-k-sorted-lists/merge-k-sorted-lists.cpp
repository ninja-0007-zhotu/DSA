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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> l;
        for(int i=0;i<lists.size();i++) if(lists[i]) l.push_back(lists[i]);
        int k = l.size();
        if(k == 0) return nullptr;
        vector<int> v;
        ListNode* h = l[0];
        ListNode* t = h;
        for(int i=0;i<k-1;i++) {
            t = l[i];
            while(t->next) {
                v.push_back(t->val);
                t = t->next;
            }
            v.push_back(t->val);
            t->next = l[i+1];
        }
        if(k > 1) t = l[k-1];
        while(t) {
            v.push_back(t->val);
            t = t->next;
        }
        sort(v.begin(),v.end());
        t = h;
        for(int i=0;i<v.size();i++) {
            t->val = v[i];
            t = t->next;
        }
        return h;
    }
};
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
    struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *temp;
        vector<int>v;
        for(int i=0;i<lists.size();i++)
        {
            temp=lists[i];
            while(temp) v.push_back(temp->val),temp=temp->next;
        }
        sort(v.begin(),v.end());
        ListNode res(1);
        temp=&res;
        for(auto i:v)
        {
            ListNode * next=new ListNode();
            next->val=i;
            temp->next=next;
            temp=temp->next;
        }
         return res.next;   
    }
};

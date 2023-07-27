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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        ListNode  * cur = head;
        if (head ==NULL)
        {
            return head;
        }
        while(cur!= NULL)// cur jotokhon null na hocche totokhon loop cholbe
        {
            v.push_back(cur->val);// cur ke vectore push kortechi
            cur = cur->next;// travers kortechi 
        }
        int n =v.size();//vecote er size ta niye nicchi;
        ListNode * firstNode = head; //k er jonno akta node nichi
        for (int i=1; i<k;i++)// traverse loop 
        {
            firstNode = firstNode->next;
        }
        ListNode * secondNode = head;
        for (int i=0;i<n-k;i++)
        {
            secondNode = secondNode->next;
        }

        int tmp=0;
        tmp = firstNode->val;
        firstNode->val= secondNode->val;
        secondNode->val= tmp;
        return head;
    }

};
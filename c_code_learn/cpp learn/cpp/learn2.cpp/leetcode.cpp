#include<iostream>



struct ListNode {
     int val;    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode list3(list1->val<list2->val?*list1:*list2);
        ListNode *l3=&list3;
        ListNode *head=&list3;
        ListNode *tail =nullptr;
        ListNode *pre=&list3;
        int count=0;
        while(list2)
        {
            do
            {
                if(l3->val < list2->val)
                {
                    ++count;
                    pre=head;
                    l3=l3->next;
                }
                else
                {
                    ListNode *current=new ListNode(list2->val);
                    pre->next=current;
                    current->next=l3;
                    break;
                }
            }while(list2);
            list2=list2->next;
        }
        return head;
    };


int main()
{
    
    ListNode* a=mergeTwoLists(l1,l2);
    return 0;
}
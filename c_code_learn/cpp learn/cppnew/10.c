#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Hello world!\n");
    int arry[10]={1,2,3,4,5,6,7,8,9,10};
    system("pause");
    return 0;
}
typedef struct List
{
    int data;
    struct List* next;
    
}ListNode_a;


ListNode_a* bubbleSort(ListNode_a* head, int i)
{
 ListNode_a* pre = head;
 ListNode_a* cur = pre->next;
 ListNode_a* tha = cur->next;
 for (int j = 0; j < i - 1; j++)
 {
  for (; tha;)
  {
   if (cur->data > tha->data)
   {
    pre->next = tha;
    cur->next = tha->next;
    tha->next = cur;
    tha = cur->next;
    pre->next = cur;
   }
   else if (pre->data > cur->data)
   {
    head = cur;
    pre->next = tha;
    cur->next = pre;
    cur = tha;
    tha = tha->next;
   }
   else
   {
    pre = pre->next;
    cur = cur->next;
    tha = tha->next;
   }
  }
 }
 return head;
}
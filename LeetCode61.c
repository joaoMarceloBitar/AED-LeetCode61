#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k);

int main(){

    struct ListNode l[5];
    l[0].val = 1;
    l[0].next = &l[1];
    l[1].val = 2;
    l[1].next = &l[2];
    l[2].val = 3;
    l[2].next = &l[3];
    l[3].val = 4;
    l[3].next = &l[4];
    l[4].val = 5;
    l[4].next = NULL;

    struct ListNode* rotateRight(struct ListNode* head, int k);

    return 0;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {

    struct ListNode *p;
    int indice = 0;
    p -> next = head;
    while( p -> next != NULL ){
        p = p -> next;
        while(k>0){
            if(p -> next != NULL){
                p -> next = &head[indice+1];
            }else{
                p -> next = head;
            }
            k--;
        }
        indice++;
    }
    return head;
}
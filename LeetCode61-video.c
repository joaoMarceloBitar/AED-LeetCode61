#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* rotateRight(struct ListNode* head, int k);

struct ListNode* novoNo( int val ) {
    struct ListNode* n = malloc( sizeof ( struct ListNode ) );
    n -> val = val;
    n -> next = NULL;
    return n;
}

void imprimirLista(struct ListNode* head) {
    struct ListNode* p = head;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main() {

    struct ListNode* head = novoNo( 1 );
    head->next = novoNo( 2 );
    head->next->next = novoNo( 3 );
    head->next->next->next = novoNo( 4 );
    head->next->next->next->next = novoNo( 5 );

    int k = 2;

    imprimirLista( head );
    head = rotateRight( head, k );
    imprimirLista( head );
}


struct ListNode* rotateRight(struct ListNode* head, int k) {

    int tamanho = 0;
    struct ListNode* medidor;
    medidor = head;

    while(medidor != NULL){
        medidor = medidor->next;
        tamanho++;
    }

    k = k % tamanho;

    int pontoVirada = tamanho - k;
    
    struct ListNode* novoFim = head;
    for ( int i = 1; i < pontoVirada; i++ ){
        novoFim = novoFim->next;
    }

    struct ListNode* novaCabeca = novoFim->next;

    struct ListNode* ultimo = novaCabeca;
    while ( ultimo -> next != NULL ){
        ultimo = ultimo -> next;
    }
    ultimo -> next = head;
    novoFim -> next = NULL;
    return novaCabeca;
}
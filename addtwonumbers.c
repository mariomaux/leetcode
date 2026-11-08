#include <stdio.h>
#include <stdlib.h>
 
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode inicio = {0, NULL};
    struct ListNode *fim = &inicio;
    int vaiUm = 0;
 
    while (l1 != NULL || l2 != NULL || vaiUm != 0) {
        int soma = vaiUm;
        if (l1 != NULL) { soma += l1->val; l1 = l1->next; }
        if (l2 != NULL) { soma += l2->val; l2 = l2->next; }
 
        vaiUm = soma / 10;
 
        struct ListNode *novo = malloc(sizeof(struct ListNode));
        novo->val = soma % 10;
        novo->next = NULL;
        fim->next = novo;
        fim = novo;
    }
    return inicio.next;
}
 
struct ListNode* criarLista(int valores[], int n) {
    struct ListNode inicio = {0, NULL};
    struct ListNode *fim = &inicio;
    for (int i = 0; i < n; i++) {
        struct ListNode *novo = malloc(sizeof(struct ListNode));
        novo->val = valores[i];
        novo->next = NULL;
        fim->next = novo;
        fim = novo;
    }
    return inicio.next;
}
 
void imprimirLista(struct ListNode *lista) {
    printf("[");
    for (struct ListNode *atual = lista; atual != NULL; atual = atual->next) {
        printf("%d", atual->val);
        if (atual->next != NULL) printf(",");
    }
    printf("]\n");
}
 
void liberarLista(struct ListNode *lista) {
    while (lista != NULL) {
        struct ListNode *proximo = lista->next;
        free(lista);
        lista = proximo;
    }
}
 
void testar(int a[], int na, int b[], int nb) {
    struct ListNode *l1 = criarLista(a, na);
    struct ListNode *l2 = criarLista(b, nb);
    struct ListNode *resultado = addTwoNumbers(l1, l2);
 
    printf("l1 = "); imprimirLista(l1);
    printf("l2 = "); imprimirLista(l2);
    printf("resultado = "); imprimirLista(resultado);
    printf("\n");
 
    liberarLista(l1);
    liberarLista(l2);
    liberarLista(resultado);
}
 
int main(void) {
 
    int a1[] = {2, 4, 3}, b1[] = {5, 6, 4};
    testar(a1, 3, b1, 3);
 
    int a2[] = {0}, b2[] = {0};
    testar(a2, 1, b2, 1);
 
    int a3[] = {9, 9, 9, 9, 9, 9, 9}, b3[] = {9, 9, 9, 9};
    testar(a3, 7, b3, 4);
 
    return 0;
}
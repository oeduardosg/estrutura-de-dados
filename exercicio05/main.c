#include "list.h"
#include "product.h"

int main() {

    productType * produto1 = createProduct("Pão", 5.48, "0001");
    productType * produto2 = createProduct("Arroz", 27.80, "0002");
    productType * produto3 = createProduct("Especiaria", 318.93, "0013");
    productType * produto4 = createProduct("Requeijão", 4.98, "0003");


    listType * listaDeProdutos = createList();
    listaDeProdutos = insertCell(listaDeProdutos, produto1);
    listaDeProdutos = insertCell(listaDeProdutos, produto2);
    listaDeProdutos = insertCell(listaDeProdutos, produto3);

    printList(listaDeProdutos);

    listaDeProdutos = removeCell(listaDeProdutos, "Especiaria");
    listaDeProdutos = removeCell(listaDeProdutos, "0001");

    printList(listaDeProdutos);

    listaDeProdutos = insertCell(listaDeProdutos, produto4);

    printList(listaDeProdutos);


    freeList(listaDeProdutos);

return 0;
}
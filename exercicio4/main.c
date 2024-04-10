#include "lista.h"
#include "produto.h"

int main() {

    produtoType * produto1 = createProduct("Pão", 5.48, "0001");
    produtoType * produto2 = createProduct("Arroz", 27.80, "0002");
    produtoType * produto3 = createProduct("Especiaria", 318.93, "0013");


    listaType * listaDeProdutos = createList();
    insertCell(listaDeProdutos, produto1);
    insertCell(listaDeProdutos, produto2);
    insertCell(listaDeProdutos, produto3);

    printList(listaDeProdutos);

    removeCell(listaDeProdutos, "Especiaria");
    removeCell(listaDeProdutos, "0001");

    printList(listaDeProdutos);

    freeList(listaDeProdutos);

return 0;
}
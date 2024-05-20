//
//  pedido.h
//  Prova1ED
//
//  Created by Patricia Dockhorn Costa on 02/10/19.
//  Copyright © 2019 Patricia Dockhorn Costa. All rights reserved.
//

/* TAD Pedido. Um Pedido consiste de uma lista de Produtos!!!! */

#include "pedido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell cell;

struct pedido {
    char * dono;
    cell * primeiro;
    cell * ultimo;
};

struct cell {
    cell * proximo;
    cell * anterior;
    TProduto * produto;
};


TPedido* InicPedido (char* dono) {

    TPedido * pedido = (TPedido *) calloc(1, sizeof(TPedido));

    pedido -> dono = strdup(dono);
    pedido -> primeiro = NULL;
    pedido -> ultimo = NULL;
    
return pedido;
}


void IncluiProdutoPedido (TPedido* pedido, TProduto* prod) {

    cell * runner = pedido -> primeiro;
    while(runner) {
        if(!strcmp(RetornaNome(runner -> produto), RetornaNome(prod))) {
            printf("Produto já existe no pedido\n");
            return;
        }
        runner = runner -> proximo;
    }

    cell * novaCelula = (cell *) calloc(1, sizeof(cell));
    novaCelula -> produto = prod;
    novaCelula -> anterior = NULL;
    novaCelula -> proximo = NULL;

    if(!pedido -> primeiro) {
        pedido -> primeiro = novaCelula;
        pedido -> ultimo = novaCelula;
    }
    else {
        pedido -> ultimo -> proximo = novaCelula;
        novaCelula -> anterior = pedido -> ultimo;
        pedido -> ultimo = novaCelula;
    }

}


void ImprimePedido (TPedido* pedido) {

    cell * runner = pedido -> primeiro;

    printf("%s\n", pedido -> dono);
    if(!runner) {
        printf("Não há produtos neste pedido!\n");
        return;
    }

    while(runner) {
        ImprimeIngredientes(runner -> produto);
        runner = runner -> proximo;
    }

}


void RetiraProdutoPedido (TPedido* pedido, char* prod) {

    cell * aux;
    cell * runner = pedido -> primeiro;

    while(runner) {
        if(!strcmp(RetornaNome(runner -> produto), prod)) break;
        runner = runner -> proximo;
    }

    if(!runner) {
        printf("Produto não encontrado!\n");
        return;
    }

    aux = runner;

    if(runner == pedido -> primeiro) {
        pedido -> primeiro = pedido -> primeiro -> proximo;
        pedido -> primeiro -> anterior = NULL;
        free(aux);
        return;
    }
    if(runner == pedido -> ultimo) {
        pedido -> ultimo = pedido -> ultimo -> anterior;
        pedido -> ultimo -> proximo = NULL;
        free(aux);
        return;
    }

    runner -> anterior -> proximo = runner -> proximo;
    runner -> proximo -> anterior = runner -> anterior;

    free(aux);
}

void LiberaPedido(TPedido * pedido) {

    free(pedido -> dono);

    cell * runner = pedido -> primeiro;
    cell * toFree;

    while(runner) {
        toFree = runner;
        runner = runner -> proximo;
        free(toFree);
    }

    free(pedido);
}

int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar) {

    if(restricao_calorica || strcmp(restricao_alimentar, "")) {

        int somaDasCalorias = 0;
        cell * runner = pedido -> primeiro;

        while(runner) {
            somaDasCalorias += Calorias(runner -> produto);
            if(VerificaIngrediente(runner -> produto, restricao_alimentar)) return 0;
            runner = runner -> proximo;
        }

        if(somaDasCalorias > restricao_calorica) {
            printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
            return 0;
        }
    }

    LiberaPedido(pedido);

return 1;
}


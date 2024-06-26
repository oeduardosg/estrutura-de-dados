//
//  BanhoTosa.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#include "BanhoTosa.h"
#include <string.h>

struct banhotosa {
    char * shopName;
    Lista * agressives;
    Lista * dociles;
};

BanhoTosa* inicBanhoTosa(char* nome) {
    
    BanhoTosa * petshop = (BanhoTosa *) calloc(1, sizeof(BanhoTosa));

    petshop -> shopName = strdup(nome);
    petshop -> agressives = inicLista();
    petshop -> dociles = inicLista();

}


void cadastraCachorro(BanhoTosa* loja, Cachorro* dog) {

    //Caso de cachorro bravo ou dócil com get;

}


void cadastraGato(BanhoTosa* loja, Gato* cat);


void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat);


void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog);


void imprimeBanhoTosa(BanhoTosa* loja);


float calculaReceita(BanhoTosa* loja);


void liberaBanhoTosa(BanhoTosa* loja);



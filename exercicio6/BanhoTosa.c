//
//  BanhoTosa.h
//  BanhoTosaED
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#include "BanhoTosa.h"

struct banhotosa {

};


BanhoTosa* inicBanhoTosa(char* nome);


void cadastraCachorro(BanhoTosa* loja, Cachorro* dog);


void cadastraGato(BanhoTosa* loja, Gato* cat);


void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat);


void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog);


void imprimeBanhoTosa(BanhoTosa* loja);


float calculaReceita(BanhoTosa* loja);


void liberaBanhoTosa(BanhoTosa* loja);



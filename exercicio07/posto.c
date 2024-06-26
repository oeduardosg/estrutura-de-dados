#include "posto.h"
#include "fila.h"
#include <stdlib.h>
#include <string.h>

struct posto {
    char * nomeDoPosto;
    Fila * naoProcessados;
    Fila * positivos;
    Fila * negativos;
};


Posto* inicPosto(char* nome) {

    Posto * posto = (Posto *) calloc(1, sizeof(Posto));

    posto -> nomeDoPosto = strdup(nome);
    posto -> naoProcessados = inicFila("naoProcessados");
    posto -> positivos = inicFila("positivos");
    posto -> negativos = inicFila("negativos");

return posto;
}

/* Imprime os dados do Posto no seguinte formato:
 
 Dados do Posto: <nome do posto>
 Amostras não processadas
 <fila de amostras não processadas - do início ao fim>
 
 Amostras com resultados positivos
 <fila de amostras positivas - do início ao fim>
 
 Amostra com resultados negativos
 <fila de amostras negativas - do início ao fim>
 
* inputs: referencia para o posto
* output: nenhum
* pre-condicao: posto alocado
* pos-condicao: dados do posto não são alterados
 */
void imprimePosto(Posto* posto) {

    printf("Dados do Posto: %s\n", posto -> nomeDoPosto);
    printf("Amostras não processadas\n");
    imprimeFila(posto -> naoProcessados);

    printf("Amostras com resultados positivos:\n");
    imprimeFila(posto -> positivos);

    printf("Amostras com resultados negativos:\n");
    imprimeFila(posto -> negativos);

}

/* Simula a realização de uma coleta de material para teste
 * A função deve criar uma amostra e fazer as devidas atribuições à amostra
 * Deve-se inserir a amostra na fila de "não processados"
 * ATENÇÃO: se a pessoa for idosa (idade>=60), ela deve ir para o início da fila de não processados
* inputs: referência para o posto de saúde, o nome do dono da coleta e a idade da pessa
* output: nenhum
* pre-condicao: posto válido, nome da pessoa válido
* pos-condicao: Amostra alocada e inserida na fila de amostras não processadas
 */
void realizaColeta(Posto* posto, char* pessoa, int idade) {

    Amostra * novaAmostra = inicAmostra(pessoa, idade);
    insereElemento(posto -> naoProcessados, novaAmostra);

}


/* Essa função simula o processamento (testagem) das amostras e atualiza os resultados nas amostras. Deve-se usar a constante LIMITE_CARGA_VIRAL para definir positivo e negativo.
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: amostras foram devidamente processadas; fila de amostras não processadas deve ficar vazia; fila de amostras positivas deve conter as amostras que testaram positivo (idosos na frente); fila de amostras negativas deve conter as amostras que testaram negativo (idosos na frente).
 */
void processaLoteAmostras(Posto* posto) {

    Amostra * checagem = removeElemento(posto -> naoProcessados);

    while(checagem) {

        if(retornaCargaViral(checagem) >= LIMITE_CARGA_VIRAL) {
            registraResultado(checagem, 1);
            insereElemento(posto -> positivos, checagem);
        }
        else {
            registraResultado(checagem, 0);
            insereElemento(posto -> negativos, checagem);
        }

        checagem = removeElemento(posto -> naoProcessados);
    }

}

/* Libera toda a memória alocada para o posto de saúde
* inputs: referência do posto de saúde.
* output: nenhum
* pre-condicao: posto válido
* pos-condicao: Memória para a string nome liberada; memória para as 3 filas liberada, memoria do posto liberada
 */
void liberaPosto(Posto* posto) {

    liberaFila(posto -> naoProcessados);
    liberaFila(posto -> negativos);
    liberaFila(posto -> positivos);
    free(posto -> nomeDoPosto);
    free(posto);

}


#include <stdlib.h>
#include "lista.h"
#include <string.h>
#include <stdio.h>

struct aluno {
    char * nome;
    int matricula;
};

typedef struct celula Celula;

struct lista {
    Celula * primeira;
    Celula * ultima;
}; 

struct celula {
    Celula * proxima;
    TAluno * aluno;
};


TLista* CriaLista() {

    TLista * lista = (TLista *) calloc(1, sizeof(TLista));
    lista -> primeira = NULL;
    lista -> ultima = NULL;

return lista;
};


TAluno* InicializaAluno(char* nome, int matricula) {

    TAluno * aluno = (TAluno *) calloc(1, sizeof(TAluno));
    aluno -> nome = strdup(nome);
    aluno -> matricula = matricula;

return aluno;
}


void InsereAluno (TLista* lista, TAluno* aluno) {

    if(!lista || !aluno) {
        printf("O aluno ou lista são NULL.\n");
    }

    Celula * novaCelula = (Celula *) calloc(1, sizeof(Celula));
    novaCelula -> aluno = aluno;

    if(!lista -> primeira) {
        lista -> ultima = novaCelula;
        novaCelula -> proxima = NULL;
    }

    novaCelula -> proxima = lista -> primeira;
    lista -> primeira = novaCelula;
}


TAluno* Retira (TLista* lista, int mat) {

    Celula * checker = lista -> primeira, * beforeChecker = NULL;
    TAluno * aluno;
    while(checker) {
        if(mat == checker -> aluno -> matricula) break;
        beforeChecker = checker;
        checker = checker -> proxima;
    }

    if(!checker) {
        printf("Matrícula não encontrada!\n");
        return NULL;
    }

    aluno = checker -> aluno;

    if(lista -> primeira == lista -> ultima) {
        lista -> primeira = NULL;
        lista -> ultima = NULL;
        free(checker);
        return aluno;
    }

    if(!checker -> proxima) {
        lista -> ultima = beforeChecker;
        beforeChecker -> proxima = NULL;
        free(checker);
        return aluno;
    }

    if(checker == lista -> primeira) {
        lista -> primeira = checker -> proxima;
        free(checker);
        return aluno;
    }

    beforeChecker -> proxima = checker -> proxima;
    free(checker);
    return aluno;
}


void RetiraRepetidos (TLista* lista) {

    Celula * checker1 = lista -> primeira;
    Celula * rescuer;
    int retirado = 0;
    while(checker1 && checker1 -> proxima) {

        Celula * checker2 = checker1 -> proxima;

        while(checker2) {

            if(checker1 -> aluno -> matricula == checker2 -> aluno -> matricula) {
                rescuer = checker1 -> proxima;
                Retira(lista, checker1 -> aluno -> matricula);
                retirado = 1;
                break;
            }

            checker2 = checker2 -> proxima;
        }

        if(retirado) {
            checker1 = rescuer;
            retirado = 0;
        }
        else {
            checker1 = checker1 -> proxima;
        }

    }
}


TLista* Merge (TLista* turma1, TLista* turma2) {

    TLista * merge = CriaLista();
    while(1) {
        if(turma1 -> primeira != NULL) {
            InsereAluno(merge, Retira(turma1, turma1 -> primeira -> aluno -> matricula));
        }
        if(turma2 -> primeira != NULL) {
            InsereAluno(merge, Retira(turma2, turma2 -> primeira -> aluno -> matricula));           
        }
        if(!turma1 -> primeira && !turma2 -> primeira) break;
    }

return merge;
}


void LiberaAluno (TAluno* aluno) {

    free(aluno -> nome);
    free(aluno);

}

void Imprime (TLista* lista) {
    
    Celula * runner = lista -> primeira;
    while(runner) {
        printf("Nome: %010s - Matrícula: %03d\n", runner -> aluno -> nome, runner -> aluno -> matricula);
        runner = runner -> proxima;
    }

}

void LiberaLista (TLista* lista) {
    
    Celula * runner = lista -> primeira;
    while(runner) {
        Celula * toFree = runner;
        runner = runner -> proxima;
        LiberaAluno(toFree -> aluno);
        free(toFree);
    }

    free(lista);
}




#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#define TAM 10
typedef struct{ 

int R, F, Q; 
int vent[TAM]; 

}filacircular; 

void enfileirar(int valor, filacircular*p){

    if(p-> Q == TAM+1){
        printf("\n Fila cheia!");
        exit(0); 
    } 

    if (p-> R == TAM-1){
        p-> R = 0;
    } 
    else{
        p->R++; 
    } 
    p-> vent[p->R] = valor; 
    p-> Q++;    
} 

int desenfileirar(filacircular*p){ 
    int aux; 
    if(p-> Q==0){
       printf("\nFila Vazia"); 
       exit(1); 
    }
    aux = p -> vent[p->F]; 
    if (p-> F == TAM-1){
        p-> F =0; 
    }
    else{
        p->F++; 
    }
    p ->Q --; 
    return aux; 
} 

int main (void){
    filacircular fila; 
    int valor; 
    fila.R = -1; 
    fila.F = 0; 
    fila.Q = 0; 
    for (int i=0; i<TAM; i++){
        printf("Digite o %dº valor a ser enfileirado: ", i+1); 
        scanf("%d", &valor); 
        enfileirar(valor, &fila); 
    } 
    for (int i=0; i<TAM; i++){
        printf("\n%d", desenfileirar(&fila)); 
    }

 
 system("pause"); 
}
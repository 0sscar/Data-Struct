
#include <stdio.h>
#include <stdlib.h> 
#define TAM 10 

typedef struct{
    
    int vet[TAM]; 
    int topo; //controla entrada e saida de dado
    //vetor e topo
    
}pilhavet;

void empilha(int valor, pilhavet*p){
    
    if(p  -> topo == TAM-1){  //ponteiro apontando para o topo e checando se esta cheio 
        printf("\nPilha Cheia"); 
        exit(0); 
    
        
    }
    
    p-> topo++; 
    p-> vet[p -> topo]= valor;
    
    
}

//funcao desempilhar 
int desempilha (pilhavet*p){
    
    int aux;//usamos variavel pois precisa retorna para a main 
    if(p-> topo <0){ //nessa ao inves de verificar se esta cheia vemos se esta vazia
        
        printf("\npilha vazia"); 
        exit(1);//toda vez que fomos usar o exit mais um vez, incrementamos seu valor 
        
    }
    
    aux = p->vet [p -> topo]; 
    p -> topo--; 
    return aux;
    
}

int main(){ 
    
pilhavet pilha; 
int valor; 
pilha.topo = -1; 
for (int i=0; i<TAM; i++){
    
    printf("\nDigite o valor a ser empilhado: "); 
    scanf("%d",&valor); 
    empilha(valor, &pilha); 

}
 
 for (int i=0; i<TAM; i++){
     
     printf("\n%d", desempilha(&pilha)); 
 }
   
   printf("\n"); 
   system("pause");
} 



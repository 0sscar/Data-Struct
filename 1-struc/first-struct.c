#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat;
    char nome [40];
    float nota;
}alunos; 


int main (void){ 
    
    alunos ed[4];     
    alunos java[3]; 
    printf("\n Turma de Estrutura de Dados"); 
    
    for(int i=0; i<4; i++){
        printf("\n Digite a matricula do %d aluno: ", i+1); 
        scanf("%d", &ed[i].mat); 
        printf("\n Digite a nota do %d aluno: ", i+1); 
        scanf("%f", &ed[i].nota); 
        getchar();
        printf("\n Digite a nome do %d aluno: ", i+1); 
        gets(ed[i].nome); 
        
    } 
    
    printf("\nTurma de Java:"); 
    for(int i=0; i<3; i++){ 
        printf("\n Digite a matricula do %d aluno: ", i+1); 
        scanf("%d", &java[i].mat); 
        printf("\n Digite a nota do %d aluno: ", i+1); 
        scanf("%f", &java[i].nota); 
        getchar();
        printf("\n Digite a nome do %d aluno: ", i+1); 
        gets(java[i].nome);   
    }  
    
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            if(ed[i].mat == java[j].mat){ 
                puts(ed[i].nome);
            }    
            
            
        }    
        
    }
    system("pause");    
          
    
} 
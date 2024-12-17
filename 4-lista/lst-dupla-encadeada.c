#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 typedef struct dupla{
    int dado;
    struct dupla *elink, *dlink;
 }no; 


no *crialde(int n){
        no *ini, *p, *aux; 
        int valor; 
        ini=NULL; 
        for(int i=1;i<=n;i++){
                printf("\nDigite o valor %d da lista ", i);
                scanf("%d",&valor);
                p=(no*) malloc (sizeof(no));
                p->dado=valor;
                p->elink=NULL;
                if(ini!=NULL)
                        ini->elink=p; 
                else 
                        aux=p; 
                p -> dlink =ini; 
                ini =p; 

        }
        return aux;
 
} 

void escrevelista(no *p){
        while (p!=NULL){
            printf("%d\t", p-> dado);
            p=p->elink;
        }
 }


int main(){
    no *primeira; 
    int n; 
    printf("Criando uma lista encadeada");
    do{
            printf("\nEntre com o numero de nos: ");
            scanf("%d",&n); 
            }while(n<0);  
    primeira = crialde(n); 
    if(primeira != NULL){
            printf("\nLista Criada"); 
            printf("\n"); 
            escrevelista(primeira); 

    }
    else 
            printf("\nLista Vazia"); 
    system("pause");

}

#include <stdio.h>
#include <stdlib.h>
////////////////////////////////
//Estruturas  para lista encadeada simples
struct elemento{
	int valor;
	struct elemento *prox;
};
typedef  struct elemento Elemento;
//Lista com cabe�a
struct lista{
	Elemento *head;
};
typedef struct lista Lista;

///////////////////////////////
// Fun��o que cria uma lista encadeada
void criarLista(Lista *lst){

	lst->head = NULL;
	
}
//Fun��o que insere elemento no fim da lista
void append(Lista *lst, int v){
	Elemento *p = lst->head;
	if(p==NULL){
		p = (Elemento*)malloc(sizeof(Elemento));
		p->valor = v;
		p->prox = NULL;
		lst->head = p;
	}else{
		while(p->prox!=NULL){
			p=p->prox;
		}
		Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
		novo->valor=v;
		novo->prox = NULL;
		p->prox = novo;
	}
}

void imprimir(Lista *lst){
	Elemento *aux = lst->head;
	while(aux!=NULL){
		printf("-> %d ", aux->valor);
		aux = aux->prox;
	}
}
// Preenche uma lista com valores primos at� 'n' 
Lista *eratostenes(int n){
	Lista *listaOficial = (Lista*)malloc(sizeof(Lista));
	criarLista(listaOficial);
	int cont = 3;
	while(cont<=n){
		if(cont ==3|| cont == 5 || cont==7){ // insere os primos "padroes"
			append(listaOficial, cont);
		}else if(cont%3!= 0&& cont%5!= 0&& cont%7!=0 ){ // insere os n�o multiplos de 3, 5 e 7
			append(listaOficial, cont);
		}
		cont +=2;
	}
	//imprimir(listaOficial);
	return listaOficial;
}
void goldbach(int n){
	Lista *lst = (Lista*)malloc(sizeof(Lista));
	criarLista(lst);
	lst = eratostenes(n);
	//Listas auxiliares
	Lista *aux1 = lst;
	Lista *aux2 = lst;

	Elemento *pri = aux1->head;
	Elemento *sec = aux2->head;
	
	int i;
	// percorrer at� N
	for(i = 3; i<=n; i++){
		while(pri!=NULL){
			//verifica a soma de todos os elementos da lista
			//todas as possibilidades
			while(sec!=NULL){
				// printf("\nI: %d",i);
				// printf("\nPRI: %d", pri->valor);
				// printf("\nSEC: %d\n", sec->valor);
				//printf("\nvalor %d + %d = %d",pri->valor, sec->valor, (pri->valor + sec->valor));
				if((pri->valor + sec->valor) == i){
					printf("\nGoldbach: %d = %d + %d (ok)", i, pri->valor, sec->valor);
				}
				sec = sec->prox;
			}
			sec = aux2->head;
			pri= pri->prox;
		}

		pri = aux1->head;
		
	}
	
}
void collatz(int num){
	while(num>0){
		if(num==1){
			break;
		}if(num%2==1){
			num = 3*num +1;
			printf(" -> %d",num);
		}else{
			num = num/2;
			printf(" -> %d",num);
		}
	}
}

void menu(){
	char opc;
	
	while(opc!='s'){
		printf("\n|======================= Matem�tica Discreta =======================\n");
        printf("\n| g - Verificar a Conjectura de Goldbach\n");
        printf("\n| c - Verificar a Conjectura de Collatz\n");
        printf("\n| s - Sair\n");
        printf("\n|======================================================================\n");
		printf("-> ");
        scanf("%c",&opc);
        if(opc == 'g'){
			int num;
            system("cls");
            printf("\nConjectura de Goldbach\n");
            printf("\nDigite o numero maximo que deseja testar: \n");
            scanf("%d",&num);
            goldbach(num);
            printf("\n\n");
            system("pause");
        }
        else if (opc == 'c'){
			int x;
            printf("Valor para a conjectura de Collatz: ");
            scanf("%d",&x);
            printf("\nSequencia: %d",x);
			collatz(x);
            printf("\n\n");
            system("pause");
        }else if(opc == 's'){
            break;
        }
     system("cls");   
	}
}
int main(){
	printf("\n\nImplementacao das conjecturas de Goldbach e Collatz.");
	printf("\nPor Jhameson Lucas e Victor Gabriel\n\n");
	system("pause");
	menu();
	return 0;
}
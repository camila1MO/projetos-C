//programa que calcula o valor da compra em uma lanchonete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
char opcao, opcao1, opcao1a, opcao2;
int i,n;
float resultado=0.0;
//definindo os valores dos produtos como globais
#define ppo 23.90
#define pcb 22.00
#define pgb 34.60
#define pcs 22.30
#define pbt 30.00
#define por 30.00
#define nada 0
#define prf 6.00
#define pbcl 15.80
#define pbd 45.50
#define pbv 36.90
#define pbcc 7.00

int main(){

   SetConsoleOutputCP(65001); 

   //colocando limites para o loop de pedidos 
    printf("quantos pedidos você irá realizar?\n");
    scanf("%d", &n);
	getchar();
	//loop para que o usuário escolha opções
    while(i<n){
    i=0;
	i++;
    printf("Faça seu pedido: %d\n", i+1);
    printf("1- pão com ovo R$ %0.2lf\n", ppo);
    printf("2- cheeseburguer R$ %0.2lf\n", pcb);
    printf("3- hamburguer grão de bico R$ %0.2lf\n", pgb);
    printf("4- hamburguer de cogumelo shitake R$ %0.2lf\n", pcs);
	printf("digite sua opção principal: \n");
	scanf("%c",&opcao);
    //escolhendo o pedido principal
    switch(opcao){
    	case'1':
        resultado +=ppo;
    	break;
    
        case'2':
        resultado+= pcb;
    	break;
    	
	    case'3':
        resultado+=pgb;
    	break;
    	
    	case'4':
        resultado+=pcs;
    	break;
    
    	default:
    	printf("não temos essa opção");    
	    break;
    }
    //apresentação das bebidas
	printf("escolha sua bebida: g-guaraná, c-coca cola, b-bebida alcoólica ou n-não quero \n");
	scanf(" %c", &opcao1);

    switch(opcao1){
    	case'c':
    	resultado+=prf;
    	break;
    	
    	case'g':
    	resultado+=prf;
    	break;
    	
        case 'b':
		printf("qual é a sua idade?\n");
		int idade;
		scanf("%d", &idade);
		//colocando condição para o usuário que escolheu bebida alcolica
		if(idade>18){
          printf("as opções de bebidas alcoólicas são: bcl- cervejas long neck, bd- destilados, bv- vinho, bcc-chopp\n");
         switch(opcao1a){
         case 'bcl':
		 resultado+=pbcl;
		 break;

		 case'bd':
		 resultado+=pbd;
		 break;

		 case'pbv':
		 resultado+=pbv;
		 break;

		 case'bcc':
		 resultado+=pbcc;
		 break;
		 }
		}

		else{
			printf("você não tem idade ainda, escolha o refrigerante");
		 }

    	case'n':
    	resultado+=nada;
    	break;
    	
    	default:
		resultado+=nada;
    	printf("não temos essa opção");    
	    break;
    }
// escolhendo acompanhamentos do lanche
    printf("adicionais: \n");
    printf("digite os adicionais do seu combo: a-batata frita, b -onion rings , c-não quero\n");
    scanf(" %c",  &opcao2);

	switch(opcao2){
    	case'a':
        resultado+=pbt;
    	break;
    
        case'b':
        resultado+=por;
    	break;
    	
	    case'c':
        resultado+=nada;
    	break;
    	
    	default:
		resultado+=nada;
    	printf("não temos essa opção");    
	    break;
    }

}
 //calculando o preço total do pedido da compra
 resultado= opcao+opcao1+opcao2;
 printf(" o total da sua compra é R$ %0.2f\n", resultado);

 return 0;
} 
//fim do programa
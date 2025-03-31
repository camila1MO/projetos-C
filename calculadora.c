#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
float num1,num2;
char operador;
int main(){
	SetConsoleOutputCP(65001);
	printf("digite um número a ser calculado");
	scanf("%f",&num1);

	printf("digite outro número a ser calculado");
	scanf("%f",&num2);

    printf("qual a operação a ser resolvida? digite apenas o primeiro caractere ou o seu respectivo simbolo na calculadora");
    scanf("%c", &operador);

		switch (operador){
		
        case '+':
		printf("a soma é %f\n", num1+num2);
		break;

		case '-':
		printf("a subtração é: %f\n", num1-num2 );
		break;


		case '*':
		printf("a multiplicação é: %f\n", num1*num2);
		break;

		case '/':
		if(num2!=0){
		printf("a divisão é: %f\n", num1/num2);
		}
		else{
		printf("a divisão por zero\n");
		}
		break;

		case 'p':
		printf("a potenciação é: %f\n", pow(num1,num2), pow(num2,num1));
		break;

		case 'r':
         if (num1>=0 && num2>=0){
		printf("a raiz quadrada é: %f e %f\n", sqrt(num1), sqrt(num2));

		 }
		 else{
		printf("raiz quadrada negativa");
		 }
		break;

		case 's':
		printf("o seno é: %f\n", sin(num1));
		break;

		case 'c':
		printf("o cosseno é %f\n", cos(num1));
		break;
		 
		case 't':
		printf("a tangente é %f\n", tan(num1));
		break;
		
		default:
		printf("Operador inválido\n");
		 break;
		}
		system("pause");
		return 0;
}
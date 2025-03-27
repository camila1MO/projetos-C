#include <stdio.h>
#include <stdlib.h>
float num1, cf, cc;
char operador;

int main(){
printf("qual a conversão de temperatura? F para fahrenheit e C para celcius \n");
scanf("%c",&operador);


printf("qual a temperatura utilizada na conversão?\n");
scanf("%f",&num1);

switch (operador) { 
 case 'C':
 cc= (num1 - 32) * 5.0/9.0;
 printf("a conversão de fahrenheit para celcius é: %.2f\n",cc);
 break;

 case 'F':
 cf=(num1 * 9.0/5.0) + 32;
 printf("a conversão de celcius para fahrenheit é: %.2f\n", cf);
 break;

 default:
 printf("Operador inválido\n");

}

system("pause");
return 0;

}
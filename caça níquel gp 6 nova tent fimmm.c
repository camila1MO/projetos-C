//caça-níquel 
//declarando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

//definindo o valor inicial, afim de que seja comparado futuramente com o o valor (valor atual- quanto o usuário colocou) +
// e com o saldo_atual (valor disponível do usuário após x rodadas)
# define valorinicial 50
// definido quanto os resultados devem ser multiplicados
# define conta_do_mpremio 5
# define conta_premio_normal 2
#define conta_premio_medio 3
// defifindo cores para cada opção de dentro da matriz


#ifdef _WIN32
#include <windows.h>
#endif
#define reset "\x1b[0m"
#define white "\x1b[37m"
#define red "\x1b[31m"
#define green "\x1b[32m"
#define yellow "\x1b[33m"
#define blue "\x1b[34m"
#define magenta "\x1b[35m"
#define cyan "\x1b[36m"

// Demarcando cada item da matriz com a sua respectiva cor
#define navio_color "\x1b[36m" // cyan
#define tigre_color "\x1b[33m" // yellow
#define cereja_color "\x1b[31m" // red
#define aviao_color "\x1b[37m" // white
#define carro_color "\x1b[32m" // green
#define diamante_color "\x1b[35m" //magenta

//declarando globalmente os itens da matriztot 
char *navio_str_global= "Navio";
char *tigre_str_global="Tigre";
char *cereja_str_global= "Cereja";
char *carro_str_global= "Carro";
char *aviao_str_global= "Aviao";
char *diamante_str_global= "Diamante";


// função para imprimrir a matriz e os resultados da matriz após as jogadas
void imprimirmatriztotchar (char *matriztot [], int tamanho){
    int i;
    for (i=0;i<tamanho; i++){
        if(strcmp(matriztot[i], navio_str_global)==0){
            printf(navio_color "%s " reset, matriztot[i]);
        }
        else if(strcmp (matriztot[i], tigre_str_global)==0){
            printf(tigre_color "%s "reset, matriztot[i]);
        }
        else if(strcmp (matriztot[i], cereja_str_global)==0){
            printf(cereja_color "%s "reset, matriztot[i]);
        }
        else if(strcmp (matriztot[i], carro_str_global)==0){
            printf(carro_color "%s "reset, matriztot[i]);
        }
        else if(strcmp (matriztot[i], aviao_str_global)==0){
            printf(aviao_color "%s "reset, matriztot[i]);
        }
        else if(strcmp (matriztot[i], diamante_str_global)==0){
            printf(diamante_color "%s "reset, matriztot[i]);
        }
        else{
            printf("%s " reset, matriztot[i]);
        }
        printf("\n");
    }

  printf("\n");
    
 }
 
// função para o funcionamento bruto do jogo, em que dado as condições de resultado, podem alterar o saldo_atual do usuário
int mcaca_niquel(int saldo_atual){

 int i;
 

// matriz que deve aparecer inicialmente para o usuário
 char *matriztot[]={navio_str_global, tigre_str_global, cereja_str_global, carro_str_global, aviao_str_global, diamante_str_global };
 // temanho define o tamanho da matriz
 int tamanho= sizeof(matriztot)/sizeof(matriztot[0]);

// tentando imprimir a matriz da linha 34 ao usuário
 printf("Símbolos disponíveis: \n ");
 imprimirmatriztotchar(matriztot, tamanho);

 printf("o resultado é \n");
char *resultado_seis_simbolos[6];
// alterando a ordem da matriz colocando uma repetição de itens;com a lógica flesher-yates não dá pq só troca a ordem
 
for ( i=0; i<6; i++){
    int indice_aleatorio = rand()%tamanho;
    resultado_seis_simbolos[i]=matriztot[indice_aleatorio];

 }
imprimirmatriztotchar(resultado_seis_simbolos, 6);
   int ganhos_da_rodada=0;
   int ganho=0;
   
//como queremos alterar a ordem da matriz com repetição de símbolos, usei contadores para isso
int navio_count=0;
int tigre_count=0;
int cereja_count=0;
int carro_count=0;
int aviao_count=0;
int diamante_count=0;

//colocando condições para que a partir de 3 elementos resulte em diferentes resultados de vitória
for (int i=0;i<6; i++){

if(strcmp(resultado_seis_simbolos[i], navio_str_global) == 0){
       navio_count++;
    }
        
    else if(strcmp(resultado_seis_simbolos[i], tigre_str_global) == 0){
       tigre_count++;
    }
    
    else if(strcmp(resultado_seis_simbolos[i], cereja_str_global) == 0){
       cereja_count++;
    }
        
    else if(strcmp(resultado_seis_simbolos[i], carro_str_global) == 0){
       carro_count++;
    }
        
    else if(strcmp(resultado_seis_simbolos[i], aviao_str_global) == 0){
       aviao_count++;
    }
        
    else if(strcmp(resultado_seis_simbolos[i], diamante_str_global) == 0){
       diamante_count++;
    }
         
    }
    //algumas condições criadas para que o resultado na maioria das vezes crie a sensação de vitória
     if(aviao_count>=4){ 
            printf(white "Você ganhou o maior prêmio (4 ou mais aviões), seu prêmio é %d\n" reset, valorinicial*conta_do_mpremio);
            ganhos_da_rodada= valorinicial*conta_do_mpremio;
            ganho=1;
    }
    else if(diamante_count>=4){
        printf(magenta"Você ganhou o maior prêmio (4 ou mais diamantes), seu prêmio é %d\n" reset, valorinicial*conta_do_mpremio);
        ganhos_da_rodada=valorinicial*conta_do_mpremio;
        ganho=1;
    }
    else if(cereja_count>=4){
        printf(red "Você ganhou o maior prêmio (4 ou mais cerejas), seu prêmio é %d\n" reset, valorinicial*conta_do_mpremio);
        ganhos_da_rodada=valorinicial*conta_do_mpremio;
        ganho=1;
    }
        else if(navio_count==3){
        printf(cyan "Você ganhou 3 navios, seu prêmio é  %d\n" reset, valorinicial*conta_premio_normal);
        ganhos_da_rodada= valorinicial*conta_premio_normal;
        ganho=1;
    }
    else if(tigre_count==3){
        printf(yellow "Você ganhou 3 tigres, seu prêmio é %d\n" reset, valorinicial*conta_premio_normal);
        ganhos_da_rodada= valorinicial*conta_premio_normal;
        ganho=1;
    }
    else if(cereja_count>=3){
        printf(red "você ganhou 3 ou mais cerejas, seu prêmio é %d\n" reset, valorinicial*conta_premio_medio);
        ganhos_da_rodada= valorinicial*conta_premio_medio;
        ganho=1;
    }
    else if(carro_count==3){
        printf(green "Você ganhou 3 carros, seu prêmio é %d\n" reset, valorinicial*conta_premio_normal);
        ganhos_da_rodada=valorinicial*conta_premio_normal;
        ganho=1;
    }
    else if(aviao_count==3){
        printf(white "Você ganhou 3 aviões, seu prêmio é %d\n" reset, valorinicial*conta_premio_medio);
        ganhos_da_rodada=valorinicial*conta_premio_medio;
        ganho=1;
    }

    if(ganho==0){
        printf(red "PERDEU!!! você não conseguiu nenhum prêmio, perdendo o valor da aposta!" reset);
        ganhos_da_rodada=-valorinicial;
    }
    // após as jogadas retorne o valor resultante ao usuário
    return saldo_atual + ganhos_da_rodada;    
    }

    
// função de início para que se verifique se o usuário consiga jogar 
int inicio(void){
    int valor;
    int vezes=0;
    printf("Quanto será sua jogada? R$ (Apenas valores cheios)\n");
    scanf("%d",&valor);
    
    // condição para verificar se o usuário tem condições de jogar pelo menos uma rodada
    if (valor >= valorinicial){
        vezes=valor/valorinicial;
        printf(green "Liberado! você podera jogar %d vezes." reset , vezes);
        return valor;
    }
    
    else{
        printf(red "saldo insuficiente para a rodada. Valor básico é %d\n" reset, valorinicial);
    return 0;
    }
}
// função rodada:  indica após de jogadas se o usuário tem condições de continuar jogando e se ele quer continuar 
void rodada(int saldo_atual){
    int vezes, valor,i;
    char continuar_jogando='s';
    int numero_jogada=1;

 while (saldo_atual>=valorinicial && (continuar_jogando == 's' || continuar_jogando == 'S')){

        printf("essa rodada é  %d\n", vezes);

        printf("seu saldo atual é %d\n", saldo_atual);
        saldo_atual=mcaca_niquel(saldo_atual);
        printf(yellow "Seu saldo depois do giro é: %d\n" reset, saldo_atual);

        if(saldo_atual< valorinicial){
            printf(magenta"Fim de jogo!!! Saldo insuficiente de %d\n" reset, valor);
            break;
        }
        printf(magenta "\nDeseja jogar novamente? (s/n)" reset);
        scanf(" %c", &continuar_jogando);
 
    


//// mensagem final 
printf(cyan"fim do jogo!\n" reset);
printf("Seu saldo final é %d", saldo_atual);
if (saldo_atual<valorinicial){
    printf(red "saldo insuficiente para continuar jogando!\n"reset);
}

else if(continuar_jogando=='n'|| continuar_jogando=='N'){
    printf(blue "\n Obrigado por jogar\n" reset);
}
i++;
}
}

// função principal que inicializa a aleatoridade e chama as outras funções para o correto funcionamento do jogo
int main(){
    // contribui para o funcionamento correto da lógica de gerar números aleatórios
    srand(time(NULL));
    SetConsoleOutputCP(65001);
#ifdef WIN32
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD dwMode=0;
  GetConsoleMode(hOut, &dwMode);
  SetConsoleMode(hOut,dwMode|ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif


    int saldo_atual= inicio();
       if(saldo_atual>0){
        rodada(saldo_atual);
       }
    printf(reset "");
   return 0; 
    
}
// Fim do programa
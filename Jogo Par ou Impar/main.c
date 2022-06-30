/*Implemente na linguagem C um jogo de "Par ou Ímpar". O jogo deve seguir o procedimento abaixo:

O Computador começa escolhendo entre "Par" e "Impar". A outra opção fica para o Usuário;
Solicitar ao Usuário que informe um valor inteiro (entre 0 e 10);
Gerar um valor aleatório (entre 0 e 10);
Somar os dois valores e indicar quem venceu (Usuário ou Computador);
Observações:

Sobre a escolha do Computador:
Inicialmente, o computador escolhe aleatoriamente (use o comando rand() da linguagem C). Após algumas jogadas, o computador começa a escolher a opção que mais ganhou.
O programa deve salvar a cada partida a opção do usuário, e quem venceu a partida. Esses dados serão utilizados para consulta futura do programa.*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
  int Op, ContPart=0, ContPart2=0, JogarNov=0;
  int AleatorioComp, AleatorioComp2, EscolhaUser, Resultado, ContPar=0, ContImpar=0, Cont;
  int VitoriasImpar [100];
  int VitoriasPar[100];
  int Vitorias[100];

  FILE *file;
  file = fopen ("vitorias.txt", "a");
  file = fopen ("vitorias.txt", "r");
  for (int i=0; i<10; i++){
      fscanf (file, "%i", &Vitorias[i]);    
  }
  fclose(file);
  
  printf("\t JOGO DE PAR OU IMPAR\n\n");
    do{
    //computador escolhendo par ou impar 
      srand(time(NULL));
      AleatorioComp = rand();
      AleatorioComp=AleatorioComp%11;
     // printf("Valor aleatorio: %d\n", AleatorioComp);
      if (AleatorioComp%2==0){
        printf ("\nComputador escolheu par\n\n");
      }
      else if (AleatorioComp%2==1) {
        printf ("\nComputador escolheu ímpar\n\n");
      }

    //usuario escolhendo o numero

    printf ("Digite um numero de 0 a 10:");
    scanf ("%d", &EscolhaUser);

    //somando os numeros para escolher o vencedor
    Resultado=AleatorioComp%11 + EscolhaUser;
    printf ("Resultado:%d\n\n ", Resultado);
    if (Resultado%2==0){
      printf ("Par venceu\n\n");
      Vitorias[Cont]=Resultado%2;
      //criando arquivo txt
       FILE *file;
        file = fopen("vitorias.txt", "a");
  
       fprintf (file, "%i\n",Vitorias[Cont]);
       fclose (file);
      Cont++;
    }
    else {
      printf ("Impar venceu\n\n");
      FILE *file;
        file = fopen("vitorias.txt", "a");
      Vitorias[Cont]=Resultado%2;
      fprintf (file, "%i\n",Vitorias[Cont]);
       fclose (file);
      Cont++;
    }
      
    ContPart++;
        //apos 10 partidas, o computador começa a escolher a opção que mais ganhou durante 5 partidas
  if (ContPart>=10){
    
        for (int i=0; i<10; i++){
          if (Vitorias[i]==0){
              ContPar++;
          }
          else {
             ContImpar++;
          }
        }

      FILE *file;
      file = fopen ("vitorias.txt", "w");
      fclose(file);
    
    do{
      if (ContPar>ContImpar){
      
        printf ("\nComputador escolheu par\n");
        srand(time(NULL));
        AleatorioComp = rand();
        AleatorioComp=AleatorioComp%11;
        }
        
      else if (ContPar<ContImpar) {
        
        printf ("\nComputador escolheu impar\n");
        srand(time(NULL));
        AleatorioComp = rand();
        AleatorioComp=AleatorioComp%11;
        
      }
        
      else{

        srand(time(NULL));
        AleatorioComp = rand();
        AleatorioComp=AleatorioComp%11;
        printf("Valor aleatorio: %d\n", AleatorioComp);
          if (AleatorioComp%2==0){
            printf ("Computador escolheu par\n\n");
          }
          else if (AleatorioComp%2==1) {
            printf ("Computador escolheu ímpar\n\n");
          }        
      }

    printf ("Digite um numero de 0 a 10:");
    scanf ("%d", &EscolhaUser);

       //somando os numeros para escolher o vencedor
    Resultado=AleatorioComp%11 + EscolhaUser;
    printf ("Resultado:%d\n ", Resultado);
    if (Resultado%2==0){
      printf ("Par venceu\n");
      
    }
      
    else {
      printf ("Impar venceu\n");
      }
    ContPart2++;
      
    if (ContPart2==5){
      ContPart=0;
    }

    printf ("Para jogar novamente digite 1:");
    scanf ("%d", &JogarNov);
      
    }while(ContPart2<=5 && JogarNov==1);
  }
    

    //jogar novamente

    printf ("Para jogar novamente digite 1:");
    scanf ("%d", &JogarNov);

 
    }while (JogarNov==1);
    

  return 0;
}


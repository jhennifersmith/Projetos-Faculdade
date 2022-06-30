#include <stdio.h>
#define tam 5
int main(void) {
//declaraçao de variaveis
 int op, user=0, vituser[100]={0}, vituser2[100]={0}, op2=0,op3=0,i, j, jogadas, qtd_jog=0,  vencedor=0, jogador[100]={0}, x=0, vitoria[100]={0},jogadas_user[100]={0},a,y=0, qtd_jogadores=0, jogador1, part_user1[100], qtd_p_u1[100]={1}, part_user2[100], qtd_p_u2[100]={1};


//inicialização do menu principal
do {
  printf ("\n[1] Iniciar partida\n[2]Visualizar Informações\n[3]Carregar Valores\n[4]Sair\n");
  scanf ("%d", &op);
  //iniciando a partida
    if (op==1){
    //menu da partida
         do { 
           
            printf ("\nDigite o número de usuário do jogador [1]:");
            scanf ("%d", &jogador1);
            jogador[jogador1]=jogador1;
            
            qtd_p_u1[jogador1]++;  
            part_user1[jogador1]=qtd_p_u1[jogador1]; 
            jogadas_user[jogador1]=qtd_p_u1[jogador1];
            
            printf ("Digite o número de usuário do jogador [2]:");
            scanf ("%d", &jogador1);
            jogador[jogador1]=jogador1;
            
            qtd_p_u1[jogador1]++;
            part_user1[jogador1]=qtd_p_u1[jogador1];
            jogadas_user[jogador1]=qtd_p_u1[jogador1];
           


          char c[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
          int vez=0;
          jogadas=1;
            do{

              //jogo
              if (vez%2==0){
                printf ("\nvez do jogador 1:");
              }
              else {
                printf ("\nvez do jogador 2:");
              }
              printf ("\nDigite a linha deseja jogar:");
              scanf ("%d", &i);
              printf ("Digite a coluna que deseja jogar:");
              scanf ("%d", &j);

              //condicoes valores invalidos
              if (i<1 || i>3 || j<1|| j>3){
                jogadas--;
                vez--;
                printf ("Jogada inválida. Digite um valor válido\n");
                }
              else if (c[i-1][j-1]!=' '){
                jogadas--;
                vez--;
                  printf ("Posicao ja utilizada. Digite outra posição\n");

                }
              //definindo de quem é a vez 
              else {
                if (vez%2==0){
                  c[i-1][j-1]='x';
                  
                } 
                else {
                  c[i-1][j-1]='o';
                  
                }
              }
              vez++;
              jogadas++;
            printf ("\t %c | %c | %c \n" , c[0][0], c[0][1], c[0][2]);
            printf ("\t %c | %c | %c \n" , c[1][0], c[1][1], c[1][2]);
            printf ("\t %c | %c | %c \n" , c[2][0], c[2][1], c[2][2]);
            //definindo o vencedor
            if (c[0][0]=='x' && c[0][1]=='x' && c[0][2]=='x'){jogadas=12;}
            if (c[1][0]=='x' && c[1][1]=='x' && c[1][2]=='x'){jogadas=12;}
            if (c[2][0]=='x' && c[2][1]=='x' && c[2][2]=='x'){jogadas=12;}
            if (c[0][0]=='x' && c[1][0]=='x' && c[2][0]=='x'){jogadas=12;}
            if (c[0][1]=='x' && c[1][1]=='x' && c[2][1]=='x'){jogadas=12;}
            if (c[0][2]=='x' && c[1][2]=='x' && c[2][2]=='x'){jogadas=12;}
            if (c[0][0]=='x' && c[1][1]=='x' && c[2][2]=='x'){jogadas=12;}
            if (c[0][2]=='x' && c[1][1]=='x' && c[2][0]=='x'){jogadas=12;}

            if (c[0][0]=='o' && c[0][1]=='o' && c[0][2]=='o'){jogadas=11;}
            if (c[1][0]=='o' && c[1][1]=='o' && c[1][2]=='o'){jogadas=11;}
            if (c[2][0]=='o' && c[2][1]=='o' && c[2][2]=='o'){jogadas=11;}
            if (c[0][0]=='o' && c[1][0]=='o' && c[2][0]=='o'){jogadas=11;}
            if (c[0][1]=='o' && c[1][1]=='o' && c[2][1]=='o'){jogadas=11;}
            if (c[0][2]=='o' && c[1][2]=='o' && c[2][2]=='o'){jogadas=11;}
            if (c[0][0]=='o' && c[1][1]=='o' && c[2][2]=='o'){jogadas=11;}
            if (c[0][2]=='o' && c[1][1]=='o' && c[2][0]=='o'){jogadas=11;}
            
            }while (jogadas<=9);
          qtd_jog++;
            
        //definindo o jogador
          if (jogadas==12){
                printf ("vencedor: jogador 1 \n");
                vituser[jogador1]++;
                vitoria[jogador1]=vituser[jogador1];                
          }
          if (jogadas==11){
                printf ("vencedor: jogador 2\n");
                vituser2[jogador1]++;                 

          }
          else if (jogadas==10) {printf ("empate\n");}

              

          //voltar ao menu ou jogar novamente
          printf ("Digite 1 para jogar novamente e qualquer outro valor para voltar ao menu:\n\n");
          scanf ("%d", &op2);
         
          } while (op2==1);}

    //visualizar informacoes  
    else if (op==2){
      
      printf ("[1] Quantidade de partidas jogadas ao todo\n[2] Quantidade de partidas jogadas por usuario\n[3] Quantidade de vitorias de todos usuarios\n[4]Quantidade de vitorias de um usuario especifico\n[5]Rank dos jogadores em ordem decrescente do numero de vitorias\n\n");
      scanf ("%d", &op3);
     //partidas ao todo
        switch (op3){
          case 1:
            printf ("A quantidade de partidas ao todo é de:%d\n", qtd_jog);
          break;
    //partidas por usuario
          case 2:
            printf ("Quantidade de partidas por usuario:\n");
            for (x=1;x<tam;x++){
              printf ("a quantidade de partidas pelo usuario [%d] é de:%d\n", jogador[x],jogadas_user[x]);
              }          
            break;
    //quantidade de vitoria
          case 3:
            for (x=1;x<tam;x++){
            printf ("a quantidade de vitoria do usuario [%d] é de:%d\n", jogador[x],vitoria[x]);
            }
          break;
    //vitoria por usuario
          int l;        
          case 4:
            printf ("Qual usuario deseja ver as vitorias?");
            scanf ("%d", &l);
            for (x=1;x<tam;x++){
              if (jogador[x]==l){
            printf ("O jogador [%d] tem [%d] vitorias",jogador[x],vitoria[x]);
              }
            }
          break;
    //rank de vitorias
        int aux1=0, aux2=0;

          case 5:          
            printf ("Rank:\n");
                              
              for (x=1; x < tam; x++){
                for (y = tam-1; y > x; y--) {
                  if (vitoria[y-1] < vitoria[y]) {
                    aux2 = vitoria[y-1];
                    aux1 = jogador[y-1];
                    
                    vitoria[y-1] = vitoria[y];
                    jogador[y-1] = jogador[y];
                    
                    vitoria[y] = aux2;
                    jogador[y] = aux1;                    
                  }
                }
              }
                
          for (y=1; y<tam; y++){
            printf ("o jogador %d tem %d vitorias\n", jogador[y], vitoria[y]);
          }
                             
          break; 

          default:
          printf ("Opção inválida");
          }
    }
//verificacao de valores
    else if (op==3){
      printf ("Verificacao de valores:\n");
      
        
          for (y=1; y<tam; y++){
            
          printf("O jogador %d jogou %d partidas e possui %d vitorias\n", jogador[y], jogadas_user[y], vitoria[y]);
          }
                       
        
    }
    else if (op>=5 || op<=0){
      printf ("opçao invalida");
    }
    else {
      printf ("fim de jogo");
    }
 
  }while (op!=4);

  return 0;
}

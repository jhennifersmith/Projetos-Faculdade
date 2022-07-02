/* Enunciado do Trabalho:

Implemente na linguagem C um programa para gerenciar Eventos Acadêmicos. O programa deve permitir o cadastro de Eventos, e para cada evento deve permitir o cadastro dos Palestrantes do evento.

O programa deve atender aos seguintes requisitos:

Possuir duas structs, uma para Eventos e outra para Palestrantes.
Armazenar os Eventos em uma listaP duplamente encadeada ordenada pela data do evento.
Armazenar os Palestrantes em uma listaP simplesmente encadeada ordenada pelo nome do palestrante.
O programa desenvolvido deve conter as seguintes funcionalidades:

Um menu inicial, que apresente ao usuário as opções do programa;
Opção de "Incluir Evento", que insere um novo evento na lista;
Opção de "Excluir Evento", que retira um evento da lista;
Opção de "Listar Todos os Eventos";
Opção de "Listar Eventos por Data", onde o usuário informará um mês para exibir os eventos;
Opção de "Gerenciar Evento", que permite cadastrar palestrantes em um determinado evento. Essa opção terá um menu auxiliar, com as seguintes opções:
Cadastrar Palestrante;
Excluir Palestrante;
Listar Palestrantes do Evento;
Uma opção para Sair ou Finalizar o programa;
Observações:

Sobre os eventos, é necessário apenas armazenar: Nome, Área Temática,  Data do evento e Código (numérico inteiro).
Sobre os palestrantes, é necessário armazenar: Nome, Email e Código (numérico inteiro).
Tanto os eventos quanto os palestrantes devem ter alocação dinâmica (use malloc()/calloc() para alocar, e free() para desalocar).
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stPalestrante Palestrante;
typedef struct stDescritor{
    Palestrante * Primeiro;
    int NumElementos;
} Descritor;

typedef struct stPalestrante{
  char NomePalestrante[50];
  char EmailPalestrante[100];
  int CodigoPalestrante;
  struct stPalestrante *Anterior;
  struct stPalestrante *Proximo;
} Palestrante;

typedef struct stPalestrante Palestrante;
typedef struct stEvento{
  char NomeEvento[50];
  char AreaTematica[50];
  char DataEvento[10];
  int DiaEvento;
  int MesEvento;
  int AnoEvento;
  int CodigoEvento;
  struct stEvento *Anterior;
  struct stEvento *Proximo;
  Descritor Palestrante;
} Evento;



int OpcaoMenu = 0;

//No para eventos
typedef struct stNo{
  int valor;
  struct stNo *Primeiro;
  struct stNo *Ultimo;
  int NumElem;
}No;
//No para Palestrante



int main(void){
    No lista;
    lista.Primeiro = NULL;
    lista.Ultimo = NULL;
    lista.NumElem = 0;

    Descritor listaP;
    listaP.NumElementos = 0;
    listaP.Primeiro = NULL;
  
    Evento * Aux;
    Evento * EventoAtual;
    Palestrante * AuxP;

    
  
  do{
    printf ("[1]Incluir Evento\n[2]Excluir Evento\n[3]Listar Todos os Eventos\n[4]Listar Eventos Por Data\n[5]Gerenciar Evento\n[6]Sair");
    scanf("%d", &OpcaoMenu);

    if (OpcaoMenu == 1){
      //CADASTRAR EVENTOS
            Aux = (Evento *) calloc(1, sizeof(Evento));
            printf("Digite o nome do evento: ");
            scanf("%s", Aux->NomeEvento);

            printf("Digite a area tematica: ");
            scanf("%s", Aux->AreaTematica);
      
            printf("Digite o dia do Evento 'dd': ");
            scanf("%d", &Aux->DiaEvento);

            printf("Digite o mes do Evento 'mm': ");
            scanf("%d", &Aux->MesEvento);
      
            printf("Digite o ano do Evento 'aaaa': ");
            scanf("%d", &Aux->AnoEvento);
      
            printf("Confirme a data do evento no formato aaaammdd: ");
            scanf("%s", Aux->DataEvento);
      
            printf("Digite o codigo do evento: ");
            scanf("%d", &Aux->CodigoEvento);

            printf("\n\tEvento cadastrado com sucesso! =)\n\n");
            
            lista.NumElem++;

            if(lista.Primeiro == NULL){
                lista.Primeiro = Aux;
                lista.Ultimo = Aux;
            }
            else{
               EventoAtual = lista.Primeiro;
                if(strcmp(Aux->DataEvento,EventoAtual->DataEvento) < 0){
                    Aux->Proximo =EventoAtual;
                   EventoAtual->Anterior = Aux;
                    lista.Primeiro = Aux;
                    Aux->Anterior = NULL;
                }
                else{
                    while(EventoAtual != NULL){
                        if(strcmp(Aux->DataEvento,EventoAtual->DataEvento) > 0){                      
                           EventoAtual =EventoAtual->Proximo;                   
                        }
                        else{                         
                           Evento * Temp;
                            Temp =EventoAtual->Anterior;
                            Temp->Proximo = Aux;
                           EventoAtual->Anterior = Aux;
                            Aux->Proximo =EventoAtual;
                            Aux->Anterior = Temp;
                            break;
                        }
                    }
                    if(EventoAtual == NULL){                       
                       Evento * Temp;
                        Temp = lista.Ultimo;
                        Aux->Anterior = Temp;
                        Temp->Proximo = Aux;
                        lista.Ultimo = Aux;
                        Aux->Proximo = NULL;
                    }
                }
            }
        
      
    }

    else if(OpcaoMenu == 2){
      //EXCLUIR EVENTO
                  if(lista.NumElem == 0){
                printf("Lista Vazia!\n");
                continue;
            }

            char NomeTemp[30], NomeTempUpr[30];
            printf("Digite o nome do evento desejado: ");
            scanf("%s", NomeTemp);
            strcpy(NomeTempUpr, NomeTemp);

            int cont=0;
            char NomeEvento[30];
            while(NomeTempUpr[cont] != '\0'){
                NomeTempUpr[cont] = toupper(NomeTempUpr[cont]);
                cont++;
            }

            Aux = lista.Primeiro;
            while(Aux != NULL){

                strcpy(NomeEvento, Aux->NomeEvento);
                cont = 0;
                while(NomeEvento[cont] != '\0'){
                    NomeEvento[cont] = toupper(NomeEvento[cont]);
                    cont++;
                }

                if(strcmp(NomeTempUpr, NomeEvento) == 0){
                    if(lista.NumElem == 1){

                        lista.Primeiro = NULL;
                        lista.Ultimo = NULL;
                    }
                    else if(Aux->Anterior == NULL){

                        (Aux->Proximo)->Anterior = NULL;
                        lista.Primeiro = Aux->Proximo;
                    }
                    else if(Aux->Proximo == NULL){

                        (Aux->Anterior)->Proximo = NULL;
                        lista.Ultimo = Aux->Anterior;
                    }
                    else{
                        Evento * Anterior = Aux->Anterior;
                        Evento * Proximo = Aux->Proximo;
                        Anterior->Proximo = Proximo;
                        Proximo->Anterior = Anterior;
                    }
                    lista.NumElem--;
                    free(Aux);
                    printf("Evento excluido!\n");
                    break;
                }
                else{
                    Aux = Aux->Proximo;
                }
            }
            if(Aux == NULL){
                printf("Evento nao encontrado!\n");
            }
    }

    else if(OpcaoMenu == 3){
      //LISTAR TODOS EVENTOS
      
       if(lista.NumElem == 0){
                printf("Lista vazia!\n");
            }
            else{
               Aux = lista.Primeiro;
               while(Aux != NULL){
               printf("Nome do evento: %s\n", Aux->NomeEvento);
               printf("Area tematica: %s\n", Aux->AreaTematica);
               printf("Dia do evento: %d\n", Aux->DiaEvento);
               printf("Data do evento: %d\n", Aux->MesEvento);
               printf("Data do evento: %d\n", Aux->AnoEvento);
               printf("Codigo do evento: %d\n", Aux->CodigoEvento);
               printf("\n");
                 
                Aux = Aux->Proximo;
                      }
              }
      }
        
    else if(OpcaoMenu == 4){
      //LISTAR EVENTOS POR DATA
      int MesTemp;
        if(lista.NumElem == 0){
             printf("Lista vazia!\n");
            }
        else{
              printf("Qual mês deseja acessar? \n");
              scanf("%d", &MesTemp);
              Aux = lista.Primeiro;
              while(Aux != NULL){
              if (Aux->MesEvento == MesTemp){
              printf("Nome do evento: %s\n", Aux->NomeEvento);
              printf("Area tematica: %s\n", Aux->AreaTematica);
              printf("Dia do evento: %d\n", Aux->DiaEvento);
              printf("Mes do evento: %d\n", Aux->MesEvento);
              printf("Ano do evento: %d\n", Aux->AnoEvento);
              printf("Codigo do evento: %d\n", Aux->CodigoEvento);
                        printf("\n");
                        
                      }
              else{
                printf ("Nenhum evento no mes digitado\n");
              }
                Aux = Aux->Proximo;

                }
              }
   
      
    }

    else if(OpcaoMenu == 5){
      //GERENCIAR EVENTOS
      int EventoTemp;
      int OpcaoMenuSecundario=0;
      printf ("Digite o codigo do evento deseja editar: \n");
      scanf("%d", &EventoTemp);
      Aux=lista.Primeiro;
      do{
        if (Aux == NULL){
          printf("Lista de Eventos vazia!\n");
          break;
        }
        else if (EventoTemp == Aux->CodigoEvento){
           do{
            printf("\n[1]Cadastrar Palestrante\n[2]Excluir Palestrante\n[3]Listar Palestrante\n[4]Voltar\n");
            scanf("%d", &OpcaoMenuSecundario);
             
            if (OpcaoMenuSecundario == 1){
              //CADASTRAR PALESTRANTE
              AuxP = (Palestrante *) calloc(1, sizeof(Palestrante));
              printf("Digite o nome do palestrante: ");
              scanf("%s", AuxP->NomePalestrante);
              printf("Digite o email do palestrante: ");
              scanf("%s", AuxP->EmailPalestrante);
              printf("Digite o codigo do palestrante: ");
              scanf("%d", &AuxP->CodigoPalestrante);
              AuxP->Proximo = NULL;
              listaP.NumElementos++; 
              Palestrante * PalestranteAtual;
              Palestrante * PalestranteAnterior;
              PalestranteAtual = Aux->Palestrante.Primeiro;
              if(Aux->Palestrante.Primeiro == NULL){
                  Aux->Palestrante.Primeiro = AuxP;
              }
              else if(strcmp(AuxP->NomePalestrante, PalestranteAtual->NomePalestrante) < 0){
                  AuxP->Proximo = Aux->Palestrante.Primeiro;
                  Aux->Palestrante.Primeiro = AuxP;
              }
              else{
                  PalestranteAnterior = PalestranteAtual;
                  PalestranteAtual = PalestranteAtual->Proximo;
                  while(PalestranteAtual != NULL){
                      if(strcmp(AuxP->NomePalestrante, PalestranteAtual->NomePalestrante) < 0){
                          PalestranteAnterior->Proximo = AuxP;
                          AuxP->Proximo = PalestranteAtual;
                          break;
                      }
                      else{
                          PalestranteAnterior = PalestranteAtual;
                          PalestranteAtual = PalestranteAtual->Proximo;
                      }
                  }
                  if(PalestranteAtual == NULL){
                      PalestranteAnterior->Proximo = AuxP;
                  }
  
              } 
            }
            else if (OpcaoMenuSecundario == 2){
              //EXCLUIR PALESTRANTES 
              Palestrante * PalestranteAtual;
              Palestrante * PalestranteAnterior;
              PalestranteAtual = Aux->Palestrante.Primeiro;
              if(PalestranteAtual == NULL){
                  printf("Lista vazia!\n");
              }
              else{
                  char NomeExcluir[30];
                  printf("Digite o Palestrante a ser excluido: ");
                  scanf("%s", NomeExcluir);
  
                  if(strcmp(NomeExcluir, PalestranteAtual->NomePalestrante) == 0){
                      Aux->Palestrante.Primeiro = PalestranteAtual->Proximo;
                      free(PalestranteAtual);
                      printf("Palestrante %s excluido!\n", NomeExcluir);
                      listaP.NumElementos--;
                  }
                  else{
                      while(PalestranteAtual != NULL){
                          if(strcmp(NomeExcluir, PalestranteAtual->NomePalestrante) == 0){
                              PalestranteAnterior->Proximo = PalestranteAtual->Proximo;
                              free(PalestranteAtual);
                              printf("Palestrante %s excluido!\n", NomeExcluir);
                              listaP.NumElementos--;
                              break;
                          }
                          else{ 
                              PalestranteAnterior = PalestranteAtual;
                              PalestranteAtual = PalestranteAtual->Proximo;
                          }
                      }
                      if(PalestranteAtual == NULL){
                          printf("Palestrante %s NAO encontrado!\n", NomeExcluir);
                      }
                  }
              }
            
          }
          else if (OpcaoMenuSecundario == 3){
            //LISTAR PALESTRANTES
            AuxP = Aux->Palestrante.Primeiro;
            printf("Palestrantes cadastrados neste evento:\n");
            while(AuxP != NULL){
                printf("Nome Palestrante: %s\nEmail Palestrante: %s\nCodigo do Palestrante: %d\n", AuxP->NomePalestrante, AuxP->EmailPalestrante, AuxP->CodigoPalestrante);
                AuxP = AuxP->Proximo;
            }
          }
          else if (OpcaoMenuSecundario == 4){
            //VOLTAR
          }
          else {
            printf("Opção invalida! Tente novamente.\n");
          }
        }while(OpcaoMenuSecundario != 4);
           
        break;
        } 
         else{
           printf("Evento não encontrado!\n");
        }       

        Aux=Aux->Proximo;

      }while(Aux!=NULL);
     
    }
    else if(OpcaoMenu > 6 || OpcaoMenu <= 0){
     printf ("Opção invalida! Tente novamente.\n");
    }
    
  }while (OpcaoMenu != 6);
  
  return 0;
}
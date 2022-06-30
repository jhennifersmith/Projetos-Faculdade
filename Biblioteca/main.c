#include <stdio.h>
/*Implemente na linguagem C um programa de Cadastro de Livros para a biblioteca. O programa deve utilizar structs para armazenar as informaÃ§Ãµes dos livros, e deve conter as seguintes funcionalidades:

Um menu inicial, que apresente ao usuário as opcoes do programa;
Opções de Cadastrar, 
Alterar e Listar os livros (não é necessário excluir);
Uma opção para Sair ou Finalizar o programa;
Sobre os livros, as informações que devem ser armazenadas são: Título, Autor, Código de barras (ou Identificação), Edição e Ano. Não é necessário salvar as informações em arquivos-texto;
O programa deve permitir o cadastro de no máximo 20 livros.*/

typedef struct livro {
char titulo[100];
char autor[100];
char codigo[100];
char edicao[100];
}LIVROS;

LIVROS CadastrarLivro(LIVROS L1){
  printf("Cadastro de Livros\n\n");

  printf ("Digite o titulo:");
  getchar();
  scanf ("%[^\n]s", L1.titulo);
  
  printf ("Digite o autor:");
  getchar();
  scanf ("%[^\n]s", L1.autor);
  
  printf ("Digite o codigo de barras:");
  getchar();
  scanf ("%[^\n]s", L1.codigo);
  
  printf ("Digite a edição:");
  getchar();
  scanf ("%[^\n]s", L1.edicao);

return L1;
}

void ExibirLivros(LIVROS L1){
    int i=0;
    printf("Titulo: %s\nAutor: %s\nCodigo de Barra: %s\nEdicao: %s\n\n",
           L1.titulo, L1.autor, L1.codigo, L1.edicao);
}

LIVROS AlterarLivro(LIVROS L1){
  printf("\n\nAlteração de Livros\n\n");

  printf ("Digite o novo titulo:");
  getchar();
  scanf ("%[^\n]s", L1.titulo);

  printf ("Digite o novo autor:");
  getchar();
  scanf ("%[^\n]s", L1.autor);

  printf ("Digite o novo codigo de barras:");
  getchar();
  scanf ("%[^\n]s", L1.codigo);

  printf ("Digite a edição:");
  getchar();
  scanf ("%[^\n]s", L1.edicao);

return L1;
}


int main(void) {
  LIVROS ListaL1[40];
  int i=0;
  int j;
  int contador=0;
 
  
  int op=0;
  do {
    
    printf("[1] Cadastrar um novo livro\n[2]Alterar um livro\n[3]Listar livros\n[4]Sair\n");
    scanf("%d", &op);
    if (op==1){
       ListaL1[i] = CadastrarLivro(ListaL1[i]);
       i++;
       contador++;
    }
    else if (op==2){
        printf("Qual livro deseja alterar?");
        scanf ("%i", &j);
        ListaL1[j] = AlterarLivro(ListaL1[j]);
        
    }
    else if (op==3){
      printf ("Livros cadastrados:\n");
      for(int i=0; i<=contador-1; i++){
        printf ("Livro [%i]\n", i);
      ExibirLivros(ListaL1[i]);}
    }
    else if (op==4){
      printf ("Programa finalizado");
    }
    else {
      printf ("Opção inválida, digite novamente uma opção válida\n\n");
    }
    
  }while(op!=4);
  
  return 0;
}
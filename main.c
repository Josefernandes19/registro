/* 
 * File:   main.c
 * Author: a15014 e a15001
 *
 * Created on 16 de Junho de 2015, 14:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct{
    int dia;
    int mes;
    int ano;
} data;
typedef struct {
    char primeiroNome[15];
    char ultimoNome[20];
    int telefone;
    char rua[30];
    char bairro[20];
    int numeroCasa;
    char cpf[12];
}cliente;
typedef struct {
   int telefone;
   float preco;
   float quantidade;
   int descricao [30];
   data dataProduto_valida;
   char dataProduto[10];
}produto;
int buscarCliente(cliente* clientes,int n){
    int tel,i,existe=0,posicao;
    printf ("Informe o numero do telefone do cliente: ");
    scanf ("%d", &tel);
    for (i = 0; i < n; i++) {
        if(clientes[i].telefone==tel) {
            existe=1;
            printf("Cliente encontrado: %s\n", clientes[i].primeiroNome);
            posicao = i;
        }
    }
    if (existe==0){
        printf ("Cliente não encontrado\n ");
        printf ("Digite novamente :\n");
        scanf ("%d", &tel);
    }
    return posicao;
}
int minha_comparacao (const char *a, const char *b) {
    int r = strcasecmp(a, b);
    if (r) return r;
    return -strcmp(a, b);
}
void ordemA(cliente* clientes, int n){
    int i ;
    cliente aux;
     for (i=0;i<n-1;i++){
        if (minha_comparacao(clientes[i+1].primeiroNome,clientes[i].primeiroNome)<0){
            aux = clientes[i];
            clientes[i] = clientes[i+1];
            clientes[i+1] = aux;
            i=0;
        }
     }
}
void inserirCliente(cliente* clientes,int n){    
    cliente cliente;
    printf("Digite o primeiro nome do cliente: ");
    scanf("%s", &cliente.primeiroNome);
    printf("Digite o ultimo nome do cliente: ");
    scanf("%s", &cliente.ultimoNome);
    printf("Digite o telefone do cliente: ");
    scanf("%d", &cliente.telefone);
    printf("Digite a rua do cliente: ");
    scanf("%s", &cliente.rua);
    printf("Digite o bairro do cliente: ");
    scanf("%s", &cliente.bairro);
    printf("Digite o numero da casa do cliente: ");
    scanf("%d", &cliente.numeroCasa);
    printf("Digite o CPF do cliente: ");
    scanf("%s", &cliente.cpf);
    clientes[n]=cliente;
    salvarCliente(clientes, n+1);
}
void alterarCliente(cliente* clientes, int n){
    int opcao, alterar;
    alterar=buscarCliente(clientes,n);
    printf (" O que deseja alterar ?\n");
    printf ("1- Nome :\n");
    printf ("2- Sobrenome :\n");
    printf ("3- Telefone :\n");
    printf ("4- Rua:\n");
    printf ("5- Bairro:\n");
    printf ("6- Numero da casa:\n");
    printf ("7- CPF:\n");
    printf ("8- Sair\n");
    printf ("Qual sua opção ?");
    scanf ("%d", &opcao);
    while (opcao > 7 || opcao <1){
        printf ("Opção inválida, escolha outra :");
        scanf ("%d", &opcao);
    }
    switch(opcao){
        case 1:
            printf ("Digite o nome :");
            scanf ("%s", &clientes[alterar].primeiroNome); 
            break;
        case 2:
            printf ("Digite o sobrenome :");
            scanf ("%s", &clientes[alterar].ultimoNome);
            break;
        case 3:
            printf ("Digite o telefone :");
            scanf ("%d", &clientes[alterar].telefone);
            break;
        case 4:
              printf ("Digite o nome rua :");
            scanf ("%s", &clientes[alterar].rua);
            break ;
        case 5:
              printf ("Digite o nome do bairro :");
            scanf ("%s", &clientes[alterar].bairro);
            break ;
        case 6:
              printf ("Digite o numero da casa :");
            scanf ("%d", &clientes[alterar].numeroCasa);
            break ;
        case 7:
              printf ("Digite o CPF :");
            scanf ("%s", &clientes[alterar].cpf);
            break;
        }
    salvarCliente(clientes, n);
}
void deletarCliente(cliente* clientes, produto* produtos,int ncliente,int nproduto){
      int i,removido=0,existe=0,tel,j;
    printf("Digite o telefone do cliente: ");
    scanf("%d", &tel);    
    for (i = 0; i < ncliente; i++) {
         if(clientes[i].telefone==tel) {
            existe=1;
            
            printf("Cliente removido: %s\n", clientes[i].primeiroNome);      
             for(j=i;j<=ncliente;j++){
                 clientes[j]=clientes[j+1];          
             }
            ncliente--;
            i--;
        }
    }
    if (existe==0){
        printf ("Cliente não encontrado\n ");
    }
    for (i = 0; i < nproduto; i++) {
        if(produtos[i].telefone==tel) {
            removido++;            
            printf("Produto Removido: Descrição: %s, Data: %s, Preço: %f, Qtd: %f\n", produtos[i].descricao, produtos[i].dataProduto, produtos[i].preco, produtos[i].quantidade);
            for(j=i;j<=nproduto;j++){
                 produtos[j]=produtos[j+1];          
             }
            nproduto--;
            i--;
        }
    }
    if (removido==0){
        printf ("Nenhum produto encontrado\n ");
    } 
    salvarCliente(clientes,ncliente);
    salvarProduto(produtos,nproduto);
}
void inserirProduto(produto* produtos, int n){
    produto produto;
    int dia, mes,ano, valida=0;
    printf("Digite o telefone do cliente do produto: ");
    scanf("%d", &produto.telefone);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);
    printf("Digite a quantidade do produto: ");
    scanf("%f", &produto.quantidade);
    printf("Digite a descrição do produto: ");
    scanf("%s", &produto.descricao);
    do{        
    data date;
    printf("Digite o dia da data da venda: ");
    scanf("%d", &produto.dataProduto_valida.dia);
    printf("Digite o mes da data da venda: ");
    scanf("%d", &produto.dataProduto_valida.mes);
    printf("Digite o ano da data da venda: ");
    scanf("%d", &produto.dataProduto_valida.ano);
    if(validaData(produto.dataProduto_valida.dia,produto.dataProduto_valida.mes,produto.dataProduto_valida.ano)==1){
    valida=1;
    produtos[n] = produto;
    salvarProduto(produtos, n+1);
    }else{
        printf("Data inválida\n");
    }
    } while (valida==0);
    
}
void deletarProduto(produto* produtos, int n){
    int i,removido=0,tel,j;
    printf("Digite o telefone do cliente: ");
    scanf("%d", &tel);
    for (i = 0; i < n; i++) {
        if(produtos[i].telefone==tel) {
            removido++;
            printf("Produto Removido: Descrição: %s, Data: %s, Preço: %f, Qtd: %f\n", produtos[i].descricao, produtos[i].dataProduto, produtos[i].preco, produtos[i].quantidade);
             for(j=i;j<=n;j++){
                 produtos[j] = produtos[j+1];                 
             }
            n--;
            i--;
        }
    }
    if (removido==0){
        printf ("Nenhum produto encontrado\n ");
    } 
    salvarProduto(produtos,n);
}
int validaData(int dia, int mes, int ano){
   int dias_no_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   int verdadeiro = 0;
   if(ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0))
    dias_no_mes[1]=29;
   if (mes<13)
   {
      if( dia <= dias_no_mes[mes-1] )
        verdadeiro=1;
   }
   return verdadeiro;
}
void buscarProdutoDoCliente(produto* produtos, int n){
    int i,existe=0,tel;
    printf("Digite o telefone do cliente: ");
    scanf("%d", &tel);
    for (i = 0; i < n; i++) {
        if(produtos[i].telefone==tel) {
            existe=1;
            printf("Produto encontrado: Descrição: %s, Data: %s, Preço: %f, Qtd: %f\n", produtos[i].descricao, produtos[i].dataProduto, produtos[i].preco, produtos[i].quantidade);
        }
    }
    if (existe==0){
        printf ("Nenhum produto encontrado\n ");
    }
}
void salvarCliente(cliente* clientes, int n){
    FILE *arquivos;
    ordemA(clientes, n);
    arquivos = fopen("cliente.txt", "w");
    fprintf(arquivos,"%d", n);
    fprintf(arquivos, "\n");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(arquivos, "%s ", clientes[i].primeiroNome);
        fprintf(arquivos, "%s ", clientes[i].ultimoNome);
        fprintf(arquivos, "%d ", clientes[i].telefone);
        fprintf(arquivos, "%s ", clientes[i].rua);
        fprintf(arquivos, "%s ", clientes[i].bairro);
        fprintf(arquivos, "%d ", clientes[i].numeroCasa);
        fprintf(arquivos, "%s ", clientes[i].cpf);
        fprintf(arquivos, "\n");
    }
    fclose(arquivos);
}
void salvarProduto(produto* produtos, int n){
    FILE *arquivos;
    arquivos = fopen("produto.txt", "w+");
    fprintf(arquivos,"%d", n);
    fprintf(arquivos, "\n");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(arquivos, "%d ", produtos[i].telefone);
        fprintf(arquivos, "%f ", produtos[i].preco);
        fprintf(arquivos, "%f ", produtos[i].quantidade);
        fprintf(arquivos, "%s ", produtos[i].descricao);
        if(produtos[i].dataProduto_valida.dia!=0){
        fprintf(arquivos, "%d/%d/%d", produtos[i].dataProduto_valida.dia,produtos[i].dataProduto_valida.mes,produtos[i].dataProduto_valida.ano);
        }else{
        fprintf(arquivos, "%s", produtos[i].dataProduto);
        }
        fprintf(arquivos, "\n");
    }
    fclose(arquivos);

}
int menu (){
    int opcao;
    printf ("---M E N U---\n");
    printf ("1-Inserir cliente\n");
    printf ("2-Alterar cliente\n");
    printf ("3-Deletar cliente\n");
    printf ("4-Buscar cliente\n");
    printf ("5-Inserir produto\n");
    printf ("6-Deletar produto\n");
    printf ("7-Buscar produtos do cliente\n");
    printf ("8 Buscar Produto aleatório\n");
    printf ("9-Buscar cliente aleatório\n");
    printf ("10-Buscar produtos por preço\n");
    printf ("11-Sair\n");
    printf ("Qual a opção desejada ?");
    scanf ("%d", &opcao);
    return opcao;
}
void buscaClienteAleatorio(cliente* clientes, int i){
      i=rand() % i;
    printf("Cliente encontrado: %s\n", clientes[i].primeiroNome);
}
void buscaProdutoAleatorio(produto* produtos, int i){
        i=rand() % i;
     printf("Produto encontrado: Descrição: %s, Data: %s, Preço: %f, Qtd: %f\n", produtos[i].descricao, produtos[i].dataProduto, produtos[i].preco, produtos[i].quantidade);
}
void buscaPreco(produto* produtos, int n){
    int existe=0, i;
    float aux;
    printf("Digite um valor para buscar: ");
    scanf("%f", &aux);
    for (i = 0; i < n; i++) {
        if(produtos[i].preco==aux) {
            existe=1;
            printf("Produto encontrado: Descrição: %s, Data: %s, Preço: %f, Qtd: %f\n", produtos[i].descricao, produtos[i].dataProduto, produtos[i].preco, produtos[i].quantidade);
        }
    }
    if(existe==0){
        printf("Nenhum produto encontrado com esse preço\n");
    }
}
int main() {
    int escolha, n_cliente,n_produto,i, posicao;
    escolha=menu();
    FILE *arquivo;
    arquivo = fopen ("cliente.txt","r");	
    fscanf (arquivo,"%d", &n_cliente);
    cliente clientes[1000];    
    FILE *arquivo_produto;
    arquivo_produto = fopen ("produto.txt","r");	
    fscanf (arquivo_produto,"%d", &n_produto);
    produto produtos[1000];    
    for (i = 0; i < n_cliente; i++) {
    fscanf(arquivo, "%s %s %d %s %s %d %s", 
                &clientes[i].primeiroNome,&clientes[i].ultimoNome,&clientes[i].telefone,
                &clientes[i].rua,&clientes[i].bairro,&clientes[i].numeroCasa,&clientes[i].cpf);   
    }    
    for (i = 0; i < n_produto; i++) {
        fscanf(arquivo_produto, "%d %f %f %s %s", &produtos[i].telefone, &produtos[i].preco, &produtos[i].quantidade, &produtos[i].descricao, &produtos[i].dataProduto);
        produtos[i].dataProduto_valida.dia=0;
        produtos[i].dataProduto_valida.mes=0;
        produtos[i].dataProduto_valida.ano=0;
    }

    while(escolha!=11){
        switch(escolha){
            case 1:
                inserirCliente(clientes,n_cliente);
                break;
            case 2:
                alterarCliente(clientes,n_cliente);
                break ;
            case 3:
                deletarCliente(clientes,produtos,n_cliente,n_produto);
                break;
            case 4:
                buscarCliente(clientes,n_cliente);
                break;        
            case 5:
                inserirProduto(produtos,n_produto);
                break;
                case 6:
                    deletarProduto(produtos,n_produto);
                break;
                case 7:
                buscarProdutoDoCliente(produtos,n_produto);
                break;
            case 8:
                buscaProdutoAleatorio(produtos, n_produto);
                break;
            case 9:                
                buscaClienteAleatorio(clientes, n_cliente);
                break;
            case 10:
                buscaPreco(produtos,n_produto);
                break;
                
                
        }
        escolha =menu();
    }
    fclose(arquivo_produto);
    fclose(arquivo);
    return 0;
}





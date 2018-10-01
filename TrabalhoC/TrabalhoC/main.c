#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *entrada;
    FILE *saida;
    int c1, l1, c2, l2, i, j, cnt;
    float v, s;
    
    //Abre arquivo
    entrada = fopen("entrada.txt", "r");
    saida = fopen("saida.txt", "w");
            
    //Verifica tamanho da Matriz 1
    fscanf(entrada, "%d %d", &l1, &c1);
    
    //Cria matriz 1
    float matriz1[l1][c1];
    
    //Ler matriz 1
    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            fscanf(entrada, "%f", &v);
            matriz1[i][j] = v;
        }
    }
    
    //Verifica tamanho da Matriz 2
    fscanf(entrada, "%d %d", &l2, &c2);
    
    //Cria matriz 2
    float matriz2[l2][c2];
    
    //Ler matriz 2
    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            fscanf(entrada, "%f", &v);
            matriz2[i][j] = v;
        }
    }
    
    //Fecha arquivo de entrada
    fclose(entrada);
    
    //Verifica se são iguais, multiplica matrizes e escreve no arquivo
    if (c1 == l2)
    {
        float matrizn[l1][c2];
        for (i = 0; i < l1; i++)
        {
            for (cnt = 0; cnt < c2; cnt++)
            {
                s = 0;
                for (j = 0; j < c1; j++)
                {
                    s = (matriz1[i][j] * matriz2[j][i]) + s;
                }
                matrizn[i][cnt] = s;
            }
        }
        fprintf(saida, "%d %d\n", l1, c2);
        for (i = 0; i < l1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                fprintf(saida, "%.2f ", matrizn[i][j]);
            }
            fprintf(saida, "\n");
        }
    }
    else
    {
        fprintf(saida, "Multiplicação impossível");
    }
    
    //Fecha arquivo de saída
    fclose(saida);
    return 0;
}


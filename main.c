#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *vet, int minimo, int maximo, int valor, int count);

int main(void) {

  int quant, valor;
  int count = 0;

  scanf("%d",&quant);

  int* vetor = (int*) malloc(quant * sizeof(int));

  for(int i = 0; i < quant; i++){
    scanf("%d",&vetor[i]);
  }

  scanf("%d",&valor);

  count = busca_binaria(vetor, 0, quant-1, valor, count);

  free(vetor);

  if(count == -1){
    printf("%d nao foi encontrado",valor);
  } else 
    printf("%d",count);

  return 0;
}

int busca_binaria(int *vet, int minimo, int maximo, int valor, int count){

  int meio = (minimo + maximo)/2 ;

  if(vet[meio] == valor)
    return count;

  if(maximo < minimo)
    return -1;

  if(vet[meio] < valor){
    count++;
    return busca_binaria(vet, meio+1, maximo, valor, count);
  } else {
      count++;
      return busca_binaria(vet, minimo, meio-1, valor, count);
  }

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

int *vetor(numero){
	int *vetor;
	vetor = (int *) malloc(4 * sizeof(int));
	int i;
	char str_numero[10];
	sprintf(str_numero, "%d", numero);
	int j = strlen(str_numero) - 4;
	if (j >= 0){
		for (i = 0; i < 4; i++){
			vetor[i] = str_numero[j] - '0';
			j++;
		}
	}else{
		j = 4 - strlen(str_numero);
		for (i = 0; i < j; i++){
			vetor[i] = 0;
		}
		int k = 0;
		for(; j < 4; j++){
			vetor[j] = str_numero[k] - '0';
			k += 1;
		}
	}
	return vetor;
}

int main(int argc, char** argv){
	
	while(true){
		float valor = 0, res = 0;
		int escolhido, sorteado;
		scanf("%f %d %d", &valor, &escolhido, &sorteado);
		if (valor == 0 && escolhido == 0 && sorteado == 0){
			return 0;
		}else{
			int *vetor_escolhidos = vetor(escolhido);
			int *vetor_sorteados = vetor(sorteado);
			if (vetor_escolhidos[0] == vetor_sorteados[0] && vetor_escolhidos[1] == vetor_sorteados[1] && vetor_escolhidos[2] == vetor_sorteados[2] && vetor_escolhidos[3] == vetor_sorteados[3]){
				res = valor * 3000;
			}else{
				if (vetor_escolhidos[1] == vetor_sorteados[1] && vetor_escolhidos[2] == vetor_sorteados[2] && vetor_escolhidos[3] == vetor_sorteados[3]){
					res = valor * 500;
				}else {
					if (vetor_escolhidos[2] == vetor_sorteados[2] && vetor_escolhidos[3] == vetor_sorteados[3]){
						res = valor * 50;
					}else {
						char dois_ultimos_esc[3];
						dois_ultimos_esc[0] = '0' + vetor_escolhidos[2];
						dois_ultimos_esc[1] = '0' + vetor_escolhidos[3];
						dois_ultimos_esc[2] = '\0';
						
						char dois_ultimos_sort[3];
						dois_ultimos_sort[0] = '0' + vetor_sorteados[2];
						dois_ultimos_sort[1] = '0' + vetor_sorteados[3];
						dois_ultimos_sort[2] = '\0';
						if(strcmp(dois_ultimos_esc, "00") == 0){
							int n1 = 100;
							int n2 = atoi(dois_ultimos_sort);
							if (n1 - n2 < 4){
								res = valor * 16;
							}
						}else if (strcmp(dois_ultimos_sort, "00") == 0){
							int n1 = 100;
							int n2 = atoi(dois_ultimos_esc);
							if (n1 - n2 < 4){
								res = valor * 16;
							}
						}else{
							int n1 = atoi(dois_ultimos_esc);
							int n2 = atoi(dois_ultimos_sort);
							if (abs(n1 - n2) < 4){
								res = valor * 16;
							}
						}
					}
				}
			}
		}
		printf("%.2f\n", res);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

typedef int boolean;
#define true 1
#define false 0

struct submissao {
    char id;
    char status[10];
    int minutos;
};


int main(){
    int n;

    while(true){
        scanf("%d ", &n);
        if (n == 0){
            return 0;
        }else{
        	struct submissao sub[26];
        	int k = 0;
            int i;
            for(i = 0; i < n; i++){
                char id;
                int mins;
                char status[10];
                scanf("%c %d %9s", &id, &mins, status);
                fflush(stdin);
                
                int achou = false;
                int j;
                for (j = 0; j < 26; j++){
					if(sub[j].id == id){
						achou = true;
						if(strcmp(sub[j].status, "incorreto") == 0 && strcmp(status, "correto") == 0){
							mins += 20;
							sub[j].minutos = mins;
							strcpy(sub[j].status, "correto");
							break;
						}
					}
				}
				if (achou == false){
					sub[k].id = id;
					sub[k].minutos = mins;
					strcpy(sub[k].status, status);
					k += 1;
				}
            }
            int mins_totais = 0;
            int total_corretos = 0;
            int l;
            for(l = 0; l < 26; l++){
				if (strcmp(sub[l].status, "correto") == 0){
					total_corretos += 1;
					mins_totais += sub[l].minutos;
				}
			}
			printf("%d %d\n", total_corretos, mins_totais);
        }
    }
    return 0;
}
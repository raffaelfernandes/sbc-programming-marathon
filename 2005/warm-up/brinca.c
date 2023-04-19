#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

int main(){
    int n;

    while(true){
        int vitorias_alice = 0;
        int vitorias_beto = 0;
        int venc;

        scanf("%d", &n);
        if (n == 0){
            return 0;
        }else{
            // int jogos[n];
            int i;
            for(i = 0; i < n; i++){
                scanf("%d", &venc);
                if (venc == 0){
                    vitorias_alice += 1;
                }else{
                    vitorias_beto += 1;
                }
            }
            printf("Alice ganhou %d e Beto ganhou %d\n", vitorias_alice, vitorias_beto);
        }
    }

    return 0;
}
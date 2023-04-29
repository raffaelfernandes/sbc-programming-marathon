#include <bits/stdc++.h>
using namespace std;

class parDeBotas{
public:
    int tam;
    bool esq;
    bool dir;
    parDeBotas(){
        esq = false;
        dir = false;
    }
    parDeBotas(int tam1, char L){
        tam = tam1;
        if(L == 'E'){
            esq = true;
            dir = false;
        }
        if(L == 'D'){
        	esq = false;
            dir = true;
        }
    }
};

int main(){

    int botas, y = 0, tamAtual, numPares = 0;
    char lAtual;
    bool achou = false;

    cin >> botas;
    parDeBotas pares[(botas/2)+1];
    int tamanho = 0;

    for(int i = 0; i < botas; i++){
        cin >> tamAtual;
        cin >> lAtual;

        if(tamanho > 0){
            for(int i = 0; i < tamanho; i++){
                parDeBotas botas = pares[i];
                if(tamAtual == botas.tam){
                    if(lAtual == 'E'){
                        if(botas.esq == false){
                            botas.esq = true;
                        }else{
                            continue;
                        }
                    }else if(lAtual == 'D'){
                        if(botas.dir == false){
                            botas.dir = true;
                        }else{
                            continue;
                        }
                    }
                    if(botas.esq == true && botas.dir == true){
                        botas.esq = false;
                        botas.dir = false;
                        numPares++;
                        achou = true;
                        break;
                    }
                }
            }
        }

        if(achou == false){
            pares[y] = parDeBotas(tamAtual, lAtual);
            tamanho++;
            y++;
        }else{
            achou = false;
        }
    }

    cout << numPares << endl;

    return 0;
}
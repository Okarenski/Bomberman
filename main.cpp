/**
    Estrutura inicial para um jogo
    versão: 0.1 (Prof. Alex,  Adaptado Prof. Felski)
*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h> // para o movimento do inimigo
#include <stdlib.h> // --

using namespace std;




bool colisao(int p){
    if (p!=0){
        return false;
    } else
        return true;
}







int main()
{
    srand(time(0));

    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
        //INICIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
        short int CX=0, CY=0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
    ///ALERTA: NAO MODIFICAR O TRECHO DE CODIGO, ACIMA.

    int m[7][7]={   1,1,1,1,1,1,1,
                    1,0,0,0,0,0,1,
                    1,0,0,0,1,1,1,
                    1,0,0,0,1,0,1,
                    1,1,0,0,1,0,1,
                    1,0,0,0,0,0,1,
                    1,1,1,1,1,1,1};




    //Posicao inicial do personagem no console
    int x=5, y=5;
    // posicao inicial do inimigo no console
    int xi = 1, yi = 1;
    int xi2 = 3, yi2 = 3;
    //Variavel para tecla precionada
    char tecla;
    // variavel personagem e inimigo
    char personagem(153);
    char inimigo (041);
    char inimigo2 (041);

    while(true){
        ///Posiciona a escrita no iicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for(int i=0;i<7;i++){
            for(int j=0;j<7;j++){ // imprime a matriz
                if(i==x && j==y){
                    cout<<personagem; //personagem




                    }else if(i==xi&&j==yi){

                            cout << inimigo;

                       }else if(i==xi2 && j==yi2){   // ver de mudar essa feiura para um for
                         cout << inimigo2;










                 }else {

                    switch (m[i][j]){
                        case 0: cout<<" "; break; //caminho
                        case 1: cout<<char(219); break; //parede
                        //default: cout<<"-"; //erro
                    } //fim switch
                }
            }
            cout<<"\n";
        } //fim for mapa




         ///executa os movimentos
         if ( _kbhit() ){
            tecla = getch();
            switch(tecla)
            {
                case 72: case 'w': ///cima
                    x--;
                    if(colisao(m[x][y]==false)){
                        x++;
                    }
                break;

                case 80: case 's': ///baixo
                    x++;
                    if(colisao(m[x][y]==false)){
                        x--;
                    }
                break;
                case 75:case 'a': ///esquerda
                    y--;
                    if(colisao(m[x][y]==false)){
                        y++;
                    }
                break;

                case 77: case 'd': ///direita
                    y++;
                    if(colisao(m[x][y]==false)){
                        y--;
                    }
                break;
            }}
        
        //movimento inimigo 

             int movimento = rand()% 800;
             switch(movimento){
                   case 0: if(xi>0){
                    xi--;
                    if(colisao(m[xi][yi]==false)){
                        xi++;
                    }
                break;}

                  case 1: if(xi<6){
                    xi++;
                    if(colisao(m[xi][yi]==false)){
                        xi--;
                    }
                break;}
               case 2: if(yi>0){
                    yi--;
                    if(colisao(m[xi][yi]==false)){
                        yi++;
                    }
                break;}

                 case 3: if(yi<6){
                    yi++;
                    if(colisao(m[xi][yi]==false)){
                        yi--;
                    }
                break;}
            }
         }

        int movimento2 = rand()% 800;
         switch(movimento2){
                   case 0: if(xi2>0){
                    xi2++;
                    if(colisao(m[xi2][yi2]==false)){
                        xi2--;
                    }
                break;}

                  case 1: if(xi2<6){
                    xi2--;
                    if(colisao(m[xi2][yi2]==false)){
                        xi2++;
                    }
                break;}
               case 2: if(yi>0){
                    yi2++;
                    if(colisao(m[xi2][yi2]==false)){
                        yi2--;
                    }
                break;}

                 case 3: if(yi2<6){
                    yi2++;
                    if(colisao(m[xi2][yi2]==false)){
                        yi2--;
                    }
                break;}
                return 0;

            }

         }












     //fim do laco do jogo

//fim main

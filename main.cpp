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

int bomba(int j, int k){
    for(int i=3;i==0;i--){
        for(int p=3;i==0;i--){
            int m[j][k]=3;
        }

    }  m[j][k]=0;

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

    int m[10][20]=            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                               1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                               1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,
                               1,0,2,0,2,0,2,0,0,0,1,0,2,0,0,0,0,0,0,1,
                               1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,2,1,1,2,1,
                               1,0,0,0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,1,
                               1,0,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,
                               1,0,0,0,2,0,1,0,0,0,1,0,1,1,1,2,1,1,1,1,
                               1,0,1,1,1,0,2,0,0,0,2,0,0,0,0,0,0,0,0,1,
                               1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};



    //Posicao inicial do personagem no console
    int x=8, y=18;
    // posicao inicial do inimigo no console
    int xi = 1, yi = 18;
    int xi2 = 1, yi2 = 3;
    int xi3 = 1, yi3 = 5;
    //posição bomba

    //Variavel para tecla precionada
    char tecla;
    // variavel personagem, inimigo e bomba.
    char personagem(153);
    char inimigo   (041);
    char inimigo2  (041);
    char inimigo3  (041);
    char bomba     (022);

    while(true){
        ///Posiciona a escrita no iicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for(int i=0;i<10;i++){
            for(int j=0;j<20;j++){ // imprime a matriz
                if(i==x && j==y){
                    cout<<personagem; //personagem




                    }else if(i==xi&&j==yi){

                            cout << inimigo;

                       }else if(i==xi2 && j==yi2){   // ver de mudar essa feiura para um for
                         cout << inimigo2;


                 } else if (i==xi3&&j==yi3){
                        cout << inimigo3;



                 }else {

                    switch (m[i][j]){
                        case 0: cout<<" "; break; //caminho
                        case 1: cout<<char(219); break; //parede
                        case 2: cout<<char(176); break; //parede quebravel
                        case 3: cout<<char(022); break; //bomba
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

                case 81: case 'z': ///bomba
                    for(int i=3,i)
                    m[x][y]=3;

            }}

        //movimento inimigo

             int movimento = rand()% 90;
             switch(movimento){
                   case 27:
                    xi++;
                    if(colisao(m[xi][yi]==false)){
                        xi--;
                    }
                break;

                  case 48:
                    xi--;
                    if(colisao(m[xi][yi]==false)){
                        xi++;
                    }
                break;

                  case 61:
                    yi++;
                    if(colisao(m[xi][yi]==false)){
                        yi--;
                    }
                break;

                 case 84:
                    yi--;
                    if(colisao(m[xi][yi]==false)){
                        yi++;
                    }
                break;
            }


        int movimento2 = rand()% 90;
         switch(movimento2){
                   case 15:
                    xi2++;
                    if(colisao(m[xi2][yi2]==false)){
                        xi2--;
                    }
                break;

                  case 28:
                    xi2--;
                    if(colisao(m[xi2][yi2]==false)){
                        xi2++;
                    }
                break;
               case 59:
                    yi2++;
                    if(colisao(m[xi2][yi2]==false)){
                        yi2--;
                    }
                break;

                 case 87:
                    yi2--;
                    if(colisao(m[xi2][yi2]==false)){
                        yi2++;
                    }
                break;}

        int movimento3 = rand()% 90;
         switch(movimento3){
                   case 17:
                    xi3++;
                    if(colisao(m[xi3][yi3]==false)){
                        xi3--;
                    }
                break;

                  case 31:
                    xi3--;
                    if(colisao(m[xi3][yi3]==false)){
                        xi3++;
                    }
                break;
               case 64:
                    yi3++;
                    if(colisao(m[xi3][yi3]==false)){
                        yi3--;
                    }
                break;

                 case 83:
                    yi3--;
                    if(colisao(m[xi3][yi3]==false)){
                        yi3++;
                    }
                break;}
                }
                return 0;

            }














     //fim do laco do jogo

//fim main

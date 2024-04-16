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
struct inimigo { /// stuct inimigo 1 2 3
    int xi,yi;
};

bool explosao (int ex){ /// função da bomba destruir paredes
    if (ex==2){
        return false;
    }   else
         return true;
}

bool colisao(int p){ /// colisão
    if (p!=0){
        return false;
    } else
        return true;
}

bool timer (int &bomb){ /// timer da bomba
    if(bomb==100){
        return false;
    } else {
        bomb++;
        return true;
    }
}


int main()
{
    int entrada;

     cout << "=============================" << endl;
    cout << "        BEM-VINDO AO JOGO     " << endl;
    cout << "=============================" << endl;
    cout << "Digite 1 para jogar ou 2 para sair" << endl;
    do{

        cin >> entrada;
         if (entrada != 1 && entrada != 2) {
            cout << "Digite novamente." << endl;
        } else if (entrada == 2) {
            break;

        } else {
    system("cls");

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



    //condição derrota
        int gameover;
    //codição de vitoria
        int vit = 0;
        int InimigosAtivos=3;
    //selecionar
        int selecionar;
    //Posicao inicial do personagem no console
        int x=8, y=18;
    // posicao inicial do inimigo no console
        inimigo um;
    //inimigo dois;
        inimigo dois;
    //inimigo tres;
        inimigo tres;
    //posição inicial inimigo
        um.xi=1;
        um.yi=18;
        dois.xi=1;
        dois.yi=3;
        tres.xi=1;
        tres.yi=5;
    //posição da bomba
        int xb=-1,yb=-1;
    //timer bomba
        int bomb=1;
    //timer da exploção
        int explo=1;
    //Variavel para tecla precionada
        char tecla;
    // variavel personagem, inimigo e bomba.
        char personagem(153);
        char inimigo1  (041);
        char inimigo2  (041);
        char inimigo3  (041);
        char bomba     (022);
        char quente    (105);
        char kbom      (161);

    while(true){
        ///Posiciona a escrita no iicio do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for(int i=0;i<10;i++){
            for(int j=0;j<20;j++){ // imprime a matriz
                    if(i==x && j==y){

                    cout<<personagem; //personagem

                    }else if(i==um.xi && um.yi==j){

                        cout << inimigo1;

                       }else if(i==dois.xi && j==dois.yi){

                         cout << inimigo2;

                        } else if (i==tres.xi && j==tres.yi){

                            cout << inimigo3;

                        }else if ((i==xb&&j==yb)&&(bomb>20&&bomb<30)){ ///bomba esquentando

                                cout << quente;

                        }else if ((i==xb&&j==yb)&&(bomb>50&&bomb<60)){ ///bomba esquentando

                                cout << quente;

                        }else if ((i==xb&&j==yb)&&(bomb>80&&bomb<90)){ /// bomba esquentado

                                cout << quente;

                        }else if(i==xb&&j==yb){

                                cout << bomba;

                        } else if((i==xb&&j==yb+1)&&(bomb>97&&bomb<=100)){ /// exploção direita

                                cout << kbom;

                        } else if((i==xb&&j==yb-1)&&(bomb>97&&bomb<=100)){ /// exploção esquerda

                                cout << kbom;

                        } else if((i==xb+1&&j==yb)&&(bomb>97&&bomb<=100)){ /// exploção baixo

                                cout << kbom;

                        } else if((i==xb-1&&j==yb)&&(bomb>97&&bomb<=100)){ /// exploção cima

                                cout << kbom;

                        } else {

                        switch (m[i][j]){
                            case 0: cout<<" "; break; //caminho
                            case 1: cout<<char(219); break; //parede
                            case 2: cout<<char(176); break; //parede quebravel
                            case 3: cout<<char(022); break; //bomba
                        //default: cout<<"-"; //erro
                    }    //fim switch
                }
            }
            cout<<"\n";
        } //fim for mapa

            if((x==um.xi&&y==um.yi)||(x==dois.xi&&y==dois.yi)||(x==tres.xi&&y==tres.yi)){ ///inimigo mata player
                x=-3;
                y=-3;
                break;
        }
        if(xb!=-1&&yb!=-1){ /// verificação se tem uma bomba no mapa para começar o timer
                            /// tem que ficar fora por do for por causa do if do player, se não o timer não começa a contar
            if (timer(bomb)==false){ /// timer da bomba
                m[xb][yb]=0;

                if(x==xb&&y==yb){ /// player morrer em cima da bomba
                    x=-3;
                    y=-3;
                    break;
                }

                if(explosao(m[xb][yb+1]) == false){ ///parede ///direita
                    m[xb][yb+1]=0;

                } if (xb==x&&yb+1==y){ ///player morre
                    x=-3;
                    y=-3;
                    break;

                } if(xb==um.xi && yb+1==um.yi){ /// inimigo 1
                    um.xi=-2;
                    um.yi=-2;
                    InimigosAtivos--;
                }
                if(xb==dois.xi && yb+1==dois.yi){ ///inimigo 2
                    dois.xi=-2;
                    dois.yi=-2;
                    InimigosAtivos--;
                }
                if(xb==tres.xi && yb+1==tres.yi){ ///inimigo 3
                    tres.xi=-2;
                    tres.yi=-2;
                    InimigosAtivos--;
                }

                if(explosao(m[xb][yb-1]) == false){ ///parede ///esquerda
                    m[xb][yb-1]=0;

                }   if (xb==x&&yb-1==y){ ///player morre
                    x=-3;
                    y=-3;
                    break;

                } if(xb==um.xi && yb-1==um.yi){ /// inimigo 1
                    um.xi=-2;
                    um.yi=-2;
                    InimigosAtivos--;

                } if(xb==dois.xi && yb-1==dois.yi){ ///inimigo 2
                    dois.xi=-2;
                    dois.yi=-2;
                    InimigosAtivos--;

                } if(xb==tres.xi && yb-1==tres.yi){ ///inimigo 3
                    tres.xi=-2;
                    tres.yi=-2;
                    InimigosAtivos--;
                }

                if(explosao(m[xb+1][yb]) == false){ ///parede ///baixo
                    m[xb+1][yb]=0;

                }  if (xb+1==x&&yb==y){ ///player morre
                    x=-3;
                    y=-3;
                    break;

                } if(xb+1==um.xi && yb==um.yi){ /// inimigo 1
                    um.xi=-2;
                    um.yi=-2;
                    InimigosAtivos--;

                } if(xb+1==dois.xi && yb==dois.yi){ ///inimigo 2
                    dois.xi=-2;
                    dois.yi=-2;
                    InimigosAtivos--;

                } if(xb+1==tres.xi && yb==tres.yi){ ///inimigo 3
                    tres.xi=-2;
                    tres.yi=-2;
                    InimigosAtivos--;
                }

                if(explosao(m[xb-1][yb]) == false){ ///parede ///cima
                    m[xb-1][yb]=0;

                } if (xb-1==x&&yb==y){ ///player morre
                    x=-3;
                    y=-3;
                    break;

                } if(xb-1==um.xi && yb==um.yi){ /// inimigo 1
                    um.xi=-2;
                    um.yi=-2;
                    InimigosAtivos--;

                } if(xb-1==dois.xi && yb==dois.yi){ ///inimigo 2
                    dois.xi=-2;
                    dois.yi=-2;
                    InimigosAtivos--;

                } if(xb-1==tres.xi && yb==tres.yi){ ///inimigo 3
                    tres.xi=-2;
                    tres.yi=-2;
                    InimigosAtivos--;
                }

                bomb = 1; ///reset da bomba
                xb=-1;
                yb=-1;
            }
        }
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
                    if(xb==-1&&yb==-1) ///verificador se ja tem uma bomba no mapa
                    {
                        xb=x;
                        yb=y;
                        m[xb][yb]=3; ///marca a bomba na matriz
                    }
                    break;
                }
            }

        //movimento inimigo

             int movimento = rand()% 90;
             switch(movimento){
                   case 27:
                    um.xi--;
                    if(colisao(m[um.xi][um.yi]==false)){
                        um.xi++;
                    }
                    break;

                  case 48:
                    um.xi++;
                    if(colisao(m[um.xi][um.yi]==false)){
                        um.xi--;
                    }
                    break;

                  case 61:
                    um.yi--;
                    if(colisao(m[um.xi][um.yi]==false)){
                        um.yi++;
                    }
                    break;

                 case 84:
                    um.yi++;
                    if(colisao(m[um.xi][um.yi]==false)){
                        um.yi--;
                    }
                    break;
                }

        int movimento2 = rand()% 90;
         switch(movimento2){

                case 15:
                    dois.xi--;
                    if(colisao(m[dois.xi][dois.yi]==false)){
                        dois.xi++;
                    }
                    break;

                case 28:
                    dois.xi++;
                    if(colisao(m[dois.xi][dois.yi]==false)){
                        dois.xi--;
                    }
                    break;

                case 59:
                    dois.yi--;
                    if(colisao(m[dois.xi][dois.yi]==false)){
                        dois.yi++;
                    }
                    break;

                 case 87:
                    dois.yi++;
                    if(colisao(m[dois.xi][dois.yi]==false)){
                        dois.yi--;
                    }
                    break;
                }

        int movimento3 = rand()% 90;
         switch(movimento3){

                case 17:
                    tres.xi--;
                    if(colisao(m[tres.xi][tres.yi]==false)){
                        tres.xi++;
                    }
                    break;

                case 31:
                    tres.xi++;
                    if(colisao(m[tres.xi][tres.yi]==false)){
                        tres.xi--;
                    }
                    break;

                case 64:
                    tres.yi--;
                    if(colisao(m[tres.xi][tres.yi]==false)){
                        tres.yi++;
                    }
                    break;

                case 83:
                    tres.yi++;
                    if(colisao(m[tres.xi][tres.yi]==false)){
                        tres.yi--;
                    }
                    break;
                }
                    if (InimigosAtivos==0) {
                        vit = 1; // Define vitória
                        break; // Sai do loop
                    }

                }

                system("cls");
                if(vit==1){
                    cout<<"Parabens bixo se ganhou, voce e pika! :D "<<endl;
                    system("pause");
                    return 0;
                }

                if(vit==0){
                    cout<<"game over!"<<endl;
                    cout<<"deseja tentar novamente? [1] sim [2] nao :"<<endl;

                do {
                    cin>>selecionar;
                    if(selecionar<1&&selecionar>2){
                        cout<<"opcao invalida! digite novamente."<<endl;
                        cin>>selecionar;
                    }

                switch(selecionar){

                    case 1:

                        system("cls");
                        main();
                        break;

                    case 2:

                        return 0;
                        break;

                        }
                    } while (selecionar>1&&selecionar<2);
                }
                 return 0;
            }
        }while(true);
    }

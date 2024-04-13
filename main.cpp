#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Inimigo {
    int xi, yi;
};

bool explosao(int ex) {
    if (ex == 2) {
        return false;
    } else {
        return true;
    }
}

bool colisao(int p) {
    if (p != 0) {
        return false;
    } else {
        return true;
    }
}

bool timer(int &bomb) {
    if (bomb == 100) {
        return false;
    } else {
        bomb++;
        return true;
    }
}

bool areaexp(int &explo) {
    if (explo == 50) {
        return false;
    } else {
        explo++;
        return true;
    }
}


void verificacaoExplosao(int xb, int yb, int m[10][20]){
  explosão vertical
    for (int i = xb - 1; i >= 0 && m[i][yb] != 1; i--) {  // inicializa i com a posição inicial e verifica se o elemento da matriz é diferente de 1 (parede) // -1 (cima)
        if (m[i][yb] == 0 || m[i][yb] == 2 ) {   // troca dos caracteres
                  m[i][yb] = '*';;


        } else {

        }
    }
    for (int i = xb + 1; i < 10 && m[i][yb] != 1; i++) {  // +1 (baixo)
        if (m[i][yb] == 0 || m[i][yb]==2) {
             m[i][yb] = '*';;
        } else {

        }

    }
    for (int j = yb - 1; j >= 0 && m[xb][j] != 1; j--) {
        if (m[xb][j] == 0 || m[xb][j]==2) {
             m[xb][j] = '*';;
        } else {

        }
    }
    for (int j = yb + 1; j < 20 && m[xb][j] != 1; j++) {
        if (m[xb][j] == 0 || m[xb][j]==2) {
             m[xb][j] = '*';;
        } else {

        }
    }

}





//for para trocar os eixos da matriz por um caractere

bool explosaoo = true;


int main() {
 int i;
 int j;
    int entrada;
    system("cls");
    srand(time(0));
    cout << "Digite 1 para jogar ou 2 para sair" << endl;

    do {
        cin >> entrada;
        if (entrada != 1 && entrada != 2) {
            cout << "Digite novamente" << endl;
        }
    } while (entrada != 1 && entrada != 2);

    if (entrada == 2) {
        return 0;
    } else {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(out, &cursorInfo);
        short int CX = 0, CY = 0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;

        int m[10][20] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 2, 1, 1, 2, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 2, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

        int gameover;
        int x = 8, y = 18;
        Inimigo um;
        Inimigo dois;
        Inimigo tres;
        um.xi = 1;
        um.yi = 18;
        dois.xi = 1;
        dois.yi = 3;
        tres.xi = 1;
        tres.yi = 5;
        int bomb = 1;
        int explo = 1;
        int xb = -1, yb = -1; // posição inicial da bomba

        char tecla;
        char personagem = 153;
        char inimigo1 = 041;
        char inimigo2 = 041;
        char inimigo3 = 041;
        char bomba = 022;
       // char quente = 105;
       char animacao = 42;


        while (true) {



                if(explosaoo){  //verifica se está acontecendo uma explosão, se sim, chama void


  verificacaoExplosao ( yb, xb, m);


}



            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 20; j++) {
                    if (i == x && j == y) {
                        cout << personagem;
                    } else if (i == um.xi && um.yi == j) {
                        cout << inimigo1;
                    } else if (i == dois.xi && j == dois.yi) {
                        cout << inimigo2;
                    } else if (i == tres.xi && j == tres.yi) {
                        cout << inimigo3;
                    } else if (i == xb && j == yb) {
                        cout << bomba;
                    } else {
                        switch (m[i][j]) {
                            case 0: cout << " "; break;
                            case 1: cout << char(219); break;
                            case 2: cout << char(176); break;
                            case 3: cout << char(022); break;
                            case 4: cout << char(105); break;
                            case 5: cout << animacao; break;
                        }
                    }
                }
                cout << "\n";
            }

            if ((x == um.xi && y == um.yi) || (x == dois.xi && y == dois.yi) || (x == tres.xi && y == tres.yi)) {
                x = -3;
                y = -3;
                break;
            }
            if (xb != -1 && yb != -1) {
                if (timer(bomb) == false) {
                    m[xb][yb] = 0;
                    if (explosao(m[xb][yb + 1]) == false) {
                        m[xb][yb + 1] = 0;
                        if (areaexp(explo) == false) {
                            m[xb][yb + 1] = 4;
                        }
                    }
                    if (xb == x && yb + 1 == y) {
                        x = -3;
                        y = -3;
                    }
                    if (xb == um.xi && yb + 1 == um.yi) {
                        um.xi = -2;
                        um.yi = -2;
                    }
                    if (xb == dois.xi && yb + 1 == dois.yi) {
                        dois.xi = -2;
                        dois.yi = -2;
                    }
                    if (xb == tres.xi && yb + 1 == tres.yi) {
                        tres.xi = -2;
                        tres.yi = -2;
                    }
                    if (explosao(m[xb][yb - 1]) == false) {
                        m[xb][yb - 1] = 0;
                    }
                    if (xb == x && yb - 1 == y) {
                        x = -3;
                        y = -3;
                    }
                    if (xb == um.xi && yb - 1 == um.yi) {
                        um.xi = -2;
                        um.yi = -2;
                    }
                    if (xb == dois.xi && yb - 1 == dois.yi) {
                        dois.xi = -2;
                        dois.yi = -2;
                    }
                    if (xb == tres.xi && yb - 1 == tres.yi) {
                        tres.xi = -2;
                        tres.yi = -2;
                    }
                    if (explosao(m[xb + 1][yb]) == false) {
                        m[xb + 1][yb] = 0;
                    }
                    if (xb + 1 == x && yb == y) {
                        x = -3;
                        y = -3;
                    }
                    if (xb + 1 == um.xi && yb == um.yi) {
                        um.xi = -2;
                        um.yi = -2;
                    }
                    if (xb + 1 == dois.xi && yb == dois.yi) {
                        dois.xi = -2;
                        dois.yi = -2;
                    }
                    if (xb + 1 == tres.xi && yb == tres.yi) {
                        tres.xi = -2;
                        tres.yi = -2;
                    }
                    if (explosao(m[xb - 1][yb]) == false) {
                        m[xb - 1][yb] = 0;
                    }
                    if (xb - 1 == x && yb == y) {
                        x = -3;
                        y = -3;
                    }
                    if (xb - 1 == um.xi && yb == um.yi) {
                        um.xi = -2;
                        um.yi = -2;
                    }
                    if (xb - 1 == dois.xi && yb == dois.yi) {
                        dois.xi = -2;
                        dois.yi = -2;
                    }
                    if (xb - 1 == tres.xi && yb == tres.yi) {
                        tres.xi = -2;
                        tres.yi = -2;
                    }
                    bomb = 1;
                    xb = -1;
                    yb = -1;
                }
            }

            if (_kbhit()) {
                tecla = getch();
                switch (tecla) {
                    case 72: case 'w':
                        x--;
                        if (colisao(m[x][y]) == false) {
                            x++;
                        }
                        break;
                    case 80: case 's':
                        x++;
                        if (colisao(m[x][y]) == false) {
                            x--;
                        }
                        break;
                    case 75: case 'a':
                        y--;
                        if (colisao(m[x][y]) == false) {
                            y++;
                        }
                        break;
                    case 77: case 'd':
                        y++;
                        if (colisao(m[x][y]) == false) {
                            y--;
                        }
                        break;
                    case 81: case 'z':
                        if (xb == -1 && yb == -1) {
                            xb = x;
                            yb = y;
                            m[xb][yb] = 3;
                        }
                        break;
                }
            }

            int movimento = rand() % 90;
            switch (movimento) {
                case 27:
                    um.xi--;
                    if (colisao(m[um.xi][um.yi]) == false) {
                        um.xi++;
                    }
                    break;
                case 48:
                    um.xi++;
                    if (colisao(m[um.xi][um.yi]) == false) {
                        um.xi--;
                    }
                    break;
                case 61:
                    um.yi--;
                    if (colisao(m[um.xi][um.yi]) == false) {
                        um.yi++;
                    }
                    break;
                case 84:
                    um.yi++;
                    if (colisao(m[um.xi][um.yi]) == false) {
                        um.yi--;
                    }
                    break;
            }

            int movimento2 = rand() % 90;
            switch (movimento2) {
                case 15:
                    dois.xi--;
                    if (colisao(m[dois.xi][dois.yi]) == false) {
                        dois.xi++;
                    }
                    break;
                case 28:
                    dois.xi++;
                    if (colisao(m[dois.xi][dois.yi]) == false) {
                        dois.xi--;
                    }
                    break;
                case 59:
                    dois.yi--;
                    if (colisao(m[dois.xi][dois.yi]) == false) {
                        dois.yi++;
                    }
                    break;
                case 87:
                    dois.yi++;
                    if (colisao(m[dois.xi][dois.yi]) == false) {
                        dois.yi--;
                    }
                    break;
            }

            int movimento3 = rand() % 90;
            switch (movimento3) {
                case 17:
                    tres.xi--;
                    if (colisao(m[tres.xi][tres.yi]) == false) {
                        tres.xi++;
                    }
                    break;
                case 31:
                    tres.xi++;
                    if (colisao(m[tres.xi][tres.yi]) == false) {
                        tres.xi--;
                    }
                    break;
                case 64:
                    tres.yi--;
                    if (colisao(m[tres.xi][tres.yi]) == false) {
                        tres.yi++;
                    }
                    break;
                case 83:
                    tres.yi++;
                    if (colisao(m[tres.xi][tres.yi]) == false) {
                        tres.yi--;
                    }
                    break;
            }
        }
        system("cls");
        cout << "Game over!" << endl;
        cout << "Deseja tentar novamente? Digite [1] para continuar ou [2] para desistir." << endl;
        do {
            cin >> gameover;
        } while (gameover != 1 && gameover != 2);
        return 0;
    }
}

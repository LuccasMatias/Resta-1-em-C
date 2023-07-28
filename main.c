//============== Universidade Estadual do Rio de Janeiro =============

//                    Aluno: Lucas Matias Góes da Silva




#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//--------------- Teclas definidas pelo sistema -----------------
#define TECLA_CIMA 328
#define TECLA_BAIXO 336
#define TECLA_ESQ 331
#define TECLA_DIR 333
#define TECLA_ENTER 13



int main(){
//------------------------------------Variáveis---------------------------------------------//
    char tabuleiroCalculo[7][7], tabuleiroVisual[7][7], entrada = ' ', saida;
    int teclaPressionada, jogadas,teclaPressionada_ch,i,j,win = 0,eixoX = 3,eixoY = 3, movimentos = 0;

//-------------------------Criação do Tabuleiro ---------------------------------------------//
    for (i=0; i <= 6; i++){
            for (j=0; j<=6;j++){
                tabuleiroVisual[i][j] = '*'; tabuleiroCalculo[i][j] = '1'; // define os primeiros valores nos vetores
                tabuleiroVisual[3][3] = 'x'; tabuleiroCalculo[3][3] = '2'; //apaga o ponto central do vetor
                                //bloqueio das áreas da matriz que não deve ser utilizada no jogo
                if(i <=1 && j<= 1){tabuleiroVisual[i][j] = ' '; tabuleiroCalculo[i][j] = '0';} //apaga a primeira parte da matriz
                if(i <=1 && j>=5){tabuleiroVisual[i][j] = ' '; tabuleiroCalculo[i][j] = '0';}  //apaga a segunda parte da matriz
                if(i >=5 && j<= 1){tabuleiroVisual[i][j] = ' '; tabuleiroCalculo[i][j] = '0';} //apaga a terceira parte da matriz
                if(i >=5 && j>= 5){tabuleiroVisual[i][j] = ' '; tabuleiroCalculo[i][j] = '0';} //apaga a quarta parte da matriz
                };}

//--------------------------------------------------- Menu inicial-------------------------------------
    printf("------------------------------ Regras do Jogo  ---------------------------------- \n \n\n\n");
    printf("    1)- As teclas direcionais movimentam a posicao 'x' no tabuleiro \n");
    printf("    2)- Pressione a tecla ENTER para selecionar a peca a ser movimentada\n");
    printf("    3)- Apos selecionar a peca, use as teclas direcionais para fazer segundo movimento \n\n\n\n");
    printf("    O jogo terminara quando nao existir mais movimentos possaveis \n\n\n");
    printf("                      Bom jogo");

    teclaPressionada = getch();
    system("cls");
//-------------------------------------------- Início do Jogo --------------------------------------------
    do{
            jogadas = 0; //Contador de jogadas possíveis zerado
            printf("              ============================ \n");
            printf("              |           Resta 1        | \n");
            printf("              ============================ \n");

            for (i=0; i <= 6; i++){
                    printf("                      ");
                for (j=0; j<=6;j++){
                        //Parte visual do Tabuleiro, atualizando a cada movimento feito
                    if(tabuleiroCalculo[i][j] == '0'){tabuleiroVisual[i][j] = '.';};
                    if(tabuleiroCalculo[i][j] == '1'){tabuleiroVisual[i][j] = '*';};
                    if(tabuleiroCalculo[i][j] == '2'){tabuleiroVisual[i][j] = ' ';};
                        tabuleiroVisual[eixoX][eixoY] = 'X'; //ponto de movimento dentro do tabuleiro
                        printf("%c ", tabuleiroVisual[i][j]);

                        //Contador de jogadas possíveis
                        if ((tabuleiroCalculo[i][j] == '1') && (tabuleiroCalculo[i+1][j] == '1' || tabuleiroCalculo[i-1][j] == '1' || tabuleiroCalculo[i][j+1] == '1' || tabuleiroCalculo[i][j-1] == '1')) {
                            jogadas++;}

                        }; //imprime o vetor na tela
                        printf("\n");}
            printf("\n");
            printf("\n");

            if(jogadas == 0){ win = 1;} //fim do loop do jogo
            printf("Jogadas Possiveis: %d \n",jogadas);
            printf("Jogadas feitas: %d\n ",movimentos);

            teclaPressionada = getch();
            // Pequeno filtro de movimento para o funcionamento da captura de teclas
            if(teclaPressionada == 0 || teclaPressionada ==224){
                teclaPressionada = 256+getch();}


//---------------------------------- INPUT DE MOVIMENTOS -----------------------------------------------------------------------------------
                        switch(teclaPressionada){
                            //movimento CIMA
                            case TECLA_CIMA:
                                if(eixoX >= 0 && (tabuleiroCalculo[eixoX-1][eixoY] == '1' || tabuleiroCalculo[eixoX-1][eixoY] == '2' )){

                                    entrada = tabuleiroVisual[eixoX-1][eixoY];
                                    tabuleiroVisual[eixoX-1][eixoY] = 'X';

                                        if(movimentos == 0) {tabuleiroVisual[eixoX][eixoY] = ' ';}
                                        if(movimentos == 1){tabuleiroVisual[eixoX][eixoY] = '*';}
                                        if(movimentos > 1){tabuleiroVisual[eixoX][eixoY] = entrada;}
                                        eixoX--;

                                        }
                            break;
                            case TECLA_ESQ:
                                if(eixoY > 0 && (tabuleiroCalculo[eixoX][eixoY-1] == '1' || tabuleiroCalculo[eixoX][eixoY-1] == '2' )){

                                    entrada = tabuleiroVisual[eixoX][eixoY-1];
                                    tabuleiroVisual[eixoX][eixoY-1] = 'X';

                                        if(movimentos == 0) {tabuleiroVisual[eixoX][eixoY] = ' ';}
                                        if(movimentos == 1){tabuleiroVisual[eixoX][eixoY] = '*';}
                                        if(movimentos > 1){tabuleiroVisual[eixoX][eixoY] = entrada;}
                                        eixoY--;

                                        }
                            break;
                            case TECLA_DIR:
                                if(eixoY > 0 && (tabuleiroCalculo[eixoX][eixoY+1] == '1' || tabuleiroCalculo[eixoX][eixoY+1] == '2' )){

                                    entrada = tabuleiroVisual[eixoX][eixoY+1];
                                    tabuleiroVisual[eixoX][eixoY+1] = 'X';

                                        if(movimentos == 0) {tabuleiroVisual[eixoX][eixoY] = ' ';}
                                        if(movimentos == 1){tabuleiroVisual[eixoX][eixoY] = '*';}
                                        if(movimentos > 1){tabuleiroVisual[eixoX][eixoY] = entrada;}
                                        eixoY++;

                                        }
                            break;
                            case TECLA_BAIXO:
                                if(eixoX >= 0 && (tabuleiroCalculo[eixoX+1][eixoY] == '1' || tabuleiroCalculo[eixoX+1][eixoY] == '2' )){

                                    entrada = tabuleiroVisual[eixoX+1][eixoY];
                                    tabuleiroVisual[eixoX+1][eixoY] = 'X';

                                        if(movimentos == 0) {tabuleiroVisual[eixoX][eixoY] = ' ';}
                                        if(movimentos == 1){tabuleiroVisual[eixoX][eixoY] = '*';}
                                        if(movimentos > 1){tabuleiroVisual[eixoX][eixoY] = entrada;}
                                        eixoX++;

                                        }
                            break;
//---------------------------------------------INPUT de seleção e movimentação segunda------------------------------------------------------------------------------
                            case TECLA_ENTER:
                                teclaPressionada_ch = getch();
                                if(teclaPressionada_ch == 0 || teclaPressionada_ch ==224){
                                        teclaPressionada_ch = 256+getch();}

                                switch (teclaPressionada_ch){
                                    case TECLA_CIMA:
                                        if(tabuleiroCalculo[eixoX-2][eixoY] == '2' && tabuleiroCalculo[eixoX-1][eixoY] == '1') { // Verifica se o movimento é válido
                                            tabuleiroCalculo[eixoX-1][eixoY] = '2'; //faz a peça central sumir
                                            tabuleiroCalculo[eixoX-2][eixoY] = '1'; // faz a peça anterior ir para o local vazio
                                             tabuleiroCalculo[eixoX][eixoY] = '2'; // faz o local anterior ficar vazio
                                             movimentos++;
                                             eixoX-=2;}
                                        break;

                                    case TECLA_BAIXO:
                                         if(tabuleiroCalculo[eixoX+2][eixoY] == '2' && tabuleiroCalculo[eixoX+1][eixoY] == '1'){
                                            tabuleiroCalculo[eixoX+1][eixoY] = '2';
                                            tabuleiroCalculo[eixoX][eixoY] = '2';
                                            tabuleiroCalculo[eixoX+2][eixoY] = '1';
                                            movimentos++;
                                            eixoX+= 2;}
                                        break;
                                    case TECLA_ESQ:
                                         if(tabuleiroCalculo[eixoX][eixoY-2] == '2' && tabuleiroCalculo[eixoX][eixoY-1] == '1'){
                                            tabuleiroCalculo[eixoX][eixoY-1] = '2';
                                            tabuleiroCalculo[eixoX][eixoY] = '2';
                                            tabuleiroCalculo[eixoX][eixoY-2] = '1';
                                            movimentos++;
                                            eixoY-= 2;}
                                        break;
                                    case TECLA_DIR:
                                         if(tabuleiroCalculo[eixoX][eixoY+2] == '2' && tabuleiroCalculo[eixoX][eixoY+1] == '1'){
                                            tabuleiroCalculo[eixoX][eixoY+1] = '2';
                                            tabuleiroCalculo[eixoX][eixoY] = '2';
                                            tabuleiroCalculo[eixoX][eixoY+2] = '1';
                                            movimentos++;
                                            eixoY+= 2;}
                                        break;} // fim switch de movimentação dupla

                            break; //fim case TECLA_ENTER
                        }
                system("cls");
        }while(win == 0);
    //--------------------------------------Tela Final do Jogo---------------------------
        printf("              ============================ \n");
        printf("              |           Resta 1        | \n");
        printf("              ============================ \n");

        printf("\n\n                        FIM DE JOGO \n\n\n");
        printf("                  Movimentos feitos: %d \n\n\n\n",movimentos);


    return 0;

}


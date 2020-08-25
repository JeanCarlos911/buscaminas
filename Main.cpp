# include <iostream>

using namespace std;

int matriz[][];

void modificarTablero(int filaSeleccionada, int columnaSeleccionada, int size);

int main(){
    int sizeIn = -1;

    cout << "\n"
            "      ____                                  _                 \n"
            "     / __ )__  ________________ _____ ___  (_)___  ____ ______\n"
            "    / __  / / / / ___/ ___/ __ `/ __ `__ \\/ / __ \\/ __ `/ ___/\n"
            "   / /_/ / /_/ (__  ) /__/ /_/ / / / / / / / / / / /_/ (__  ) \n"
            "  /_____/\\__,_/____/\\___/\\__,_/_/ /_/ /_/_/_/ /_/\\__,_/____/  \n"
            "                                                              \n" << endl;

    while(sizeIn<4){
        cout << "- Cuanto mide cada lado de la matriz?\n  $ " << ends;
        cin >> sizeIn;
        if(sizeIn < 4){
            cout << "El valor minimo del lado es 4, ya que si es menor, 3n es superior o igual a n*n, y no habrian casillas libres." << endl;
        }
    }
    int const size = sizeIn;

    int matriz[size][size];
    int minas = 3 * size;
    
    //LLENA LA MATRIZ CON -10 (espacios vacios que no se muestran)
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matriz[i][j] = -10;
        }
    }

    //COLOCA MINAS: el -10 es vacio y no muestra, el -11 es mina y no muestra
    while(minas>0){
        int valorA = rand() % size;
        int valorB = rand() % size;
        if(matriz[valorA][valorB] != -11){
            matriz[valorA][valorB] = -11;
            minas--;
        }
    }

    //COLOCA LOS NUMEROS
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(matriz[i][j] != -11){
                int contadorMinas=0;

                //izquierda
                if(j>0 && matriz[i][j-1]==-11){
                    contadorMinas++;
                }
                //izquierda y arriba
                if(j>0 && i>0 && matriz[i-1][j-1]==-11){
                    contadorMinas++;
                }
                //arriba
                if(i>0 && matriz[i-1][j]==-11){
                    contadorMinas++;
                }
                //arriba y derecha
                if(i>0 && j<size-1 && matriz[i-1][j+1]==-11){
                    contadorMinas++;
                }
                //derecha
                if(j<size-1 && matriz[i][j+1]==-11){
                    contadorMinas++;
                }
                //derecha y abajo
                if(i<size-1 && j<size-1 && matriz[i+1][j+1]==-11){
                    contadorMinas++;
                }
                //abajo
                if(i<size-1 && matriz[i+1][j]==-11){
                    contadorMinas++;
                }
                //abajo e izquierda
                if(i>0 && j<size-1 && matriz[i-1][j+1]==-11){
                    contadorMinas++;
                }
                if(contadorMinas!=0){
                    matriz[i][j] = contadorMinas * -1;
                }
            }
        }
    }

    //EMPIEZA EL JUEGO
    string estado = "continuar";
    int casillasPorMarcarRestantes = 3 * size;

    while(estado.compare("continuar") == 0){
        int filaSeleccionada = -1;
        int columnaSeleccionada = -1;
        int opcionSeleccionada = -1;

        //MUESTRA TABLERO 
        for(int i=0; i<size; i++){
            //parte superior de la linea
            if(i==0){
                for(int j=0; j<size; j++){
                    printf("%4d", j+1);
                }
                cout << "" << endl;
            }
            for(int j=0; j<size; j++){
                printf("%s",(i==0)?"+---":"|---");
            }
            printf("%s",(i==0)?"+\n":"|\n");

            //linea
            for(int j=0; j<size; j++){
                if(matriz[i][j] < 0){
                    cout << "|   " << ends;
                }else if(matriz[i][j]>=0 && matriz[i][j]<11){
                    cout << "| " << matriz[i][j] << " " << ends;
                }else if(matriz[i][j] == 12){
                    cout << "| X " << ends; //marca posible mina
                }else if(matriz[i][j] == 11){
                    cout << "| # " << ends; //pisa mina
                }
            }
            cout << "| " << i+1 << endl;

            //parte inferior
            if(i==size-1){
                for(int j=0; j<size; j++){
                    printf("%s","+---");
                }
                printf("%s","+\n");
            }
        }
   
        //PIDE ENTRADA
        while(filaSeleccionada>size || filaSeleccionada<1){
            cout << "- Ingrese fila de la casilla\n  $ " << ends;
            cin >> filaSeleccionada;
            if(filaSeleccionada>size || filaSeleccionada<1){
                cout << "Fila ingresada invalida" << endl;
            }
        }
        filaSeleccionada--;
        
        while(columnaSeleccionada>size || columnaSeleccionada<1){
            cout << "- Ingrese columna de la casilla\n  $ " << ends;
            cin >> columnaSeleccionada;
            if(columnaSeleccionada>size || columnaSeleccionada<1){
                cout << "Columna ingresada invalida" << endl;
            }
        }
        columnaSeleccionada--;

        while(opcionSeleccionada>3 || opcionSeleccionada<1){
            cout << "- Desea pisar(1), marcar(2) o demarcar(3)?\n  $ " << ends;
            cin >> opcionSeleccionada;
            if(opcionSeleccionada>3 || opcionSeleccionada<1){
                cout << "Opcion ingresada invalida" << endl;
            }
        }

        //SI PISA UNA CASILLA DE CERO, MUESTRA LAS OTRAS CASILLAS
        if(matriz[filaSeleccionada][columnaSeleccionada] == -10){
            matriz[filaSeleccionada][columnaSeleccionada] = 0;
            modificarTablero(filaSeleccionada, columnaSeleccionada, size);
        }

        //SI PISA UNA MINA PIERDE Y SALE
        if(matriz[filaSeleccionada][columnaSeleccionada] == -11 && opcionSeleccionada == 1){
            matriz[filaSeleccionada][columnaSeleccionada] = 11;
            estado = "perder";
            break;
        }

        //SI PISA UN NUMERO LO MUESTRA
        if(matriz[filaSeleccionada][columnaSeleccionada] >-10 && matriz[filaSeleccionada][columnaSeleccionada] <0 && opcionSeleccionada == 1){
            matriz[filaSeleccionada][columnaSeleccionada] *= -1;
        }

        //SI MARCA CASILLA, GUARDA SU VALOR ORIGINAL Y MUESTRA X
    
        //SI DESMARCA RECUPERA SU VALOR ORIGINAL NO MUESTRA

        //SI TODAS LAS CASILLAS SON MAYORES QUE CERO (si todas estan visibles o marcadas) GANA Y SALE
        estado = "ganar";
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(matriz[i][j]<0){
                    estado = "continuar";
                }
            }
        }
    }

    //IMPRIME TABLERO FINAL (muestra todas las minas)
    for(int i=0; i<size; i++){
        //parte superior de la linea
        if(i==0){
            for(int j=0; j<size; j++){
                printf("%4d", j+1);
            }
            cout << "" << endl;
        }
        for(int j=0; j<size; j++){
            printf("%s",(i==0)?"+---":"|---");
        }
        printf("%s",(i==0)?"+\n":"|\n");

        //linea
        for(int j=0; j<size; j++){
            if(matriz[i][j] < 0 && matriz[i][j] != -11){
                cout << "|   " << ends;
            }else if(matriz[i][j]>=0 && matriz[i][j]<11){
                cout << "| " << matriz[i][j] << " " << ends;
            }else if(matriz[i][j] == 12){
                cout << "| X " << ends;
            }else if(matriz[i][j] == 11 || matriz[i][j] == -11){
                cout << "| # " << ends;
            }
        }
        cout << "| " << i+1 << endl;

        //parte inferior
        if(i==size-1){
            for(int j=0; j<size; j++){
                printf("%s","+---");
            }
            printf("%s","+\n");
        }
    }

    //IMPRIME MENSAJE ADECUADO
    if(estado.compare("perder") == 0){
        cout << "Usted ha pisado una mina, ha perdido."<< endl;
    }
    if(estado.compare("ganar") == 0){
        cout << "Usted ha descubierto las posiciones de las minas, ha ganado."<< endl;
    }

}


void modificarTablero(int filaSeleccionada, int columnaSeleccionada, int size){
    //busca hacia la izquierda
    if(columnaSeleccionada>0){
        for(int j=columnaSeleccionada-1; j>=0; j--){
            if(matriz[filaSeleccionada][j] == -10){
                matriz[filaSeleccionada][j] = 0;
                modificarTablero(filaSeleccionada, j, size);
            }else{
                matriz[filaSeleccionada][j] *= -1;
                break;
            }
        }
    }
    //busca hacia la derecha
    if(columnaSeleccionada<size-1){
        for(int j=columnaSeleccionada+1; j<size; j++){
            if(matriz[filaSeleccionada][j] == -10){
                matriz[filaSeleccionada][j] = 0;
                modificarTablero(filaSeleccionada, j, size);
            }else{
                matriz[filaSeleccionada][j] *= -1;
                break;
            }
        }
    }
    //busca hacia arriba
    if(filaSeleccionada>0){
        for(int i=filaSeleccionada-1; i>=0; i--){
            if(matriz[i][columnaSeleccionada] == -10){
                matriz[i][columnaSeleccionada] = 0;
                modificarTablero(i, columnaSeleccionada, size);
            }else{
                matriz[i][columnaSeleccionada] *= -1;
                break;
            }
        }
    }
    //busca hacia abajo
    if(filaSeleccionada<size-1){
        for(int i=filaSeleccionada+1; i<size; i++){
            if(matriz[i][columnaSeleccionada] == -10){
                matriz[i][columnaSeleccionada] = 0;
                modificarTablero(i, columnaSeleccionada, size);
            }else{
                matriz[i][columnaSeleccionada] *= -1;
                break;
            }
        }
    }
}
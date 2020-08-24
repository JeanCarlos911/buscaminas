# include <iostream>

using namespace std;

int main(){
    int size;

    cout << "\n"
            "      ____                                  _                 \n"
            "     / __ )__  ________________ _____ ___  (_)___  ____ ______\n"
            "    / __  / / / / ___/ ___/ __ `/ __ `__ \\/ / __ \\/ __ `/ ___/\n"
            "   / /_/ / /_/ (__  ) /__/ /_/ / / / / / / / / / / /_/ (__  ) \n"
            "  /_____/\\__,_/____/\\___/\\__,_/_/ /_/ /_/_/_/ /_/\\__,_/____/  \n"
            "                                                              \n" << endl;

    cout << "- Cuanto mide cada lado de la matriz?\n  $ " << ends;
    cin >> size;

    int matriz[size][size];
    int minas = 3 * size;

    cout << "La cantidad de minas es: " << minas << endl;
    
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

    //EMPIEZA EL JUEGO
    String estado = "continuar";

    while(true){
        //MUESTRA TABLERO 
        for(int i=0; i<size; i++){
            //parte superior de la linea
            for(int j=0; j<size; j++){
                printf("%s",(i==0)?"+---":"|---");
            }
            printf("%s",(i==0)?"+\n":"|\n");

            //linea
            for(int j=0; j<size; j++){
                String valor= " ";
                switch(matriz[i][j]){
                    case 12:
                        valor = "X";//casilla marcada
                        break;
                    case 11:
                        valor = "#";//piso mina
                        break;
                }
                if(matriz[i][j]<11 && matriz[i][j]>=0){
                    valor = String.format("%d", matriz[i][j]);
                }
                printf("%s%3s", "|", valor);
            }
            cout << "|" << endl;

            //parte inferior
            if(i==size-1){
                for(int j=0; j<size; j++){
                    printf("%s","+---");
                }
                printf("%s","+\n");
            }
        }
   
        //PIDE ENTRADA
        //cout << "Ingrese fila de la casilla" << ends;
        //ingrese columna
        //desea pisar(1),  marcar(2) o demarcar(3)?

        //SI PISA UNA CASILLA DE CERO, MUESTRA LAS OTRAS CASILLAS

        //SI PISA UNA MINA PIERDE Y SALE

        //SI PISA UN NUMERO LO MUESTRA

        //SI TODAS LAS CASILLAS SON MAYORES QUE CERO GANA Y SALE

        //SI MARCA CASILLA, GUARDA SU VALOR ORIGINAL Y MUESTRA X
    
        //SI DESMARCA RECUPERA SU VALOR ORIGINAL NO MUESTRA
    }
    
}

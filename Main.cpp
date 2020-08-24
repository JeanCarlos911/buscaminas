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
    
    //COLOCA MINAS: el cero es vacio, el menos uno es mina
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(minas>0){
                int tipoCasilla = rand() % 2 - 1;
                if(tipoCasilla == -1){
                    minas --;
                }
                matriz[i][j] = tipoCasilla;
            }else{
                matriz[i][j] = 0;
            }
        }
    }

    //IMPRIMIR TABLERO
    for(int i=0; i<size; i++){
        //parte superior de la linea
        for(int j=0; j<size; j++){
            printf("%s",(i==0)?"+---":"|---");
        }
        printf("%s",(i==0)?"+\n":"|\n");

        //linea
        for(int j=0; j<size; j++){
            printf("%s%3d", "|", matriz[i][j]);
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

}
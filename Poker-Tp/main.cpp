#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
*   ESTRUCTURAS UTILIZADAS
*/
 struct Carta{
    int num;
    string palo;
};
struct Jugador{
    string nombre;
    Carta mano[5];
};
/*
*   Definicion de Variables y Vectores Globales
*/
const string Palos[] ={"PICA","TREBOL","DIAMANTE","CORAZON"};
Carta mazo[52];

/*
*   Funcion Crear Mazo con sus respectivos valores y palos
*/
 void CrearMazo(){
     int posCarta=0;
    for(int i=0 ; i<4 ; i++ ){
        for(int j=1 ; j<14 ; j++){

            mazo[posCarta].num=j;
            mazo[posCarta].palo=Palos[i];
            posCarta++;
        }
    }
}
void Mesclar(Carta mazo[52]){
    Carta A;
    int num;
    int num2;
    for(int i=0 ; i<100000 ; i++ ){
       num=rand()%51;
       num2=rand()%51;

       A= mazo[num];
       mazo[num]=mazo[num2];
       mazo[num2]=A;
    }
}
void Repartir(Jugador Jugadores[],int cantJugadores){
    int posMazo=0;

    for(int j=0 ; j<5 ; j++){
        for(int i=0 ; i< cantJugadores ; i++ ){
            Jugadores[i].mano[j]=mazo[posMazo];
            posMazo++;
        }
    }
}
void ImagenCarta(Carta carta){
    cout<<" ------ "<< endl;
    if(carta.palo=="PICA"){
        //cout<<"|"<<"♠"<<"      |"<< endl;
        cout<<"|"<<"P"<<"     |"<< endl;
        }else if(carta.palo=="TREBOL"){
            //cout<<"|"<<"♣"<<"      |"<< endl;
            cout<<"|"<<"T"<<"     |"<< endl;
            }else if(carta.palo=="DIAMANTE"){
                //cout<<"|"<<"♦"<<"      |"<< endl;
                cout<<"|"<<"D"<<"     |"<< endl;
                }else {
                    //cout<<"|"<<"♥"<<"      |"<< endl;
                    cout<<"|"<<"C"<<"     |"<< endl;
    }
    cout<<"|      |"<< endl;
    cout<<"|      |"<< endl;
    if(carta.num==11){
        cout<<"|     "<<"J"<<"|"<< endl;
    }else if(carta.num==12){
        cout<<"|     "<<"Q"<<"|"<< endl;
    }else if(carta.num==13){
        cout<<"|     "<<"k"<<"|"<< endl;
    }else{
        cout<<"|     "<<carta.num<<"|"<< endl;
    }
    cout<<" ------ "<< endl;
}
void MostrarManos(Jugador Jugadores[] ,int cantJugadores){
    Carta cart;
    for(int i=0 ; i< cantJugadores ; i++ ){
        cout << "Jugador " ;
        cout << Jugadores[i].nombre << endl;
        for(int j=0 ; j<5 ; j++){
            cout << "Carta " <<j+1<< endl;
            cart=Jugadores[i].mano[j];
            //cout<< Jugadores[i].mano[j].num << " ";
              //cout<< Jugadores[i].mano[j].palo << endl;
            ImagenCarta(Jugadores[i].mano[j]);
        }
        cout <<endl;
    }
    cout <<"------------------------------------"<<endl;
}

int main()
{
    srand(time(NULL));
    /*
    *   Crear jugadores
    */
   int cantJugadores=2;
    cout << "Ingrese cantidad de jugadores  " << endl;
    cin >>cantJugadores;
    /*
    *   CREAMOS LOS JUGADORES CON SUS NOMBRES
    */
    Jugador jugadores[cantJugadores];
    for(int j=0 ; j<cantJugadores ; j++){
        cout << "Ingrese Nombre de jugador " <<j+1<< endl;
        cin >>jugadores[j].nombre;
    }
    // CANTIDAD DE RONDAS
    int cantRondas=1;
    cout << "Ingrese cantidad de Rondas  " << endl;
    cin >>cantRondas;


    /*
    * CREAMOS EL MAZO Y LO MESCLAMOS
    */
    CrearMazo();
    Mesclar(mazo);
    Repartir(jugadores ,cantJugadores);

   // for(int i=0 ; i<52 ; i++ ){
    //    cout << mazo[i].num << "  "<<mazo[i].palo << "///";
    //}

MostrarManos(jugadores ,cantJugadores );


    return 0;
}

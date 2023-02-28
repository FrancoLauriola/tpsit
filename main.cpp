/*!
\file main.cpp
\brief implementazione del codice main
\author F.Lauriola
\date 27/02/2023
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int n;//! \var numero di partecipanti

/*!
\struct s_snow 
\brief andremo a creare la struttura
*/
struct s_snow
{
    int matricola;//! \var matricola
                  //! \brief numero della matricola dell'atleta
    string cognome;//! \var cognome
    //! \brief cognome dell'atleta
    int kmt;//! \var kmt
    //! \brief kilometri percorsi dall'atleti
    int x[30];//! \var x
    //! \brief coordinata(x)
    int y[30];//! \var y
    //! \brief coordinata(y)
} vet_snow [10];

/*!
\fn geneta
\brief generazione delle coordinate
\param[in] snowborder 
\return distanza percorsa dall'atleta
*/
int genera(int snowboarder)
{
    int x1=0,y1=0,x=0,y=0,dist1=0,dist=0,giri=0;
    giri=rand()%5+25;
    
    for(int i=0; i<giri; i++)
    {
        x=rand()%100;
        y=rand()%100;
        vet_snow[snowboarder].x[i] = x;
        vet_snow[snowboarder].y[i] = y;
        
        dist1=sqrt((pow(x,2)-pow(x1,2))+(pow(y,2)-pow(y1,2)));
        x1=x;
        y1=y;
        dist=dist+dist1;
    }
    
    return dist; 
}

/*!
\fn gara
\brief generazione della gara 


*/
void gara()
{
    int dista=0;
    
    cout<<"Quanti partecipanti si vuole far gareggiare? "<<endl;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        vet_snow[i].matricola=i+1;
        
        cout<<"Inserire cognome partecipante "<< i+1 << " " << endl;
        cin>>vet_snow[i].cognome;
        
        vet_snow[i].kmt=genera(i);
    }
}

/*!
\fn stampaSuFile
\brief stampa matricole,cognomi,e le coordinate su un file
*/
void stampaSuFile(){
    //apertura file
    ofstream fout("gara.txt");
    
    for(int i=0; i< n; i++)
    {
        //scrittura su file
        fout << std::to_string(vet_snow[i].matricola) + "\t"+ vet_snow[i].cognome;
        
        for (int j=0; j<30; j++){
            fout << "\t(" << vet_snow[i].x[j] << "," << vet_snow[i].y[j] << ")";
        }
        fout << endl;
        cout << std::to_string(vet_snow[i].matricola) +"\t"+ vet_snow[i].cognome + "\t" << endl;
    }
    
    //chiusura file
    fout.close();
}

/*!
\fn calcolaPodioEVisualizza
\brief calcola il podio con vari for 
*/
void calcolaPodioEVisualizza(){
  
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++) {
            if(vet_snow[i].kmt < vet_snow[j].kmt){
                s_snow app = vet_snow[j];
                vet_snow[j] = vet_snow[i];
                vet_snow[i] = app;
            }
        }
    }
    
    for (int i=0; i<min(n,3);i++){
        int posizione = i+1;
        cout << "Posizione " << std::to_string(posizione) << " - " << vet_snow[i].matricola << " "<< vet_snow[i].cognome << " "<< vet_snow[i].kmt<<endl;
    }
}

/*
\fn main 
\brief infine c'è il main dove andiamo a richiamare le varie funzioni
*/
int main()
{
    srand (time(0));

    int scelta;
        do 
        {
            cout<<"===== MENU ====="<<endl;
            cout<<"1) Genera gara"<<endl;
            cout<<"2) Visualizza risultato"<<endl;
            cout<<"3) Stampa su file "<<endl;
            cout<<"4) USCITA "<<endl;
            cout<<"Inserire una scelta: "<<endl;
            cin>>scelta;
            
            switch(scelta){
                case 1:
                    gara();
                    break;
                case 2:
                    calcolaPodioEVisualizza();
                    break;
                case 3:
                    stampaSuFile();
                    break;
            }

        }while(scelta!=4);
    return 0;
}

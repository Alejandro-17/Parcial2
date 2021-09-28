#include <iostream>
#include <QImage>
#include <vector>
#include <QColor>
#include <string>
#include <QRgb>

using namespace std;

void submuestreo(string filename);
int main()
{
    string filename = "../Parcial2/images/colombia.jpg";
  // QImage im(filename.c_str());


    submuestreo(filename);
    return 0;
}

void submuestreo(string filename){
    QImage im(filename.c_str());
    int ancho=im.width(), alto=im.height();

    int limiteX=0,limiteY=0,iterador=0,iterador1=0; // limiteX-Y me ayudan a interactuar con los limites de la imganen. iterador 0-1 me ayudan a recorrer la nueva matriz de apuntadores
    short int Rpromedio=0, Gpromedio=0, Bpromedio=0; // para guadar el promedio de intensidad de cada canal


    // Reservo espacio para una matriz de punteros a QRgb
    QRgb **pix=NULL;

    pix= new QRgb*[alto/4];
    for (int i=0; i<(alto/4);++i){
        pix[i]= new QRgb[ancho/4];
    }


    //submuestreo la imagen original en una relacion 4:4 a 1 pixel, es decir
    //promedio la intensidad RGB de 16 pixeles en  1
    while( limiteY< im.height()){
    int sumR=0,sumG=0,sumB=0,cont=0;

    for (int indy=limiteY; indy<limiteY+4; ++indy){ //itero sobre las columnas
     if(indy<alto){
     for(int indx=limiteX; indx<limiteX+4 ; ++indx){ //itero sobre las filas
     if(indx<ancho){
     sumR= sumR + im.pixelColor(indx,indy).red();   //guardo la intesidad de canal rojo de cada pixel sobre el que itero
     sumG = sumG + im.pixelColor(indx,indy).green(); //......... verde.........
     sumB= sumB + im.pixelColor(indx,indy).blue();
     cont+=1; // me ayuda a promediar las sumas de vectores
    }
    }
    }
    }

    Rpromedio= sumR / cont; //promedio canal rojo
    Gpromedio= sumG / cont; //promedio canal verde
    Bpromedio= sumB /cont; // .............. azul

    // Agrego cada nuevo pixel a mi matriz de pixeles submuestreados
    for(int i=iterador;i<iterador+1;i++){
        if(i<(alto/4)){
        for(int j=iterador1;j<(iterador1+1);j++ ){
        if(j<(ancho/4)){
        pix[i][j]= qRgb(Rpromedio,Gpromedio,Bpromedio);
    cout<<qRed(pix[i][j])<<": " <<qGreen(pix[i][j])<<": " <<qBlue(pix[i][j])<<": "<<i<<":"<<j<<endl;
    }
    }
    }
    }

    iterador1+=1;



    limiteX+=4;
    if(limiteX>=im.width()){
        limiteX=0;
        limiteY+=4;
        iterador+=1;
        iterador1=0;}
    }

    alto=alto/4;
    ancho=ancho/4;

   if(ancho>=20){
        if(alto>=20){
            limiteX=0,limiteY=0,iterador=0,iterador1=0;
            Rpromedio=0, Gpromedio=0, Bpromedio=0;
            QRgb **pix1=NULL;
            pix1= new QRgb*[alto/4];
            for (int i=0; i<(alto/4);++i){
                pix1[i]= new QRgb[ancho/4];
            }

            while( limiteY< alto){
            int sumR=0,sumG=0,sumB=0,cont=0;

            for (int indy=limiteY; indy<limiteY+4; ++indy){
             if(indy<alto){
             for(int indx=limiteX; indx<limiteX+4 ; ++indx){
             if(indx<ancho){
             sumR= sumR + qRed(pix[indy][indx]);
             sumG = sumG + qGreen(pix[indy][indx]);
             sumB= sumB + qBlue(pix[indy][indx]);
             cont+=1;
            }
            }
            }
            }
            Rpromedio= sumR / cont;
            Gpromedio= sumG / cont;
            Bpromedio= sumB /cont;

            for(int i=iterador;i<iterador+1;i++){
                if(i<(alto/4)){
                for(int j=iterador1;j<(iterador1+1);j++ ){
                if(j<(ancho/4)){
                pix1[i][j]= qRgb(Rpromedio,Gpromedio,Bpromedio);
            cout<<qRed(pix1[i][j])<<": " <<qGreen(pix1[i][j])<<": " <<qBlue(pix1[i][j])<<": "<<i<<":"<<j<<endl;
            }
            }
            }
            }
            iterador1+=1;
            limiteX+=4;
            if(limiteX>=ancho){
                limiteX=0;
                limiteY+=4;
                iterador+=1;
                iterador1=0;}
            }

            for (int i=0; i<(im.height()/4); ++i){
                delete [] *(pix+i);
            }
            delete [] pix;

            //Elimino espacio reservado por el pixel1
            for (int i=0; i<(alto/4); ++i){
                delete [] *(pix1+i);
            }
            delete [] pix1;
        }

    }
    for (int i=0; i<(im.height()/4); ++i){
        delete [] *(pix+i);
    }
    delete [] pix;



}


#include <iostream>
#include <QImage>
#include <vector>
#include <QColor>
#include <string>

using namespace std;


int main()
{
    string filename = "../Parcial2/images/brasil.jpg";
    QImage im(filename.c_str());
/*
    unsigned int pixelX=200;
    unsigned int pixelY=200;
    cout<<"Intensidad de color rojo del pixel seleccionado es: "<< im.pixelColor(pixelX,pixelY).red()<<endl;
    cout<<"Intensidad de color verde del pixel seleccionado es: "<< im.pixelColor(pixelX,pixelY).green()<<endl;
    cout<<"Intensidad de color azul del pixel seleccionado es: "<< im.pixelColor(pixelX,pixelY).blue()<<endl;
    cout<<"Formato de la imagen es: "<< im.format()<<endl;
*/
    ///////////////////////////////////////////////////////////////// Adelanto
       vector <QColor> pix1;
       int limiteX=0,limiteY=0;
       short int Rpromedio=0, Gpromedio=0, Bpromedio=0;
       //submuestreo la imagen original en una relacion 4:4 a 1 pixel, es decir
       //promedio la intensidad RGB de 16 pixeles en  1
       while( limiteY< im.height()){
       int sumR=0,sumG=0,sumB=0;
       for (int indy=limiteY; indy<limiteY+4; ++indy){
       for(int indx=limiteX; indx<limiteX+4 ; ++indx){
        sumR= sumR + im.pixelColor(indx,indy).red();
        sumG = sumG + im.pixelColor(indx,indy).green();
        sumB= sumB + im.pixelColor(indx,indy).blue();
      }
    }
       Rpromedio= sumR / 16;
       Gpromedio= sumG / 16;
       Bpromedio= sumB /16;
       pix1.push_back(QColor(Rpromedio,Gpromedio,Bpromedio));
       limiteX+=4;
       if(limiteX>=im.width()){
           limiteX=0;
           limiteY+=4;}
      // for(auto var:pix1){
        //   cout<<var.green()<<endl;
      // }

        }
        cout<<"el tamano del vector es: "<<pix1.size()<<" La capacidad del vector es: "<< pix1.capacity()<<endl;

        return 0;
}

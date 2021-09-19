#include <iostream>
#include <QImage>
#include <string>

using namespace std;


int main()
{
    string filename = "../Parcial2/images/colombia.jpg";
    QImage im(filename.c_str());

    unsigned int pixelX=200;
    unsigned int pixelY=200;
    cout<<"Intensidad de color rojo del pixel seleccionado es: "<< im.pixelColor(pixelX,pixelY).red()<<endl;
    cout<<"Intensidad de color verde del pixel seleccionado es: "<< im.pixelColor(pixelX,pixelY).green()<<endl;
    cout<<"Intensidad de color azul del pixel seleccionado es: "<< im.pixelColor(pixelX,pixelY).blue()<<endl;

   for (int indx=0; indx<im.width() ; ++indx){
       for(int indy=0; indy<im.height(); ++indy){
           cout<< indx << ","<< indy << "="<<im.pixelColor(indx,indy).red()<<endl;
       }
   }

    return 0;
}

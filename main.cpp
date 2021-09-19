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


    return 0;
}

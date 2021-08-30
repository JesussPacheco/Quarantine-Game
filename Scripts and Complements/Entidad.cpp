#include "Entidad.h"
#include<iostream>
int  Entidad:: getX() { return x; }
int  Entidad:: getY() { return y; }
int  Entidad:: getDX() { return dx; }
int  Entidad:: getDY() { return dy; }
int  Entidad:: getAncho() { return ancho; }
int  Entidad:: getAlto() { return alto; }
int  Entidad:: getColumna() { return columna; }
Rectangle Entidad::getArea(){return area;}
Rectangle Entidad::getContorno() { return contorno;}

void Entidad:: setX(int n) { x = n; }
void Entidad:: setY(int n) { y = n; }
void Entidad:: setDX(int n) { dx = n; }
void Entidad:: setDY(int n) { dy = n; }
void Entidad:: setAncho(int n) { ancho = n; }
void Entidad:: setAlto(int n) { alto = n; }
void Entidad:: setColumna(int n) { columna = n; }
void Entidad::setImg(Bitmap^n) { img = n; }
void Entidad::setArea(Rectangle n) { area = n; }
void Entidad::setContorno(Rectangle n) { contorno = n; }
void Entidad::setAccion(Accion n) { accion = n; }
Accion Entidad::getAccion() {return accion;}
String^ Entidad:: getFoto() {
	return foto;
}
void Entidad::setFoto(String^n) {
	foto = n;
}
 
#pragma once
enum Accion {
	hechizoArr, hechizoIzq, hechizoAba, hechizoDer, empujeArr, empujeIzq, empujeAba, empujeDer, caminarArr, caminarIzq, caminarAba, caminarDer, burlaArr, burlaIzq, burlaAba, burlaDer, disparoArr, disparoIzq, disparoAba, disparoDer, muerto
};
using namespace System;
using namespace System::Drawing;


ref class Entidad
{
protected:

	int x, y;
	int dx, dy;
	int ancho, alto;
	int columna;
	double escala;
	Bitmap^img;
	Rectangle area;
	Rectangle contorno;
	Accion accion;
	String^foto;

public:
	int   getX();
	int   getY();
	int   getDX();
	int   getDY();
	int   getAncho();
	int   getAlto();
	int   getColumna();
	Rectangle getArea();
	Rectangle getContorno();
	void  setX(int n);
	void  setY(int n);
	void  setDX(int n);
	void  setDY(int n);
	void  setAncho(int n);
	void  setAlto(int n);
	void  setColumna(int n);
	void  setImg(Bitmap^n);
	void  setArea(Rectangle n);
	void setContorno(Rectangle n);
	void setAccion(Accion n);
	Accion getAccion();
	String^ getFoto();
	void setFoto(String^n);
};
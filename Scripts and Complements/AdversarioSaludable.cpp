#include "AdversarioSaludable.h"
#include<iostream>
AdversarioSaludable::AdversarioSaludable() :Entidad()
{
	img = gcnew Bitmap("Imagenes\\Personajes\\zAdversarioSaludable.png");
	Random r;
	x = r.Next(200, 700); System::Threading::Thread::Sleep(10);
	y = r.Next(300, 500); System::Threading::Thread::Sleep(10);

	do {
		dx = dy = r.Next(-5, 10); System::Threading::Thread::Sleep(10);
	} while (dx == 0);
	columna = 8;
	accion = caminarDer;;
	escala = 1.2;
	ancho = img->Width / 13;
	alto = img->Height / 21;

}
void AdversarioSaludable::Mostrar(Graphics^g) {
	area = Rectangle(x, y, ancho * escala, alto * escala);
	contorno = Rectangle(x + 17, y + 15, ancho - 19, alto - 5);
	Rectangle corte = Rectangle(columna * ancho, accion * alto, ancho, alto);
	g->DrawRectangle(gcnew Pen(Color::Red, 1), contorno);


	g->DrawImage(img, area, corte, GraphicsUnit::Pixel);

	if (accion >= 0 && accion <= 3)
		columna = (columna + 1) % 7;
	else if (accion >= 4 && accion <= 7)
		columna = (columna + 1) % 8;
	else if (accion >= 8 && accion <= 11)
		columna = (columna + 1) % 9;
	else if (accion >= 12 && accion <= 15)
		columna = (columna + 1) % 6;
	else if (accion >= 16 && accion <= 19)
		columna = (columna + 1) % 13;
	else if (accion == 20)
		columna = (columna + 1) % 6;
}


void AdversarioSaludable::Mover(Graphics^g) {
	x += dx;
	if (x + dx < 0) {
		accion = caminarDer;
		dx *= -1;
		std::cout << getAccion() << std::endl;

		std::cout << getAccion() << std::endl;
	}
	if (x + ancho + dx >= g->VisibleClipBounds.Right) {
		accion = caminarIzq;
		dx *= -1;
		std::cout << getAccion() << std::endl;
		//	setAccion(caminarIzq);
		std::cout << getAccion() << std::endl;
	}
	//std::cout << getAccion() << std::endl;
}
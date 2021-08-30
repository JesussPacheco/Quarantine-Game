
#include "AdversarioAsintomatico.h"
#include<iostream>
AdversarioAsintomatico::AdversarioAsintomatico() :Entidad()
{
	balas = gcnew ArregloBalas();
	img = gcnew Bitmap("Imagenes\\Personajes\\zAdversarioAsintomatico.png");
	Random r;
	x = r.Next(200, 700); System::Threading::Thread::Sleep(10);
	y = r.Next(250, 600); System::Threading::Thread::Sleep(10);
	do {
		dx = dy = r.Next(-5, 10); System::Threading::Thread::Sleep(10);
	} while (dx == 0);
	columna;
	accion = caminarDer;
	escala = 1.2;
	ancho = img->Width / 13;
	alto = img->Height / 21;

}
void AdversarioAsintomatico::Mostrar(Graphics^g) {
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
void AdversarioAsintomatico::Mover(Graphics^g,int _x,int _y) {
	if (rand() % 100 == 0)
	Disparar(_x, _y);
	x += dx;
	y += dy;
	if (x + dx < 0) {
		accion = caminarDer;
		dx *= -1;
		std::cout << accion << "PORQUE" << std::endl;
		std::cout << "Instante" << accion << accion << std::endl;
	}
	if (x + ancho + dx >= g->VisibleClipBounds.Right) {
		accion = caminarIzq;
		dx *= -1;
		std::cout << accion << "CHUCHA" << std::endl;
		std::cout << "Instante" << accion << accion << std::endl;
	}
	if (y + dy < 200) {
		accion = caminarAba;
		dy *= -1;


		std::cout << accion << "NOCAMIBAS" << std::endl;
		std::cout << "Instante" << accion << accion << std::endl;
	}

		if (y + alto + dy >= g->VisibleClipBounds.Bottom) {
			dy *= -1;
			accion = caminarArr;
			std::cout << accion << "CTMR" << std::endl;
			std::cout << "Instante" << accion << accion << std::endl;

		}
		std::cout << "ACCION ACTUAL:" << accion << std::endl;
	}
	//std::cout << getAccion() << std::endl;
void AdversarioAsintomatico::MoverBalas() {
	balas->moverBalas();
}
void AdversarioAsintomatico::MostrarBalas(Graphics^g) {
	balas->mostrarBalas(g);
}
void AdversarioAsintomatico::Disparar(int x, int y) {
	balas->Agregar(gcnew Balas(this->x, this->y, x,y,false));
}
ArregloBalas^AdversarioAsintomatico::getBalas() {
	return balas;
}
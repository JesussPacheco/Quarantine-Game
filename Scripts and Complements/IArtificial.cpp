#include "IArtificial.h"
IArtificial::IArtificial(Tipo _nice)
{
	if (_nice == policia) {
		img = gcnew Bitmap("Imagenes\\Personajes\\Policia.png");
		dx = dy = 20;
	}
	else if (_nice == medice) {
		img = gcnew Bitmap("Imagenes\\Personajes\\Medico.png");
		dx = dy = 20;
	}
	else {
		img = gcnew Bitmap("Imagenes\\Personajes\\choro.png");
		dx = dy = 6;
}
	Random j;
	x = j.Next(100, 500);
	System::Threading::Thread::Sleep(10);
	y = j.Next(200, 500);
	System::Threading::Thread::Sleep(10);
	columna = 0;
	accion = caminarAba;
	escala = 1.2;
	ancho = img->Width / 13;
	alto = img->Height / 21;
}
void IArtificial::Mostrar(Graphics ^g)
{
	area = Rectangle(x, y, ancho * escala, alto * escala);
	contorno = Rectangle(x + 17, y + 15, ancho - 19, alto - 5);
	Rectangle corte = Rectangle(columna * ancho, accion * alto, ancho, alto);
	g->DrawImage(img, area, corte, GraphicsUnit::Pixel);
	g->DrawRectangle(gcnew Pen(Color::Red, 1), contorno);
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
	if (dx == 0 && dy == 0 && accion >= 8 && accion <= 11)
		columna = 0;
}
void IArtificial::Mover(Graphics^g) {
	switch (accion)
	{
	case Accion::caminarArr:
		if (y - dy > 0)
			y -= dy;
		break;
	case Accion::caminarAba:
		if (y + alto + dy < g->VisibleClipBounds.Bottom)
			y += dy;
		break;
	case Accion::caminarIzq:
		if (x - dx > 0)
			x -= dx;
		break;
	case Accion::caminarDer:
		if (x + ancho + dx < g->VisibleClipBounds.Right)
			x += dx;
		break;
	}
}

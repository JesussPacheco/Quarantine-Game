#include "Jugador.h"
Jugador::Jugador() :Entidad()
{
	img = gcnew Bitmap("Imagenes\\Personajes\\zJugador.png");
	x = y = 300;
	dx = dy = 0;
	columna = 3;
	accion = caminarAba;
	escala = 1.2;
	ancho = img->Width / 13;
	alto = img->Height / 21;
	balas = gcnew ArregloBalas();

}
void Jugador::moverBalas() {
	balas->moverBalas();
}

void  Jugador::Mostrar(Graphics^g)
{
	area = Rectangle(x, y, ancho * escala, alto * escala);
	contorno = Rectangle(x + 17, y + 15, ancho - 19, alto - 5);
	Rectangle corte = Rectangle(columna * ancho, accion * alto, ancho, alto);
	g->DrawImage(img, area, corte, GraphicsUnit::Pixel);
//	g->DrawRectangle(gcnew Pen(Color::Yellow, 1), contorno);

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
	if (columna == 0)
	{
		if (accion == disparoAba)
			accion = caminarAba;
		else if (accion == disparoArr)
			accion = caminarArr;
		else if (accion == disparoIzq)
			accion = caminarIzq;
		else if (accion == disparoDer)
			accion = caminarDer;
	}
	balas->mostrarBalas(g);
}


void Jugador::Mover(Graphics^g) {
	if (x + dx > 0 && x + ancho + dx <= g->VisibleClipBounds.Right&&y + dy >200 && y + alto + dy <= g->VisibleClipBounds.Bottom) {
		x += dx;
		y += dy;
	}
}
void Jugador::Disparar(int x,int y) {
	Balas^bala;
	int v = 50;
	if (accion == disparoArr)
		bala = gcnew Balas(this->x + 30,this-> y + 30, x,y,true);
	else if (accion == disparoAba)			 
		bala = gcnew Balas(this->x + 30, this->y + 30, x,y,true );
	else if (accion == disparoIzq)			 
		bala = gcnew Balas(this->x + 30, this->y + 30, x,y,true );
	else if (accion == disparoDer)			 
		bala = gcnew Balas(this->x + 30,this->y + 30, x,y,true );
	balas->Agregar(bala);
}
ArregloBalas^Jugador::getBalas() {
	return balas;
}


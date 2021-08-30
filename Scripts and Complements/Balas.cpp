#include "Balas.h"
#include<iostream>
Balas::Balas(int x, int y, int fx, int fy,bool diferencia)
{   
	img = gcnew Bitmap("Imagenes\\Personajes\\covid.png");
	this->diferencia = diferencia;
	this->x = x;
	this->y = y;
	Random r;
	switch (r.Next(0, 4))
	{
	case 0:mensaje = "   \n ¡Quedate\n  en tu\n  casa!"; break;
	case 1:mensaje = "   \n ¡Usa \n     mascarilla!"; break;
	case 2:mensaje = "   \n ¡Lavate \n  las\n manos¡"; break;
	case 3:mensaje = "   \n ¡Manten \nel metro\nde distancia"; break;
	}
	System::Threading::Thread::Sleep(10);
	double V = 30;
	double c1 = fx - x;
	double c2 = fy - y;
	double h = Math::Sqrt(c1*c1 + c2*c2);
	double C = V / h;
	dx = c1*C;
	dy = c2*C;
	ancho = alto = 10;
	escala = 6.4;
}
void Balas::Mostrar(Graphics^ g)
{
	area = Rectangle(x, y, ancho * escala, alto * escala);
	contorno = Rectangle(x + 17, y + 15, ancho - 19, alto - 5);
	if (diferencia) {
		g->DrawRectangle(gcnew Pen(Color::Red, 1), area);
		g->FillEllipse(Brushes::Black, area);
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial Rounded MT", 8,System::Drawing::FontStyle::Bold);
		g->DrawString(mensaje, f, Brushes::White, area);
	}
	else g->DrawImage(img,area);
}
void Balas::Mover() {
	x += dx;
	y += dy;
}

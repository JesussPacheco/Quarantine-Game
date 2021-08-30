#include"ArregloBalas.h"
#pragma once
#include"Entidad.h"

ref class AdversarioAsintomatico :public Entidad
{
	Accion accion;
	ArregloBalas^balas;
public:
	AdversarioAsintomatico();
	void Mover(Graphics^g,int x,int y);
	void  MoverBalas();
	void MostrarBalas(Graphics^g);
	void Disparar(int x,int y);
	void Mostrar(Graphics^g);
	ArregloBalas^getBalas();
};


#pragma once
#include"Entidad.h"
#include"ArregloBalas.h"

ref class Jugador :public Entidad
{
	ArregloBalas^balas;
public:
	Jugador();
	void Mover(Graphics^g);
	void moverBalas();
	void Disparar(int x,int y);
	ArregloBalas^getBalas();
	void  Mostrar(Graphics^g);
};



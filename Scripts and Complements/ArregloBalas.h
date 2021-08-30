#pragma once
#include"Balas.h"
ref class ArregloBalas
{
	array<Balas^>^arreglo;

public:
	ArregloBalas();
	~ArregloBalas();
	void Agregar(Balas^ element);
	void Eliminar(int pos);

	Balas^getBala(int pos);
	int getCant();
	void mostrarBalas(Graphics^g);
	void moverBalas();
	array<Balas^>^ getArr();
};


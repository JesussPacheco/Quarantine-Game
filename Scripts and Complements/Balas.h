#pragma once
#include "Entidad.h"
ref class Balas : public Entidad
{
	String^mensaje;
	bool diferencia;
public:
	Balas(int x, int y, int dx, int dy,bool diferencia);
	void Mover();
	void Mostrar(Graphics^g);
};
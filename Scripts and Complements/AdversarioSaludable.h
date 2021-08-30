#pragma once
#include"Entidad.h"

ref class AdversarioSaludable :public Entidad
{

	Accion accion;
public:
	AdversarioSaludable();
	void Mover(Graphics^g);
	void Mostrar(Graphics^g);
};
#pragma once
#include"AdversarioSaludable.h"
ref class ArregloSaludables
{
	array<AdversarioSaludable^>^arr;
public:

	ArregloSaludables();
	void Agregar();
	void Eliminar(int pos);
	array<AdversarioSaludable^>^getArr();

};


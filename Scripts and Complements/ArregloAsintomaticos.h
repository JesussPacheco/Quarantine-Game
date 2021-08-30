#pragma once
#include "AdversarioAsintomatico.h"
ref class ArregloAsintomaticos 

{
	array<AdversarioAsintomatico^>^arr;
public:
	ArregloAsintomaticos();
	void Agregar();
	void Eliminar(int pos);
	array<AdversarioAsintomatico^>^getArr();
};


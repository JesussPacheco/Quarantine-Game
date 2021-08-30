#pragma once
#include "Entidad.h"
enum Tipo{policia,medice,ratero};
ref class IArtificial:public Entidad
{
public:
	IArtificial(Tipo nice);
	void Mover(Graphics^g);
	void Mostrar(Graphics^g);
};


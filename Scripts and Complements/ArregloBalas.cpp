#include "ArregloBalas.h"
ArregloBalas::ArregloBalas()
{
	arreglo = gcnew array<Balas^>{};
}

ArregloBalas::~ArregloBalas()
{
}
void ArregloBalas::Agregar(Balas^ element)
{
	array<Balas^>^ T = gcnew array<Balas^>(arreglo->Length + 1);

	for (int i = 0; i < arreglo->Length; i++)
		T[i] = arreglo[i];

	T[arreglo->Length] = element;

	arreglo = T;
}
void ArregloBalas::Eliminar(int pos)
{
	array<Balas^>^ T = gcnew array<Balas^>(arreglo->Length - 1);

	for (int i = 0; i <pos; i++)
		T[i] = arreglo[i];

	for (int i = pos; i <arreglo->Length - 1; i++)
		T[i] = arreglo[i + 1];

	arreglo = T;
}
Balas^ ArregloBalas::getBala(int pos) {
	return arreglo[pos];
}
int ArregloBalas::getCant()
{
	return (int)arreglo->Length;
}
void ArregloBalas::mostrarBalas(Graphics^g) {
	for (int i = 0; i < arreglo->Length; i++)
		arreglo[i]->Mostrar(g);

}
void ArregloBalas::moverBalas() {
	for (int i = 0; i < arreglo->Length; i++)
		arreglo[i]->Mover();
}
array<Balas^>^ ArregloBalas::getArr() {
	return arreglo;
}



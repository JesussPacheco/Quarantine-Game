#include "ArregloSaludables.h"



ArregloSaludables::ArregloSaludables()
{
	arr = gcnew array<AdversarioSaludable^>(1);
}
void ArregloSaludables::Agregar() {
	AdversarioSaludable^aux = gcnew AdversarioSaludable;
	array<AdversarioSaludable^>^ T = gcnew array<AdversarioSaludable^>(arr->Length + 1);

	for (int i = 0; i < arr->Length; i++)
		T[i] = arr[i];

	T[arr->Length] = aux;

	arr = T;
}
void ArregloSaludables::Eliminar(int pos) {
	array<AdversarioSaludable^>^ T = gcnew array<AdversarioSaludable^>(arr->Length - 1);

	for (int i = 0; i <pos; i++)
		T[i] = arr[i];

	for (int i = pos; i <arr->Length - 1; i++)
		T[i] = arr[i + 1];

	arr = T;
}
array<AdversarioSaludable^>^ ArregloSaludables::getArr() {
	return arr;
}
#include "ArregloAsintomaticos.h"



ArregloAsintomaticos::ArregloAsintomaticos()
{
	arr = gcnew array<AdversarioAsintomatico^>(1);
}
void ArregloAsintomaticos::Agregar() {
	AdversarioAsintomatico^aux = gcnew AdversarioAsintomatico;
	array<AdversarioAsintomatico^>^ T = gcnew array<AdversarioAsintomatico^>(arr->Length + 1);
	for (int i = 0; i < arr->Length; i++)
		T[i] = arr[i];
	T[arr->Length] = aux;
	arr = T;
}
void ArregloAsintomaticos::Eliminar(int pos) {
	array<AdversarioAsintomatico^>^ T = gcnew array<AdversarioAsintomatico^>(arr->Length - 1);
	for (int i = 0; i <pos; i++)
		T[i] = arr[i];

	for (int i = pos; i < arr->Length - 1; i++)
		T[i] = arr[i + 1];

	arr = T;
}
array<AdversarioAsintomatico^>^ ArregloAsintomaticos::getArr() {
	return arr;
}
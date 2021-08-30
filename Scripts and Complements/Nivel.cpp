#include "Nivel.h"
#include<iostream>
#include<fstream>

Nivel::Nivel(Jugador^_player)
{
	mapa = gcnew Bitmap("Imagenes\\Mapas\\Lurigancho1.png");
	player = _player;
	police = gcnew IArtificial(policia);
	medico = gcnew IArtificial(medice);
	arraySaludables = gcnew ArregloSaludables();
	arrayAsintomaticos = gcnew ArregloAsintomaticos();
	puntaje = 0;
	Abrir();
	//this->player = player;
}

Nivel::~Nivel()
{
}
void Nivel::mostrarMapa(Graphics^g,int A,int L) {
	g->DrawImage(mapa, 0, 0, A, L);
}
void Nivel::generarSaludables(int n) {

	for (int i = 0; i < n; i++) {
		arraySaludables->getArr()[i] = gcnew AdversarioSaludable();
	}
}
void Nivel::MostrarSaludables(Graphics^g) {
	for (int i = 0; i < arraySaludables->getArr()->Length; i++)
	{
		arraySaludables->getArr()[i]->Mostrar(g);

		//std::cout << i << std::endl;
	}
}


void Nivel::MoverSaludables(Graphics^g) {
	for (int i = 0; i < arraySaludables->getArr()->Length; i++)
		arraySaludables->getArr()[i]->Mover(g);
}
void Nivel::generarAsintomaticos(int n) {
	for (int i = 0; i < n; i++) {
		arrayAsintomaticos->getArr()[i] = gcnew AdversarioAsintomatico();
	}
}
void Nivel::MostrarAsintomaticos(Graphics^g) {
	for (int i = 0; i <arrayAsintomaticos->getArr()->Length; i++)
	{
		arrayAsintomaticos->getArr()[i]->Mostrar(g);
		//std::cout << i << std::endl;
	}
}
void Nivel::MoverAsintomaticos(Graphics^g) {
	for (int i = 0; i < arrayAsintomaticos->getArr()->Length; i++) {
		arrayAsintomaticos->getArr()[i]->Mover(g, player->getX(), player->getY());
		arrayAsintomaticos->getArr()[i]->MoverBalas();

	}
}


bool Nivel::ColisionBalas()
{
	for (int i = 0; i < player->getBalas()->getCant(); i++) {
		for (int j = 0; j < arraySaludables->getArr()->Length; j++)
		{
			if (player->getBalas()->getArr()[i]->getArea().IntersectsWith(arraySaludables->getArr()[j]->getContorno()) && arraySaludables->getArr()[j]->getFoto() != "cambio")
			{
				Bitmap^aux = gcnew  Bitmap("Imagenes\\Personajes\\verde.png");
				arraySaludables->getArr()[j]->setImg(aux);
				arraySaludables->getArr()[j]->setFoto("cambio");
				puntaje+=10;
				player->getBalas()->Eliminar(i);
				return true;
			}
		}
		for (int j = 0; j < arrayAsintomaticos->getArr()->Length; j++)
		{
			if (player->getBalas()->getArr()[i]->getArea().IntersectsWith(arrayAsintomaticos->getArr()[j]->getContorno()) && arrayAsintomaticos->getArr()[j]->getFoto() != "cambio")

			{

				Bitmap^aux = gcnew  Bitmap("Imagenes\\Personajes\\rojo.png");
				arrayAsintomaticos->getArr()[j]->setImg(aux);
				arrayAsintomaticos->getArr()[j]->setFoto("cambio");
				puntaje++;
				player->getBalas()->Eliminar(i);
				return true;

			}
		}
	}
}
bool Nivel::ColisionJugador() {
	for (int i = 0; i < arraySaludables->getArr()->Length; i++) {
		if (player->getContorno().IntersectsWith(arraySaludables->getArr()[i]->getContorno())) {
			player->setAccion(muerto);
			return true;
			break;
		}
	}
	for (int i = 0; i < arrayAsintomaticos->getArr()->Length; i++) {
		if (player->getContorno().IntersectsWith(arrayAsintomaticos->getArr()[i]->getContorno())) {
			player->setAccion(muerto);
			return true;
			break;
		}
	}


}
bool Nivel::ColisionPolicia(Graphics^g) {

	if (validedPolice == true) {
		for (int i = 0; i < arraySaludables->getArr()->Length; i++) {
			if (arraySaludables->getArr()[i]->getFoto() == "cambio") {
				std::cout << "Porque no valida!!!" << std::endl;
				indicePolice = i;
				validedPolice = false;
				break;
			}

		}
	}
		if (validedPolice==false&&indicePolice!=-1) {
			if (police->getX() > arraySaludables->getArr()[indicePolice]->getX()) {
				police->setAccion(caminarIzq);                                  
				police->Mover(g);
			}
			else if (police->getX() < arraySaludables->getArr()[indicePolice]->getX()) {
				police->setAccion(caminarDer);
				police->Mover(g);
			}
			if (police->getY() > arraySaludables->getArr()[indicePolice]->getY()) {
				police->setAccion(caminarArr);
				police->Mover(g);
			}
			else if (police->getY() < arraySaludables->getArr()[indicePolice]->getY()) {
				police->setAccion(caminarAba);
				police->Mover(g);
			}

			if (arraySaludables->getArr()[indicePolice]->getContorno().IntersectsWith(police->getContorno())) {
				arraySaludables->Eliminar(indicePolice);
				validedPolice = true;
				indicePolice = -1;
				return true;
			}
		}
	}
bool Nivel::ColisionMedico(Graphics^g) {
	if (validedMedico == true) {
		for (int i = 0; i < arrayAsintomaticos->getArr()->Length; i++) {
			if (arrayAsintomaticos->getArr()[i]->getFoto() == "cambio") {
				std::cout << "Porque no valida!!!" << std::endl;
				indiceMedico = i;
				validedMedico = false;
				break;
			}

		}
	}
	if (validedMedico == false && indiceMedico != -1) {
		std::cout << "ptmr si esntra" << std::endl;
		std::cout << "Esta entrando al wile" << std::endl;
		if (medico->getX() > arrayAsintomaticos->getArr()[indiceMedico]->getX()) {
			medico->setAccion(caminarIzq);
			medico->Mover(g);
		}
		else if (medico->getX() < arrayAsintomaticos->getArr()[indiceMedico]->getX()) {
			medico->setAccion(caminarDer);
			medico->Mover(g);
		}
		if (medico->getY() > arrayAsintomaticos->getArr()[indiceMedico]->getY()) {
			medico->setAccion(caminarArr);
			medico->Mover(g);
		}
		else if (police->getY() < arrayAsintomaticos->getArr()[indiceMedico]->getY()) {
			medico->setAccion(caminarAba);
			medico->Mover(g);
		}

		if (arrayAsintomaticos->getArr()[indiceMedico]->getContorno().IntersectsWith(medico->getContorno())) {
		arrayAsintomaticos->Eliminar(indiceMedico);
			validedMedico = true;
			indiceMedico = -1;
			return true;
		}
	}

}
void Nivel::setMapa(Bitmap^n) {
	mapa = n;
}
int Nivel ::getnmroEnemigos() {
	return nroEnemigos;
}
void Nivel::setNmroEnemigos(int n) {
	nroEnemigos = n;
}


IArtificial^ Nivel::getPolice() {
	return police;
}
IArtificial^Nivel::getMedico() {
	return medico;
}
int  Nivel::getPuntaje() {
	return puntaje;
}
ArregloAsintomaticos ^Nivel::getArrayAsintomaticos() {
	return arrayAsintomaticos;
}
ArregloSaludables^Nivel::getArraySaludables() {
	return arraySaludables;
}
void Nivel::Guardar() {
	/*std::ofstream saveAsintomaticos("saveAsintomaticos.txt");
	saveAsintomaticos << arrayAsintomaticos->getArr()->Length << std::endl;
	for (int i = 0; i < arrayAsintomaticos->getArr()->Length; i++)
		saveAsintomaticos << arrayAsintomaticos->getArr()[i]->getX() << " " << arrayAsintomaticos->getArr()[i]->getY();
	saveAsintomaticos.close();
	std::ofstream saveSaludables("saveSaludables.txt");
	saveSaludables << arraySaludables->getArr()->Length << std::endl;
	for (int i = 0; i < arraySaludables->getArr()->Length; i++)
		saveSaludables << arraySaludables->getArr()[i]->getX() << " " << arraySaludables->getArr()[i]->getY();
	saveSaludables.close();

	std::ofstream saveJugador("saveJugador.txt");
		saveJugador << player->getX() << " " <<player->getY();
		saveJugador.close();*/
}
void Nivel::Abrir() {
	//int x, y;
	//std::ifstream fin("saveAsintomaticos.txt");
	//int cant; fin >> cant;
	//for (int i = 0; i < cant; i++) {
	//	fin >> x >> y;

	//	arrayAsintomaticos->getArr()[i]->setX(x);
	//	arrayAsintomaticos->getArr()[i]->setY(y);
	//}
	//fin.close();
	//std::ifstream prime("saveSaludables.txt");
 //       prime >> cant;
	//for (int i = 0; i < cant; i++) {
	//prime>> x >> y;
	//	arraySaludables->getArr()[i]->setX(x);
	//	arraySaludables->getArr()[i]->setY(y);
	//}
	//prime.close();
	//std::ifstream one("saveJugador.txt");
	//one >> x;
	//one >> y;
	//player->setX(x);
	//player->setY(y);
	//one.close();
}

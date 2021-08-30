#include "Hard.h"
#include<iostream>
Hard::Hard(Jugador^_player):Nivel(_player){
	choro = gcnew IArtificial(ratero);
	generarSaludables(1);
	generarAsintomaticos(1);
	//this->player = player;
}

Hard::~Hard()
{
}

void Hard::InteractuarBalasAsintomaticos (Graphics^g) {
	for (int i = 0; i <arrayAsintomaticos->getArr()->Length; i++)
	{
		arrayAsintomaticos->getArr()[i]->MoverBalas();
		arrayAsintomaticos->getArr()[i]->MostrarBalas(g);
	}
}
bool Hard::ColisionChoro(Graphics^g) {
	if (choro->getX() > player->getX()) {
		choro->setAccion(caminarIzq);
		std::cout << "entraIzquierda" <<std:: endl;
		choro->Mover(g);
	}
	else if (medico->getX() < player->getX()) {
		choro->setAccion(caminarDer);
		std::cout << "entraDerecha" << std::endl;
		choro->Mover(g);
	}
	if (choro->getY() > player->getY()) {
		std::cout << "entraArriba" << std::endl;
		choro->setAccion(caminarArr);
		choro->Mover(g);
	}
	else if (police->getY() <player->getY()) {
		std::cout << "entraAbajo" << std::endl;
		choro->setAccion(caminarAba);
		choro->Mover(g);
	}

	if (player->getContorno().IntersectsWith(choro->getContorno())) {
		return true;
	}

}
IArtificial^Hard::getChoro() {
	return choro;
}

bool Hard::ColisisionBalaAsintomatico() {
	for (int i = 0; i < arrayAsintomaticos->getArr()->Length; i++) {
		for (int j = 0; j < arrayAsintomaticos->getArr()[i]->getBalas()->getArr()->Length; j++) {
			if (arrayAsintomaticos->getArr()[i]->getBalas()->getArr()[j]->getArea().IntersectsWith(player->getContorno())){
				arrayAsintomaticos->getArr()[i]->getBalas()->Eliminar(j);
				return true;
				}
		}
	}
}

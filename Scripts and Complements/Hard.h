#pragma once
#include"Nivel.h"
#include"Jugador.h"
System::Collections::IList;
ref class Hard:public Nivel{
	IArtificial^choro;
public:
	Hard(Jugador^_player);
	~Hard();
	bool ColisionChoro(Graphics^g);
	void InteractuarBalasAsintomaticos(Graphics^g);
	bool ColisisionBalaAsintomatico();
	IArtificial^getChoro();
	/*void mostrarJugador(Graphics^g) {
	player->Mostrar(g);
	}
	void MoverJugador(Graphics^g) {
	player->Mover(g);
	}*/
};
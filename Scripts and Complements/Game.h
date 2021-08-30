#pragma once
#include"Easy.h"
#include"Hard.h"
#include"Jugador.h"
ref class Game
{
	Easy^ez;
	Hard^jard;
	Jugador^player;
public:
	Game(Jugador^_player);
	Jugador^getPlayer();
	Easy^getEz();
	Hard^getJard();
};

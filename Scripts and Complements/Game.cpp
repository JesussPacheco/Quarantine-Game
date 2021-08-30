#include "Game.h"
#include"Jugador.h"

Game::Game(Jugador^_player)
{
	player = _player;
	ez = gcnew Easy(player);
	jard = gcnew Hard(player);
}
Jugador^ Game::getPlayer() {
	return player;
};
Easy^ Game::getEz() {
	return ez;
}
Hard^ Game::getJard() {
	return jard;
}



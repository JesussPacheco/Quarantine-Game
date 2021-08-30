#include"Easy.h"
Easy::Easy(Jugador^_player):Nivel(_player)
{
	generarSaludables(1);
	generarAsintomaticos(1);
}

#pragma once
#include"ArregloAsintomaticos.h"
#include"ArregloSaludables.h"
#include"IArtificial.h"
#include"Jugador.h"
System::Collections::IList;
ref class Nivel {
protected:
	IArtificial^police;
	IArtificial^medico;
	Random x;
	int nroEnemigos = x.Next(4, 6);
	int n = nroEnemigos / 2;
	Jugador^player;
	Bitmap^mapa;
	ArregloAsintomaticos^arrayAsintomaticos;
	ArregloSaludables^arraySaludables;
	bool validedPolice = true;
	int indicePolice;
	bool validedMedico = true;
	int indiceMedico;
	int puntaje;

public:
	Nivel(Jugador^_player);
	~Nivel();
	void mostrarMapa(Graphics^g, int A, int L);
	void generarSaludables(int n);
	void MostrarSaludables(Graphics^g);
	void MoverSaludables(Graphics^g);
	void generarAsintomaticos(int n);
	void MostrarAsintomaticos(Graphics^g);
	void MoverAsintomaticos(Graphics^g);
	bool ColisionBalas();
	bool ColisionJugador();
	bool ColisionPolicia(Graphics^g);
	bool ColisionMedico(Graphics^g);
	void setMapa(Bitmap^n);
	void setNmroEnemigos(int n);
	int  getnmroEnemigos();
	int getPuntaje();
	void Abrir();
	void Guardar();

	IArtificial^getPolice();
	IArtificial^Nivel::getMedico();
	ArregloAsintomaticos^getArrayAsintomaticos();
	ArregloSaludables^getArraySaludables();

		/*void mostrarJugador(Graphics^g) {
	player->Mostrar(g);
	}
	void MoverJugador(Graphics^g) {
	player->Mover(g);
	}*/
};


#pragma once
#include"Game.h"
#include"Jugador.h"
#include<iostream>
namespace Finalisimo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	enum  Pantalla{
	menu,instrucciones,creditos,ganaste,perdiste,start,inicio};
	enum Nivel {
		inice,One,two,three,four
	};

	public ref class Gameh : public System::Windows::Forms::Form
	{
	public:
		Gameh(void)
		{
			InitializeComponent();
			MostrarPantalla(menu);
			player = gcnew Jugador();
			juego = gcnew Game(player);
			vidas = gcnew Bitmap("Imagenes\\Complementos\\vida.png");
			reloj = gcnew Bitmap("Imagenes\\Complementos\\reloj.png");
			soundInicio->PlayLooping();
		}

	protected:
		~Gameh()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  pnlMenu;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnSalir;
	private: System::Windows::Forms::Button^  btnCreditos;
	private: System::Windows::Forms::Button^  btnInstrucciones;
	private: System::Windows::Forms::Panel^  pnlInstrucciones;
	private: System::Windows::Forms::Button^  btnBack;
	private: System::Windows::Forms::Panel^  pnlCreditos;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  pnlInicio;
	private: System::Windows::Forms::RadioButton^  rbtnFacil;
	private: System::Windows::Forms::RadioButton^  rbtnDificil;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::TextBox^  tbxNombre;
	private: System::Windows::Forms::NumericUpDown^  numericTiempo;
	private: System::Windows::Forms::NumericUpDown^  numericVidas;
	private: System::Windows::Forms::Timer^  clockEasy;

	private: System::ComponentModel::IContainer^  components;
	private:
		Game ^juego;
		Jugador^player;
		Bitmap^vidas;
		Bitmap^reloj;
		String^name;
		int corazones;
		int tiempo;
		bool pause;
		bool cambioNivel = true;
		int colDownEnemigos = 0;
		int colDownPolicia = 0;
		int colDownAmbulancia = 0;
		int colDownTiempo = 0;
		Bitmap^aux1 = gcnew Bitmap("Imagenes\\Mapas\\Lurigancho2.png");
		Bitmap^aux2 = gcnew Bitmap("Imagenes\\Mapas\\SanMiguel1.png");
		Bitmap^aux3 = gcnew Bitmap("Imagenes\\Mapas\\SanMiguel2.png");
		Bitmap ^comienzo= gcnew Bitmap("Imagenes\\Mapas\\Lurigancho1.png");
		SoundPlayer^soundInicio = gcnew SoundPlayer("Musica\\musicaMenu.wav");
	private: System::Windows::Forms::Timer^  clockHard;

			 Nivel cambio = two;

#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Gameh::typeid));
			this->pnlMenu = (gcnew System::Windows::Forms::Panel());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pnlInstrucciones = (gcnew System::Windows::Forms::Panel());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->pnlCreditos = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pnlInicio = (gcnew System::Windows::Forms::Panel());
			this->numericTiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericVidas = (gcnew System::Windows::Forms::NumericUpDown());
			this->tbxNombre = (gcnew System::Windows::Forms::TextBox());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->rbtnFacil = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnDificil = (gcnew System::Windows::Forms::RadioButton());
			this->clockEasy = (gcnew System::Windows::Forms::Timer(this->components));
			this->clockHard = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlMenu->SuspendLayout();
			this->pnlInstrucciones->SuspendLayout();
			this->pnlCreditos->SuspendLayout();
			this->pnlInicio->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericTiempo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericVidas))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlMenu
			// 
			resources->ApplyResources(this->pnlMenu, L"pnlMenu");
			this->pnlMenu->Controls->Add(this->btnSalir);
			this->pnlMenu->Controls->Add(this->btnCreditos);
			this->pnlMenu->Controls->Add(this->btnInstrucciones);
			this->pnlMenu->Controls->Add(this->button1);
			this->pnlMenu->Name = L"pnlMenu";
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::Transparent;
			this->btnSalir->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSalir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->btnSalir, L"btnSalir");
			this->btnSalir->ForeColor = System::Drawing::Color::Transparent;
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->UseVisualStyleBackColor = false;
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCreditos->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->btnCreditos, L"btnCreditos");
			this->btnCreditos->ForeColor = System::Drawing::Color::Transparent;
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &Gameh::btnCreditos_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Transparent;
			this->btnInstrucciones->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnInstrucciones->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->btnInstrucciones, L"btnInstrucciones");
			this->btnInstrucciones->ForeColor = System::Drawing::Color::Transparent;
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &Gameh::btnInstrucciones_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->button1, L"button1");
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Gameh::button1_Click);
			// 
			// pnlInstrucciones
			// 
			resources->ApplyResources(this->pnlInstrucciones, L"pnlInstrucciones");
			this->pnlInstrucciones->Controls->Add(this->btnBack);
			this->pnlInstrucciones->Name = L"pnlInstrucciones";
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Transparent;
			this->btnBack->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnBack->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->btnBack, L"btnBack");
			this->btnBack->ForeColor = System::Drawing::Color::Transparent;
			this->btnBack->Name = L"btnBack";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &Gameh::btnBack_Click);
			// 
			// pnlCreditos
			// 
			resources->ApplyResources(this->pnlCreditos, L"pnlCreditos");
			this->pnlCreditos->Controls->Add(this->button2);
			this->pnlCreditos->Name = L"pnlCreditos";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->button2, L"button2");
			this->button2->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Gameh::button2_Click);
			// 
			// pnlInicio
			// 
			resources->ApplyResources(this->pnlInicio, L"pnlInicio");
			this->pnlInicio->Controls->Add(this->numericTiempo);
			this->pnlInicio->Controls->Add(this->numericVidas);
			this->pnlInicio->Controls->Add(this->tbxNombre);
			this->pnlInicio->Controls->Add(this->btnStart);
			this->pnlInicio->Controls->Add(this->rbtnFacil);
			this->pnlInicio->Controls->Add(this->rbtnDificil);
			this->pnlInicio->Name = L"pnlInicio";
			// 
			// numericTiempo
			// 
			resources->ApplyResources(this->numericTiempo, L"numericTiempo");
			this->numericTiempo->Name = L"numericTiempo";
			// 
			// numericVidas
			// 
			resources->ApplyResources(this->numericVidas, L"numericVidas");
			this->numericVidas->Name = L"numericVidas";
			// 
			// tbxNombre
			// 
			resources->ApplyResources(this->tbxNombre, L"tbxNombre");
			this->tbxNombre->Name = L"tbxNombre";
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::Transparent;
			this->btnStart->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnStart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->btnStart, L"btnStart");
			this->btnStart->ForeColor = System::Drawing::Color::Transparent;
			this->btnStart->Name = L"btnStart";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &Gameh::btnStart_Click);
			// 
			// rbtnFacil
			// 
			resources->ApplyResources(this->rbtnFacil, L"rbtnFacil");
			this->rbtnFacil->Name = L"rbtnFacil";
			this->rbtnFacil->TabStop = true;
			this->rbtnFacil->UseVisualStyleBackColor = true;
			// 
			// rbtnDificil
			// 
			resources->ApplyResources(this->rbtnDificil, L"rbtnDificil");
			this->rbtnDificil->Name = L"rbtnDificil";
			this->rbtnDificil->TabStop = true;
			this->rbtnDificil->UseVisualStyleBackColor = true;
			this->rbtnDificil->CheckedChanged += gcnew System::EventHandler(this, &Gameh::rbtnDificil_CheckedChanged);
			// 
			// clockEasy
			// 
			this->clockEasy->Tick += gcnew System::EventHandler(this, &Gameh::Easy_Tick);
			// 
			// clockHard
			// 
			this->clockHard->Tick += gcnew System::EventHandler(this, &Gameh::clockHard_Tick);
			// 
			// Gameh
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlInicio);
			this->Controls->Add(this->pnlCreditos);
			this->Controls->Add(this->pnlInstrucciones);
			this->Controls->Add(this->pnlMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Gameh";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Gameh::Gameh_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Gameh::Gameh_KeyUp);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Gameh::Gameh_MouseDown);
			this->pnlMenu->ResumeLayout(false);
			this->pnlInstrucciones->ResumeLayout(false);
			this->pnlCreditos->ResumeLayout(false);
			this->pnlInicio->ResumeLayout(false);
			this->pnlInicio->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericTiempo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericVidas))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		void MostrarPantalla(Pantalla pantalla) {
			pnlMenu->Visible =false;
			pnlInstrucciones->Visible =false;
			pnlCreditos->Visible = false;
			pnlInicio->Visible = false;
			pnlCreditos->Dock = System::Windows::Forms::DockStyle::None;
			pnlInicio->Dock = System::Windows::Forms::DockStyle::None;
			pnlInstrucciones->Dock = System::Windows::Forms::DockStyle::None;
			pnlMenu->Dock = System::Windows::Forms::DockStyle::None;
			if (pantalla == menu) {
				pnlMenu->Visible = true;
				pnlMenu->Dock = System::Windows::Forms::DockStyle::Fill;
				pnlMenu->Focus();
			}
			else if (pantalla == instrucciones) {
				pnlInstrucciones->Visible = true;
				pnlInstrucciones->Dock = System::Windows::Forms::DockStyle::Fill;
				pnlInstrucciones->Focus();
			}
			else if (pantalla == creditos) {
				pnlCreditos->Visible = true;
				pnlCreditos->Dock = System::Windows::Forms::DockStyle::Fill;
				pnlCreditos->Focus();
			}
			else if (pantalla == inicio) {
				pnlInicio->Visible = true;
				pnlInicio->Dock = System::Windows::Forms::DockStyle::Fill;
				pnlInicio->Focus();
			}
			else if (pantalla == start) {
				this->Visible = true;
				if (this->Focused == false)
					this->Focus();
			}
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		MostrarPantalla(inicio);
	}
private: System::Void btnInstrucciones_Click(System::Object^  sender, System::EventArgs^  e) {
	MostrarPantalla(instrucciones);
}
private: System::Void btnCreditos_Click(System::Object^  sender, System::EventArgs^  e) {
	MostrarPantalla(creditos);
}
private: System::Void btnBack_Click(System::Object^  sender, System::EventArgs^  e) {
	MostrarPantalla(menu);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	MostrarPantalla(menu);
}
private: System::Void rbtnDificil_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((rbtnDificil->Checked != false || rbtnFacil->Checked != false) && tbxNombre->Text != ""&&(numericTiempo->Text != ""||numericTiempo->Text=="0")&&(numericVidas->Text != ""||numericVidas->Text=="0")) {
		MostrarPantalla(start);
		if (rbtnFacil->Checked == true) {
			clockEasy->Enabled = true;
			corazones = Convert::ToInt32(numericVidas->Text);
			tiempo = Convert::ToUInt32(numericTiempo->Text)*60;
			name = tbxNombre->Text;
		//	juego->getEz()->Abrir();
		}
		else {
			clockHard->Enabled = true;
			corazones = Convert::ToInt32(numericVidas->Text);
			tiempo = Convert::ToUInt32(numericTiempo->Text)*60;
			name = tbxNombre->Text;
			//juego->getJard()->Abrir();
		}
	}
	else MessageBox::Show("Complete todos los recuadros");
}

	private: System::Void Easy_Tick(System::Object^  sender, System::EventArgs^  e) {
	//	juego->getEz()->Guardar();
		colDownTiempo += 1;
		colDownEnemigos += 10;
		colDownAmbulancia += 17;
		colDownPolicia += 10;
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		juego->getEz()->mostrarMapa(bf->Graphics, this->Width, this->Height);
		//Mostrando nombre
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 30);
		bf->Graphics->DrawString(name, f, Brushes::Black, 0, 0);
		//Mostrando vidas
		if (juego->getEz()->ColisionJugador()) corazones--;
		bf->Graphics->DrawImage(vidas, 40, 50, 80, 80);
		System::Drawing::Font^ T = gcnew System::Drawing::Font("Arial", 30);
		bf->Graphics->DrawString(corazones + " ", T, Brushes::Black, 50, 55);
		if (corazones == 0) {
			clockEasy->Enabled = false;
			MessageBox::Show("PERDISTE,TE QUEDASTE SIN VIDAS!Nivel:Facil\nJugador:" + name + "\n PUNTAJE:" + juego->getEz()->getPuntaje());
			this->Visible = false;
		}
		//Mostrando Puntaje
		System::Drawing::Font^ P = gcnew System::Drawing::Font("Arial", 30);
		bf->Graphics->DrawString("Puntaje:" + juego->getEz()->getPuntaje() + " ", P, Brushes::White, 50, 140);

		//mostrando reloj
		bf->Graphics->DrawImage(reloj, this->Width - 130, 35, 80, 80);
		System::Drawing::Font^ R = gcnew System::Drawing::Font("Arial", 50);
		bf->Graphics->DrawString(tiempo + " ", R, Brushes::Black, this->Width - 250, 40);
		if (colDownTiempo == 10) {
			tiempo -= 1;
			colDownTiempo = 0;
		};
		if (tiempo == 0) {
			clockEasy->Enabled = false;
			MessageBox::Show("Perdiste,TU TIEMPO SE AGOTÓ!\nNivel:Facil\nJugador:"+name+"\n PUNTAJE:" + juego->getEz()->getPuntaje());
			clockEasy->Enabled = false;
			this->Visible = false;
		}
		//------------------------------------------------
		//AGREGAR ENEMIGO EN INTERVALO
		if (colDownEnemigos == 100 && juego->getEz()->getArraySaludables()->getArr()->Length <= juego->getEz()->getnmroEnemigos() / 2) {
			juego->getEz()->getArraySaludables()->Agregar();
		}
        //AGREGAR ENEMIGO EN INTERVALO
		if (colDownEnemigos == 150 && juego->getEz()->getArrayAsintomaticos()->getArr()->Length <= juego->getEz()->getnmroEnemigos() / 2) {
			juego->getEz()->getArrayAsintomaticos()->Agregar();
			colDownEnemigos = 0;
		}
		juego->getEz()->ColisionBalas();

		if (colDownPolicia > 1500)
		{
			juego->getEz()->ColisionPolicia(bf->Graphics);
			juego->getEz()->getPolice()->Mostrar(bf->Graphics);
		}
		if (colDownAmbulancia > 1500) {
			juego->getEz()->ColisionMedico(bf->Graphics);
			juego->getEz()->getMedico()->Mostrar(bf->Graphics);
		}
		juego->getEz()->MostrarAsintomaticos(bf->Graphics);
		juego->getEz()->MoverAsintomaticos(bf->Graphics);
		juego->getEz()->MostrarSaludables(bf->Graphics);
		juego->getEz()->MoverSaludables(bf->Graphics);
		player->Mover(bf->Graphics);
		player->Mostrar(bf->Graphics);
		player->moverBalas();
		if (cambio == two) {
			if (juego->getEz()->getArraySaludables()->getArr()->Length == 0 && juego->getEz()->getArrayAsintomaticos()->getArr()->Length == 0) {
				juego->getEz()->setMapa(aux1);
				colDownAmbulancia = 0;
				colDownPolicia = 0;
				colDownEnemigos = 90;
				cambio = three;
				juego->getEz()->setNmroEnemigos(8);
				juego->getEz()->getArraySaludables()->Agregar();
			}
		}

		if (cambio == three) {
			if (juego->getEz()->getArraySaludables()->getArr()->Length == 0 && juego->getEz()->getArrayAsintomaticos()->getArr()->Length == 0) {
				juego->getEz()->setMapa(aux2);
				colDownAmbulancia = 0;
				colDownPolicia = 0;
				colDownEnemigos = 90;
				cambio = four;
				juego->getEz()->setNmroEnemigos(12);
				juego->getEz()->getArraySaludables()->Agregar();
			}

		}
		if (cambio == four) {
			if (juego->getEz()->getArraySaludables()->getArr()->Length == 0 && juego->getEz()->getArrayAsintomaticos()->getArr()->Length == 0) {
				juego->getEz()->setMapa(aux3);
				colDownAmbulancia = 0;
				colDownPolicia = 0;
				colDownEnemigos = 90;
				cambio = One;
				juego->getEz()->setNmroEnemigos(16);
				juego->getEz()->getArraySaludables()->Agregar();
			}
		}
		if (cambio == One) {
			if (juego->getEz()->getArraySaludables()->getArr()->Length == 0 && juego->getEz()->getArrayAsintomaticos()->getArr()->Length == 0) {
				juego->getEz()->setMapa(aux3);
				colDownAmbulancia = 0;
				colDownPolicia = 0;
				colDownEnemigos = 90;
				cambio = One;
				juego->getEz()->setNmroEnemigos(16);
				clockEasy->Enabled = false;
				MessageBox::Show("GANASTE :V");
			}
		}
		bf->Render(g);
}
private: System::Void Gameh_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	const int v = 10;
	if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)
	{
		player->setDY(-v);
		juego->getPlayer()->setAccion(caminarArr);
	}
	else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)
	{
		player->setDY(v);
		juego->getPlayer()->setAccion(caminarAba);
	}
	else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)
	{
		player->setDX(-v);
		player->setAccion(caminarIzq);
	}
	else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D)
	{
		player->setDX(v);
		player->setAccion(caminarDer);
	}
	if (e->KeyCode == Keys::Enter) {
		Graphics ^aux = this->CreateGraphics();
		System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 100);
		aux->DrawString("PAUSE", f, Brushes::Black, 250, 250);
		if (clockEasy->Enabled == true) 
			clockEasy->Enabled = false;
		else clockEasy->Enabled = true;
	}

}
private: System::Void Gameh_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Up || e->KeyCode == Keys::W)
	{
		player->setDY(0);
	}
	else if (e->KeyCode == Keys::Down || e->KeyCode == Keys::S)
	{
		player->setDY(0);
	}
	else if (e->KeyCode == Keys::Left || e->KeyCode == Keys::A)
	{
		player->setDX(0);
	}
	else if (e->KeyCode == Keys::Right || e->KeyCode == Keys::D)
	{
		player->setDX(0);
	}
}
private: System::Void Gameh_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (player->getAccion() == caminarArr)
	{
		player->setAccion(disparoArr);
		player->Disparar(e->X,e->Y);
	}
	else if (player->getAccion() == caminarAba)
	{

		player->setAccion(disparoAba);

		player->Disparar(e->X, e->Y);

	}
	else if (player->getAccion() == caminarIzq)
	{

		player->setAccion(disparoIzq);

		player->Disparar(e->X, e->Y);

	}
	else if (player->getAccion() == caminarDer)
	{

		player->setAccion(disparoDer);

		player->Disparar(e->X, e->Y);
	}
}
private: System::Void clockHard_Tick(System::Object^  sender, System::EventArgs^  e) {
//	juego->getJard()->Guardar();
	colDownTiempo += 1;
	colDownEnemigos += 10;
	colDownAmbulancia += 17;
	colDownPolicia += 10;
	Graphics^g = this->CreateGraphics();
	BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
	BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
	juego->getJard()->mostrarMapa(bf->Graphics, this->Width, this->Height);
//Mostrando nombre
	System::Drawing::Font^ f = gcnew System::Drawing::Font("Arial", 30);
	bf->Graphics->DrawString(name, f, Brushes::Black, 0, 0);
	//Mostrando vidas
	bf->Graphics->DrawImage(vidas, 40, 50, 80, 80);
	System::Drawing::Font^ T = gcnew System::Drawing::Font("Arial", 30);
	bf->Graphics->DrawString(corazones + " ", T, Brushes::Black, 50,55);
	if (juego->getJard()->ColisionChoro(bf->Graphics))corazones--;
	if (juego->getJard()->ColisionJugador()) corazones --;
	//Mostrando Puntaje
	if (corazones == 0) {
	clockHard->Enabled = false;
	MessageBox::Show("PERDISTE,TE QUEDASTE SIN VIDAS!\nJugador:"+name+"\nNIVEL:DIFICIL"+"\nPUNTAJE:" + juego->getJard()->getPuntaje());
	this->Visible = false;
	}
	System::Drawing::Font^ P = gcnew System::Drawing::Font("Arial", 30);
	bf->Graphics->DrawString( "Puntaje:"+juego->getJard()->getPuntaje() + " ", P, Brushes::White, 50,140);

	//mostrando reloj
	bf->Graphics->DrawImage(reloj, this->Width-130, 35, 80, 80);
	System::Drawing::Font^ R = gcnew System::Drawing::Font("Arial", 50);
	bf->Graphics->DrawString(tiempo + " ", R, Brushes::Black, this->Width-250,40);
	if (colDownTiempo == 10) { 
		tiempo -= 1;
		colDownTiempo = 0;
	};
	if (tiempo == 0) {
		clockHard->Enabled = false;
		MessageBox::Show("Perdiste,TU TIEMPO SE AGOTÓ!\nJugador:" + name + "\nNIVEL:DIFICIL" + "\nPUNTAJE:" + juego->getJard()->getPuntaje());
		this->Visible = false;
	}
	//------------------------------------------------
	if (colDownEnemigos == 100 && juego->getJard()->getArraySaludables()->getArr()->Length <= juego->getJard()->getnmroEnemigos() / 2) {
		juego->getJard()->getArraySaludables()->Agregar();
	}
	if (colDownEnemigos == 150 && juego->getJard()->getArrayAsintomaticos()->getArr()->Length <= juego->getJard()->getnmroEnemigos() / 2) {
		juego->getJard()->getArrayAsintomaticos()->Agregar();
		colDownEnemigos = 0;
	}
	juego->getJard()->ColisionBalas();

	if (colDownPolicia > 1000)
	{
		juego->getJard()->ColisionPolicia(bf->Graphics);
		juego->getJard()->getPolice()->Mostrar(bf->Graphics);
	}
	if (colDownAmbulancia > 600) {
		juego->getJard()->ColisionMedico(bf->Graphics);
		juego->getJard()->getMedico()->Mostrar(bf->Graphics);
	}
	if (juego->getJard()->ColisisionBalaAsintomatico())corazones-=1;;
	juego->getJard()->getChoro()->Mostrar(bf->Graphics);
	juego->getJard()->MostrarAsintomaticos(bf->Graphics);
	juego->getJard()->MoverAsintomaticos(bf->Graphics);
	juego->getJard()->MostrarSaludables(bf->Graphics);
	juego->getJard()->MoverSaludables(bf->Graphics);
	juego->getJard()->InteractuarBalasAsintomaticos(bf->Graphics);
	player->Mover(bf->Graphics);
	player->Mostrar(bf->Graphics);
	player->moverBalas();
	if (cambio == two) {
		if (juego->getJard()->getArraySaludables()->getArr()->Length == 0 && juego->getJard()->getArrayAsintomaticos()->getArr()->Length == 0) {
			juego->getJard()->setMapa(aux1);
			colDownAmbulancia = 0;
			colDownPolicia = 0;
			colDownEnemigos = 90;
			cambio = three;
			juego->getJard()->setNmroEnemigos(8);
			juego->getJard()->getArraySaludables()->Agregar();
		}
	}

	if (cambio == three) {
		if (juego->getJard()->getArraySaludables()->getArr()->Length == 0 && juego->getJard()->getArrayAsintomaticos()->getArr()->Length == 0) {
			juego->getJard()->setMapa(aux2);
			colDownAmbulancia = 0;
			colDownPolicia = 0;
			colDownEnemigos = 90;
			cambio = four;
			juego->getJard()->setNmroEnemigos(12);
			juego->getJard()->getArraySaludables()->Agregar();
		}

	}
	if (cambio == four) {
		if (juego->getJard()->getArraySaludables()->getArr()->Length == 0 && juego->getJard()->getArrayAsintomaticos()->getArr()->Length == 0) {
			juego->getJard()->setMapa(aux3);
			colDownAmbulancia = 0;
			colDownPolicia = 0;
			colDownEnemigos = 90;
			cambio = One;
			juego->getJard()->setNmroEnemigos(16);
			juego->getJard()->getArraySaludables()->Agregar();
		}
	}
	if (cambio == One) {
		if (juego->getJard()->getArraySaludables()->getArr()->Length == 0 && juego->getJard()->getArrayAsintomaticos()->getArr()->Length == 0) {
			juego->getJard()->setMapa(aux3);
			colDownAmbulancia = 0;
			colDownPolicia = 0;
			colDownEnemigos = 90;
			cambio = inice;
			clockHard->Enabled = false;
			MessageBox::Show("¡GANASTE!\nPuntaje:"+juego->getJard()->getPuntaje());
			this->Visible = false;
		}
	}
	bf->Render(g);

}
};
}

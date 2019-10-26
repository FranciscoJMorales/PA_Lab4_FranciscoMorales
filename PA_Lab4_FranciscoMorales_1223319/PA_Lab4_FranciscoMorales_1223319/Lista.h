#pragma once
#include "Pokemon.h"

class Lista
{
public:
	Pokemon *head;
	Pokemon *tail;
	int length;

	Lista();
	~Lista();
	void Lista::Agregar(Pokemon *nuevo);
	Pokemon *Lista::Eliminar(int posicion);
	bool Lista::Ordenado();
	bool Lista::OrdenadoGen();
	void Lista::Intercambiar(Pokemon *p1, Pokemon *p2);
	int Lista::LengthIntervalo(Pokemon *inicio, Pokemon *fin);
	Pokemon *Lista::ObtenerPrimeroGeneración(int g);
	Pokemon *Lista::ObtenerÚltimoGeneración(int g);
	System::String^Lista::String();

private:
	void Lista::AgregarRecursivo(Pokemon *nuevo, Pokemon *pos);
	Pokemon *Lista::EliminarRecursivo(Pokemon *pos, int cantidad);
	bool Lista::OrdenadoRecursivo(Pokemon *pos);
	bool Lista::OrdenadoGenRecursivo(Pokemon *pos);
	System::String^Lista::StringRecursivo(Pokemon *pos);
};


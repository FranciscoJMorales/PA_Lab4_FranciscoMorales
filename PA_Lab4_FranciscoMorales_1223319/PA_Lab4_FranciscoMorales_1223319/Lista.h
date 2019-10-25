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
	void Lista::Intercambiar(Pokemon *p1, Pokemon *p2);
	System::String^Lista::String();

private:
	void Lista::AgregarRecursivo(Pokemon *nuevo, Pokemon *pos);
	Pokemon *Lista::EliminarRecursivo(Pokemon *pos, int cantidad);
	bool Lista::OrdenadoRecursivo(Pokemon *pos);
	System::String^Lista::StringRecursivo(Pokemon *pos);
};


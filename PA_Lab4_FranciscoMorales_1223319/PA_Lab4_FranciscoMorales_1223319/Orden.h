#pragma once
#include "Lista.h"
#include "Pokemon.h"

class Orden
{
public:
	Lista *pokedex;

	Orden();
	~Orden();
	void Orden::BubbleSort();
	void Orden::QuickSort();
	void Orden::StupidSort();
	void Orden::Cargar(System::String ^nuevo);
	System::String^Orden::String();

private:
	void Orden::QuickSort(Pokemon *inicio, Pokemon *fin);
};


#pragma once
#include "Lista.h"
#include "Pokemon.h"

class Orden
{
public:
	Lista *pokedex;
	Lista *generaciones[8];

	Orden();
	~Orden();
	void Orden::BubbleSort();
	void Orden::QuickSort();
	void Orden::StupidSort();
	void Orden::BubbleSortGen();
	void Orden::QuickSortGen();
	void Orden::StupidSortGen();
	void Orden::Cargar(System::String ^nuevo);
	System::String^Orden::String();

private:
	void Orden::BubbleSort(Lista *lista);
	void Orden::StupidSort(Lista *lista);
	void Orden::QuickSort(Pokemon *inicio, Pokemon *fin);
	void Orden::QuickSortGen(Pokemon *inicio, Pokemon *fin);
};


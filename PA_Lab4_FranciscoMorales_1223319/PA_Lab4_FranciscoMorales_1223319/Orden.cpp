#include "Orden.h"



Orden::Orden()
{
	pokedex = new Lista();
}


Orden::~Orden()
{
}

void Orden::BubbleSort() {
	Pokemon *i = pokedex->head;
	bool intercambio = true;
	do {
		intercambio = false;
		i = pokedex->head;
		while (i->sig != nullptr) {
			if (i->sig->numero < i->numero) {
				pokedex->Intercambiar(i, i->sig);
				intercambio = true;
			}
			i = i->sig;
		}
	} while (intercambio);
}

void Orden::QuickSort() {
	QuickSort(pokedex->head, pokedex->tail);
}

void Orden::QuickSort(Pokemon *inicio, Pokemon *fin) {
	if (inicio != fin) {
		Pokemon *izquierda = inicio;
		Pokemon *derecha = fin;
		while (izquierda != derecha) {
			while (derecha->numero > inicio->numero && izquierda != derecha) {
				derecha = derecha->ant;
			}
			if (izquierda != derecha) {
				while (izquierda->numero <= inicio->numero && izquierda != derecha) {
					izquierda = izquierda->sig;
				}
			}
			pokedex->Intercambiar(izquierda, derecha);
		}
		pokedex->Intercambiar(inicio, derecha);
		if (derecha != inicio) {
			QuickSort(inicio, derecha->ant);
		}
		if (derecha != fin) {
			QuickSort(derecha->sig, fin);
		}
	}
}

void Orden::StupidSort() {
	System::Random ^rng = gcnew System::Random();
	while (!pokedex->Ordenado()) {
		Lista *aux = new Lista();
		while (pokedex->length > 0) {
			aux->Agregar(pokedex->Eliminar(rng->Next(0, pokedex->length)));
		}
		pokedex = aux;
	}
}

void Orden::Cargar(System::String ^nuevo) {
	int n = System::Convert::ToInt32(nuevo->Substring(0, nuevo->IndexOf(";")));
	nuevo = nuevo->Remove(0, nuevo->IndexOf(";") + 1);
	int g = System::Convert::ToInt32(nuevo->Substring(0, nuevo->IndexOf(";")));
	nuevo = nuevo->Remove(0, nuevo->IndexOf(";") + 1);
	pokedex->Agregar(new Pokemon(n, g, nuevo));
}

System::String^Orden::String() {
	return pokedex->String();
}
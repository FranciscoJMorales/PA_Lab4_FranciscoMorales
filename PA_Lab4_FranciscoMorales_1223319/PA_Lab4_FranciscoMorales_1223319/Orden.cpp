#include "Orden.h"



Orden::Orden()
{
	pokedex = new Lista();
	for (int i = 0; i < 8; i++) {
		generaciones[i] = new Lista();
	}
}


Orden::~Orden()
{
}

void Orden::BubbleSort() {
	BubbleSort(pokedex);
	/*Pokemon *i = pokedex->head;
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
	} while (intercambio);*/
}

void Orden::BubbleSort(Lista *lista) {
	Pokemon *i = lista->head;
	int n = 0;
	bool intercambio = true;
	do {
		intercambio = false;
		n = 0;
		i = lista->head;
		while (n < lista->length - 1) {
			if (i->sig->numero < i->numero) {
				lista->Intercambiar(i, i->sig);
				intercambio = true;
			}
			n++;
			i = i->sig;
		}
	} while (intercambio);
}

void Orden::BubbleSortGen() {
	Pokemon *i = pokedex->head;
	bool intercambio = true;
	do {
		intercambio = false;
		i = pokedex->head;
		while (i->sig != nullptr) {
			if (i->sig->generación < i->generación) {
				pokedex->Intercambiar(i, i->sig);
				intercambio = true;
			}
			i = i->sig;
		}
	} while (intercambio);
	for (int i = 0; i < 8; i++) {
		generaciones[i]->head = pokedex->ObtenerPrimeroGeneración(i + 1);
		generaciones[i]->tail = pokedex->ObtenerÚltimoGeneración(i + 1);
		generaciones[i]->length = pokedex->LengthIntervalo(generaciones[i]->head, generaciones[i]->tail);
		if (generaciones[i]->length > 0) {
			BubbleSort(generaciones[i]);
		}
	}
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

void Orden::QuickSortGen() {
	QuickSortGen(pokedex->head, pokedex->tail);
	for (int i = 0; i < 8; i++) {
		generaciones[i]->head = pokedex->ObtenerPrimeroGeneración(i + 1);
		generaciones[i]->tail = pokedex->ObtenerÚltimoGeneración(i + 1);
		generaciones[i]->length = pokedex->LengthIntervalo(generaciones[i]->head, generaciones[i]->tail);
		if (generaciones[i]->length > 0) {
			QuickSort(generaciones[i]->head, generaciones[i]->tail);
		}
	}
}

void Orden::QuickSortGen(Pokemon *inicio, Pokemon *fin) {
	if (inicio != fin) {
		Pokemon *izquierda = inicio;
		Pokemon *derecha = fin;
		while (izquierda != derecha) {
			while (derecha->generación > inicio->generación && izquierda != derecha) {
				derecha = derecha->ant;
			}
			if (izquierda != derecha) {
				while (izquierda->generación <= inicio->generación && izquierda != derecha) {
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
	StupidSort(pokedex);
	/*System::Random ^rng = gcnew System::Random();
	while (!pokedex->Ordenado()) {
		Lista *aux = new Lista();
		while (pokedex->length > 0) {
			aux->Agregar(pokedex->Eliminar(rng->Next(0, pokedex->length)));
		}
		pokedex = aux;
	}*/
}

void Orden::StupidSort(Lista *lista) {
	bool guardarPokedex = false;
	if (lista == pokedex) {
		guardarPokedex = true;
	}
	Pokemon *auxInicio = lista->head->ant;
	Pokemon *auxFin = lista->tail->sig;
	lista->head->ant = nullptr;
	lista->tail->sig = nullptr;
	System::Random ^rng = gcnew System::Random();
	while (!lista->Ordenado()) {
		Lista *aux = new Lista();
		while (lista->length > 0) {
			aux->Agregar(lista->Eliminar(rng->Next(0, lista->length)));
		}
		lista = aux;
	}
	lista->head->ant = auxInicio;
	lista->tail->sig = auxFin;
	if (auxInicio != nullptr) {
		lista->head->ant->sig = lista->head;
	}
	else {
		pokedex->head = lista->head;
	}
	if (auxFin != nullptr) {
		lista->tail->sig->ant = lista->tail;
	}
	else {
		pokedex->tail = lista->tail;
	}
	if (guardarPokedex) {
		pokedex = lista;
	}
}

void Orden::StupidSortGen() {
	System::Random ^rng = gcnew System::Random();
	while (!pokedex->OrdenadoGen()) {
		Lista *aux = new Lista();
		while (pokedex->length > 0) {
			aux->Agregar(pokedex->Eliminar(rng->Next(0, pokedex->length)));
		}
		pokedex = aux;
	}
	for (int i = 0; i < 8; i++) {
		generaciones[i]->head = pokedex->ObtenerPrimeroGeneración(i + 1);
		generaciones[i]->tail = pokedex->ObtenerÚltimoGeneración(i + 1);
		generaciones[i]->length = pokedex->LengthIntervalo(generaciones[i]->head, generaciones[i]->tail);
		if (generaciones[i]->length > 0) {
			StupidSort(generaciones[i]);
		}
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
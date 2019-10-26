#include "Lista.h"



Lista::Lista()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}


Lista::~Lista()
{
}

void Lista::Agregar(Pokemon *nuevo) {
	length++;
	tail = nuevo;
	if (head == nullptr) {
		head = nuevo;
	}
	else {
		AgregarRecursivo(nuevo, head);
	}
}

Pokemon *Lista::Eliminar(int posicion) {
	if (head != nullptr) {
		if (posicion == 0) {
			length--;
			if (head == tail) {
				tail = nullptr;
			}
			Pokemon *aux = head;
			head = head->sig;
			if (head != nullptr) {
				head->ant = nullptr;
			}
			aux->sig = nullptr;
			aux->ant = nullptr;
			return aux;
		}
		else if (posicion == length - 1) {
			length--;
			Pokemon *aux = tail;
			tail = tail->ant;
			tail->sig = nullptr;
			aux->sig = nullptr;
			aux->ant = nullptr;
			return aux;
		}
		else {
			return EliminarRecursivo(head, posicion);
		}
	}
	else {
		return new Pokemon(-1, -1, "");
	}
}

bool Lista::Ordenado() {
	if (head == nullptr) {
		return true;
	}
	else {
		if (head->sig == nullptr) {
			return true;
		}
		else {
			return OrdenadoRecursivo(head);
		}
	}
}

bool Lista::OrdenadoGen() {
	if (head == nullptr) {
		return true;
	}
	else {
		if (head->sig == nullptr) {
			return true;
		}
		else {
			return OrdenadoGenRecursivo(head);
		}
	}
}

void Lista::Intercambiar(Pokemon *p1, Pokemon *p2) {
	System::String ^nombreAux = p1->Nombre();
	int numAux = p1->numero;
	int genAux = p1->generación;
	p1->AsignarNombre(p2->Nombre());
	p1->numero = p2->numero;
	p1->generación = p2->generación;
	p2->AsignarNombre(nombreAux);
	p2->numero = numAux;
	p2->generación = genAux;
}

int Lista::LengthIntervalo(Pokemon *inicio, Pokemon *fin) {
	if (inicio == nullptr) {
		return 0;
	}
	else {
		if (inicio == fin) {
			return 1;
		}
		else {
			return 1 + LengthIntervalo(inicio->sig, fin);
		}
	}
}

Pokemon *Lista::ObtenerPrimeroGeneración(int g) {
	if (head == nullptr) {
		return new Pokemon(-1, -1, "");
	}
	else {
		Pokemon *aux = head;
		while (aux->generación != g && aux->sig != nullptr) {
			aux = aux->sig;
		}
		if (aux->generación == g) {
			return aux;
		}
		else {
			return nullptr;
		}
	}
}

Pokemon *Lista::ObtenerÚltimoGeneración(int g) {
	if (head == nullptr) {
		return new Pokemon(-1, -1, "");
	}
	else {
		Pokemon *aux = head;
		while (aux->generación != g + 1 && aux->sig != nullptr) {
			aux = aux->sig;
		}
		if (aux->generación == g) {
			return aux;
		}
		else if (aux->ant->generación == g) {
			return aux->ant;
		}
		else {
			return nullptr;
		}
	}
}

System::String^Lista::String() {
	return StringRecursivo(head);
}

void Lista::AgregarRecursivo(Pokemon *nuevo, Pokemon *pos) {
	if (pos->sig != nullptr) {
		AgregarRecursivo(nuevo, pos->sig);
	}
	else {
		pos->sig = nuevo;
		nuevo->ant = pos;
	}
}

Pokemon *Lista::EliminarRecursivo(Pokemon *pos, int cantidad) {
	if (cantidad > 0) {
		if (pos->sig != nullptr) {
			return EliminarRecursivo(pos->sig, cantidad - 1);
		}
		else {
			return new Pokemon(-1, -1, "");
		}
	}
	else {
		if (pos->ant != nullptr) {
			pos->ant->sig = pos->sig;
		}
		if (pos->sig != nullptr) {
			pos->sig->ant = pos->ant;
		}
		pos->ant = nullptr;
		pos->sig = nullptr;
		length--;
		return pos;
	}
}

bool Lista::OrdenadoRecursivo(Pokemon *pos) {
	if (pos != tail) {
		if (pos->numero <= pos->sig->numero) {
			return OrdenadoRecursivo(pos->sig);
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}

bool Lista::OrdenadoGenRecursivo(Pokemon *pos) {
	if (pos != tail) {
		if (pos->generación <= pos->sig->generación) {
			return OrdenadoGenRecursivo(pos->sig);
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}

System::String^Lista::StringRecursivo(Pokemon *pos) {
	if (pos != nullptr) {
		if (pos->sig == nullptr) {
			return pos->String();
		}
		else {
			return pos->String() + "\r\n" + StringRecursivo(pos->sig);
		}
	}
	else {
		return "--;--;--";
	}
}
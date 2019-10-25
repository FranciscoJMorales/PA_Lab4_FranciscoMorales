#include "Pokemon.h"



Pokemon::Pokemon(int num, int gen, System::String ^name)
{
	numero = num;
	generación = gen;
	sig = nullptr;
	ant = nullptr;
	nombre = msclr::interop::marshal_as<std::string>(name);
}


Pokemon::~Pokemon()
{
}

void Pokemon::AsignarNombre(System::String ^name) {
	nombre = msclr::interop::marshal_as<std::string>(name);
}

System::String^Pokemon::Nombre() {
	System::String ^name = gcnew System::String(nombre.c_str());
	return name;
}

System::String^Pokemon::String() {
	System::String ^name = gcnew System::String(nombre.c_str());
	return numero + ";" + generación + ";" + name;
}
#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace System;

class Pokemon
{
public:
	int numero;
	int generación;
	std::string nombre;
	Pokemon *sig;
	Pokemon *ant;

	Pokemon(int num, int gen, System::String ^name);
	~Pokemon();
	void Pokemon::AsignarNombre(System::String ^name);
	System::String^Pokemon::Nombre();
	System::String^Pokemon::String();
};



#include "pch.h"
#include "cstdlib"
#include "string"
#include "ctime"

using namespace System;

void CambiarPos(int Mapa[70], int Probabilidad[10], int** Gamer)
{
	//Se aplica el MOD para que quede un residuo entre 0 y 10
	int Value = rand() % 10;
	int NuevaPos = **Gamer + Probabilidad[Value];
	//If anidados, abreviados 
	NuevaPos = NuevaPos > 70 ? 69 : (NuevaPos < 0 ? 0 : NuevaPos);
	//Accede al valor en la posición del puntero
	* Gamer = &Mapa[NuevaPos];
}

int main(array<System::String^>^ args)
{
	//Genera una posición inicial para cada Random
	srand(time(NULL));
	//Variables
	int Mapa[70];
	int ProbabilidadTortuga[10] = { 3,3,3,3,3,-6,-6,1,1,1 };
	int ProbabilidadLiebre[10] = { 0,0,9,9,-12,1,1,1,-2,-2 };
	int* Tortuga, * Liebre;
	Liebre = Tortuga = &Mapa[0];

	//Asignar los valores del vector
	for (int i = 0; i < 70; i++)
	{
		Mapa[i] = i + 1;
	}

	//Ciclos de la carrera 
	bool Fin = false;
	Console::WriteLine("Empieza la carrera");
	while (!Fin)
	{
		CambiarPos(Mapa, ProbabilidadTortuga, &Tortuga);
		CambiarPos(Mapa, ProbabilidadLiebre, &Liebre);
		for (int i = 0; i < 70; i++)
		{
			if (Tortuga == Liebre && Tortuga == &Mapa[i])
			{
				Console::Write("O");
			}
			else if (Tortuga == &Mapa[i])
			{
				Console::Write("T");
			}
			else if (Liebre == &Mapa[i])
			{
				Console::Write("L");
			}
			else
			{
				Console::Write("_");
			}

		}
		//Condición de los ganadores
		Console::WriteLine("");
		if (Tortuga == &Mapa[69])
		{
			Console::WriteLine("Gana Tortuga!");
			Fin = true;
		}
		else if (Liebre == &Mapa[69])
		{
			Console::Write("Gana Libre!");
			Fin = true;
		}
	}
	Console::ReadKey();
	return 0;
}
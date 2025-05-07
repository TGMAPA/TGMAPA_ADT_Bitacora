// Actividad Integral --> BITACORA

// Miguel Ángel Pérez Ávila A01369908
// Tadeo Serrano Arriaga A01771239 

// Implementación del ADT de la estructura:



#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdint.h>

using namespace std;



class Bitacora{
	
	private:

		int ind_campo_clave; // Indice del campo clave para los eventos
		string Bit_name;
		vector<string> event_ord;
		
		//Merge - Comparació y unión de vectores
		void Mezcla( vector<string>&array, int first_ind, int mid, int end_ind );
	
		//Merge - Recursión
		void mezclarecursion( vector<string>&array, int first_ind, int end_ind );
		
		//Merge - retorno de vector 
		vector<string> ordenaMezcla( vector<string> array );
		
		//Busqueda binaria  -> indice de busqueda
		int busqBinaria( vector<string> array, string campo );
		
		
		
	public:
		
		Bitacora(int ind_campo_clave_user, string arch_Bit_name){
			
			// Construir el arhcivo .txt para la bitacora
			Bit_name= arch_Bit_name;
			ind_campo_clave = ind_campo_clave_user;
			ofstream arch;     
			arch.open(Bit_name, ios::out);
			arch.close();
		}
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	void agregar_Evento( string evento );
	
	void agregar_Evento_lote( string archivo );
	
	void vaciar();
	
	bool Estado();
	
	void ordenar( bool mostrar = false );
	
	void buscar( string campo );
	
	void consultar_rango( string campo_inicial, string campo_final );

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

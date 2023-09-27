	#include <stdio.h>
	#include <conio.h>
	#include <String.h>
	#include <string.h>
	
	#include <vector>
	#include <fstream>
	#include <iostream>
	#include <cstdlib>
	#include <sstream>
	#include <ratio>
	#include <time.h>
	#include <sys/time.h>
	#include <chrono>
	#include <ctime>
	#include <bits/stdc++.h>
	#include <algorithm>
	#include <experimental/random>
	
	using namespace std;
	
	
	
	class Bitacora{
		public:
			int cant_eventos;
			int ind_campo_clave;
			char *user_arch_original;
			char Bit_name;
			
		public:
			Bitacora(int ind_campo_clave, string Bit_name){
				
				ofstream arch;
  				arch.open(Bit_name, ios::out);
			}
			
			
		void agregar_Evento(char campo){
			
			
			
		}
		
		void agregar_Evento_lote(){
			
			ifstream arch;
			string lectura;
			ofstream out(Bit_name);
			
			arch.open(archivo, ios::in);
			if(arch.fail()){
		        cout<<"No se pudo abrir el archivo";
		        exit(1);
	   		}
			
			while(!arch.eof()){
		        getline(arch,lectura);
		        int aux;
		        istringstream(lectura) >> aux;
		        out << aux;
			out.close();
			arch.close();	
			
			}
		}
		
		void vaciar(){
			
			
			
			
		}	
		
		bool Estado(){
			
			
			
		}
		
		void ordenar(){
			
			
		}
		
		void buscar(){
			
			
		}
		
		void consultar_rango( char campo , char campo_inicial, char campo_final){
			
			
		}
		
		
	};
	
	
	
	
	///////////////////////////////////////////////////////////////////////////////////////////
	
	int main(){
		
		Bitacora Bitac(0, "bitacora_test.txt");
		
		Bitac.user_arch_original = "bitacora.txt";
		
		Bitac.agregar_Evento_lote();
		
		
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

//Act 2.1 - Implementación de un ADT de estructura de datos lineales
// Miguel Ángel Pérez Ávila    A01369908


#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdint.h>

using namespace std;



class Torneo{
	
	//Definicion de estructura JUGADOR
	public: struct Jugador{
		string nombre = "";
		int identificador = -1;
		string posicion = "";
		float media = 0.0;
	};
	
	//Definicion de estructura EQUIPOS
	public: struct Equipo{
		string nombre = "";
		int p_ganados = -1;
		int p_perdidos = -1;
		int p_empatados = -1;
		float puntos = 0.0;
		struct Jugador *arr_players = NULL;
		
		create(int m){
			arr_players= new Jugador[m];	
		}
		
		~Equipo(){
			delete arr_players;
		}
	};
	
	private:
		
		//numero maximo de equipos
		int max_teams;
		
		//numero maximo de jugadores por equipo
		int max_players;
		
		//arreglo de equipos
		struct Equipo *arr_teams = NULL;
		
		//arreglo de equpós ordenados
		struct Equipo *arr_teams_ord = NULL;
		
		//Método para ordenar por puntaje
		void Ord();
		
		//Método para revisar el estado del arreglo principal de equipos donde:  True --> arreglo lleno
		bool full();
		
		//Método para revisar el estado del arreglo de jugadores donde:  True --> arreglo lleno
		bool full_players(string team);
				
	public:
		
		//Constructor de clase Torneo
		Torneo(int e_var, int j_var){
	
			max_teams = e_var;	
			max_players = j_var;
			
			//Reserva de memoria para arrgelos con maximo de jugadores por equipo
			arr_teams = new Equipo[e_var]; // arreglo principal de equipos de torneo
			arr_teams_ord = new Equipo[e_var]; // arreglo de equipos ordenados por puntaje
			for(int i=0;i<max_teams;i++){
				arr_teams[i].create(j_var);
				arr_teams_ord[i].create(j_var);
			}
			
		}
		
		//Destructor de clase Torneo --> liberación de memoria reservada para arreglos
		~Torneo(){
			delete arr_teams;
			delete arr_teams_ord;
		}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	void create_team( Equipo eq );
	
	void create_player( string team, Jugador jd );
	
	void read_team( string team );
	
	void read_player( string player, string team );
	
	void update_team( string team_ , Equipo eq );
	
	void update_player( string player_, string team_, Jugador jd );
	
	void delete_team( string team );
	
	void delete_player( string player, string team );
	
	void state();

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//  Definición de métodos  -> outline

#include "ADT.hpp"

// Private ======================================================================================

void Torneo::Ord(){
	
	float aux;
	float points[max_teams];
	
	for(int i = 0; i<max_teams; i++){
		points[i] = arr_teams[i].puntos;
	}
	
	for(int i = 0; i<max_teams-1; i++){
		for(int j=i+1; j<max_teams-1; j++){
			if(points[i] < points[j]){
				aux= points[i];
				points[i]= points[j];
				points[j]= aux;
			}		
		}
	}
	
	for(int i = 0; i<max_teams; i++){
		for(int j = 0; j<max_teams; j++){
			if(arr_teams[j].puntos == points[i]){
				arr_teams_ord[i] = arr_teams[j];
				break;
			}
		}
	}
}

bool Torneo::full(){
	
	bool flag=false;
	for( int i = 0; i<max_teams; i++){
		if(arr_teams[i].nombre != ""){
			flag=true;
		}else{
			flag=false;
		}
	}
	return flag;
}

bool Torneo::full_players(string team){
	
	bool flag=false;
	for( int i = 0; i<max_teams; i++){
		if(arr_teams[i].nombre == team){
			for( int j = 0; j<max_players; j++){
				if(arr_teams[i].arr_players[j].nombre != ""){
					flag=true;
				}else{
					flag=false;
				}
			}	
			break;
		}	
	}
	return flag;
}

// Public =======================================================================================

void Torneo::create_team( Equipo eq ){
	
	if(full()){
		cout << "[ERROR] Maximo de equipos alcanzado..." << endl;
	}else{
		for(int i=0; i<max_teams; i++){
			if(arr_teams[i].nombre == ""){
				arr_teams[i].nombre = eq.nombre;
				arr_teams[i].p_ganados = eq.p_ganados;
				arr_teams[i].p_perdidos= eq.p_perdidos;
				arr_teams[i].p_empatados= eq.p_empatados;
				arr_teams[i].puntos= eq.puntos;
				break;
			}
		}	
	}
}
	
void Torneo::create_player( string team, Jugador jd ){
	
	if(full_players(team)){
		cout << "[ERROR] Maximo de jugadores (Equipo : " << team << ") alcanzado..." << endl;
	}else{
		for(int i=0; i<max_teams; i++){
			if(arr_teams[i].nombre == team){
				for(int player = 0; player < max_players; player++){
					if(arr_teams[i].arr_players[player].nombre == ""){
						arr_teams[i].arr_players[player].nombre = jd.nombre;
						arr_teams[i].arr_players[player].identificador = jd.identificador;
						arr_teams[i].arr_players[player].posicion = jd.posicion;
						arr_teams[i].arr_players[player].media = jd.media;
						break;
					}		
				}
				break;
			}
		}
	}	
}

void Torneo::read_team( string team_ ){
	
	cout << "\n\n________ Informacion - Equipo : " << team_ << "\n" << endl;
	for(int team=0; team<max_teams; team++){
		if(arr_teams[team].nombre == team_){
			cout<< "Nombre del equipo  = " << arr_teams[team].nombre << endl;
			cout<< "Partidos ganados   = " << arr_teams[team].p_ganados << endl;
			cout<< "Partidos perdidos  = " << arr_teams[team].p_perdidos << endl;
			cout<< "Partidos empatados = " << arr_teams[team].p_empatados << endl;
			cout<< "Puntos             = " << arr_teams[team].puntos << endl;
			cout<< "Jugadores del equipo:    " << endl;
			for(int player=0; player<max_players; player++){
				if (arr_teams[team].arr_players[player].nombre != ""){
					cout << "-->  " << arr_teams[team].arr_players[player].nombre << " - ";
					cout << arr_teams[team].arr_players[player].identificador << " - ";
					cout << arr_teams[team].arr_players[player].posicion << " - ";
					cout << arr_teams[team].arr_players[player].media << endl;
				}
			}
			break;	
		}	
	}
}

void Torneo::read_player( string player_, string team_ ){
	
	cout << "\n\n________ Informacion - Jugador : " << player_ << "\n" << endl;
	for(int team=0; team<max_teams; team++){
		if(arr_teams[team].nombre == team_){
			cout<< "Nombre del equipo   = " << arr_teams[team].nombre << endl;
			for(int player=0; player<max_players; player++){
				if (arr_teams[team].arr_players[player].nombre == player_){
					cout << "Nombre del jugador  = " << arr_teams[team].arr_players[player].nombre << endl;
					cout << "Identificador       = " << arr_teams[team].arr_players[player].identificador << endl;
					cout << "Posicion            = " << arr_teams[team].arr_players[player].posicion << endl;
					cout << "Media del jugador   = " << arr_teams[team].arr_players[player].media << endl;
					break;
				}
			}
			break;	
		}	
	}	
}

void Torneo::update_team( string team_ , Equipo eq ){
	
	cout << "\n\n________ Actualizacion - Equipo : " << team_ << "\n" << endl;
	for(int i=0; i<max_teams; i++){
		if(arr_teams[i].nombre == team_){
			arr_teams[i].nombre = eq.nombre;
			arr_teams[i].p_ganados = eq.p_ganados;
			arr_teams[i].p_perdidos= eq.p_perdidos;
			arr_teams[i].p_empatados= eq.p_empatados;
			arr_teams[i].puntos= eq.puntos;
			break;
		}
	}	
}

void Torneo::update_player( string player_, string team_, Jugador jd ){
	
	cout << "\n\n________ Actualizacion - Jugador : " << player_ << "  -  Equipo : " << team_ << "\n" << endl;
	for(int i=0; i<max_teams; i++){
		if(arr_teams[i].nombre == team_){
			for(int j=0; j<max_players; j++){
				if(arr_teams[i].arr_players[j].nombre == player_){
					arr_teams[i].arr_players[j].nombre = jd.nombre;
					arr_teams[i].arr_players[j].identificador = jd.identificador;
					arr_teams[i].arr_players[j].posicion = jd.posicion;
					arr_teams[i].arr_players[j].media = jd.media;
					break;
				}	
			}
			break;
		}
	}	
}
	
void Torneo::delete_team( string team ){
	
	cout << "\n\n________ DELETE - Equipo : " << team << "\n" << endl;
	for(int i=0; i<max_teams; i++){
		if(arr_teams[i].nombre == team){
			Equipo empty_team;
			for(int j=i; j<max_teams; j++){
				if(j<max_teams-1){
					arr_teams[j] = arr_teams[j+1];
				}else{
					arr_teams[max_teams-1]= empty_team;
				}
			}
			break;
		}
	}
}

void Torneo::delete_player( string player, string team ){
	
	cout << "\n\n________ DELETE - Juagdor : " << player << " - Equipo : " << team << "\n" << endl;
	for(int i=0; i<max_teams; i++){
		if(arr_teams[i].nombre == team){
			for(int j=0; j< max_players; j++){
				if(arr_teams[i].arr_players[j].nombre == player){
					Jugador empty_player;
					for(int z=j; z<max_players; z++){
						if(z<max_players-1){
							arr_teams[i].arr_players[z] = arr_teams[i].arr_players[z+1];	
						}else{
							arr_teams[i].arr_players[max_players-1]= empty_player;
						}
					}
				}
				break;
			}
			break;
		}
	}
}

void Torneo::state(){
	
	cout << "\n\n________  Tabla del Torneo : \n" << endl;
	
	Ord();
	
	for(int i = 0; i<max_teams; i++){
		if(arr_teams_ord[i].nombre != ""){
			cout << "-->  " << arr_teams_ord[i].nombre << " - ";
			cout << arr_teams_ord[i].p_ganados << " - ";
			cout << arr_teams_ord[i].p_perdidos << " - ";
			cout << arr_teams_ord[i].p_empatados << " - ";
			cout << arr_teams_ord[i].puntos << " - \n" << endl;
		}
	}
	
	cout << "\n\n________ Tabla de jugadores por equipo: \n" << endl;
	for(int i = 0; i<max_teams; i++){
		if (arr_teams_ord[i].nombre != ""){
			cout << "Equipo : " << arr_teams_ord[i].nombre << endl;
			for(int j=0; j<max_players; j++){
				if(arr_teams_ord[i].arr_players[j].nombre != ""){
					cout << "-->  " << arr_teams_ord[i].arr_players[j].nombre << " - ";
					cout << arr_teams_ord[i].arr_players[j].identificador << " - ";
					cout << arr_teams_ord[i].arr_players[j].posicion << " - ";
					cout << arr_teams_ord[i].arr_players[j].media << " - " << endl;	
				}
			}
			cout << endl;
		}	
	}
}


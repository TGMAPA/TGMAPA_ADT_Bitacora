// Actividad Integral --> TORNEO

// Miguel Ángel Pérez Ávila A01369908

// Prueba de implementación del ADT de la estructura "Torneo" :

#include "ADT.hpp"


int main(){
	
	string nombre, team, nombre_jugador, posicion, player;
	int p_ganados, p_perdidos, p_empatados, id;
	float puntos, media;
	string aux;
	int max_teams;
	int max_players;
	Torneo::Equipo eq;
	Torneo::Jugador jd;
	
	
	//Solcitud de datos para constructo de Torneo
	cout << "\nIndica el maximo de Equipos para el Torneo            :  ";
	getline (cin, aux);
	max_teams = stoi(aux);
	cout << "Indica el maximo de jugadores por equipo para el Torneo :  ";
	getline (cin, aux);
	max_players = stoi(aux);
	
	Torneo torneo(max_teams, max_players);
	
	string op;	
	
	while(true){
		
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "=============== Menu de prueba ===============\n" << endl;
		cout << "1) Agregar Equipo "             << endl;
		cout << "2) Agregar Jugador  "           << endl;
		cout << "3) Consultar Equipo  "          << endl;
		cout << "4) Consultar Jugador "          << endl;
		cout << "5) Actualzar Equipo"            << endl;
		cout << "6) Actualzar Jugador "          << endl;
		cout << "7) Eliminar Equipo "            << endl;
		cout << "8) Eliminar Jugador "           << endl;
		cout << "9) Mostrar Estado del Torneo "  << endl;
		cout << "0) Salir \n\n\n"                << endl;
		
		cout << "Opcion deseada :  "             << endl;
		getline (cin, op);
		
		if (stoi(op) < 10 && stoi(op) >= 0){	
			
			if(stoi(op) == 0){
				break;
			}
			if(stoi(op) == 1){
				cout << "\n\n________ Agregar equipo : "  << endl;
				
				cout << "\nIngresa el nombre del equipo   :  ";
				getline (cin, eq.nombre); 
				
				cout << "\nIngresa los partidos ganados   :  ";
				getline (cin, aux);
				eq.p_ganados = stoi(aux);
				
				cout << "\nIngresa los partidos perdidos  :  ";
				getline (cin, aux);
				eq.p_perdidos = stoi(aux);
				
				cout << "\nIngresa los partidos empatados :  ";
				getline (cin, aux);
				eq.p_empatados = stoi(aux);
				
				cout << "\nIngresa los puntos acumulados  :  ";
				getline (cin, aux);
				eq.puntos = stof(aux);
				
				
				torneo.create_team( eq );
				cout << "\n[AVISO] Equipo creado exitosamente, pulsa [ENTER] para continuar...  " << endl;
				getche();
				
			}
			if(stoi(op) == 2){
				cout << "\n\n________ Agregar jugador : "  << endl;
				
				cout << "\nIngresa el nombre del equipo      :  ";
				getline (cin, team);
				
				cout << "\nIngresa el nombre del Jugador     :  ";
				getline (cin, jd.nombre);
				
				cout << "\nIngresa el numero id del Jugador  :  ";
				getline (cin, aux);
				jd.identificador = stoi(aux);
				
				cout << "\nIngresa la posicion del Jugador   :  ";
				getline (cin, jd.posicion);
				
				cout << "\nIngresa la media del Jugador      :  ";
				getline (cin, aux);
				jd.media = stof(aux);
				
				torneo.create_player( team, jd );
				cout << "\n[AVISO] Jugador del equipo " << team << " creado exitosamente, pulsa [ENTER] para continuar...  " << endl;
				getche();
				
			}		
			if(stoi(op) == 3){
				cout << "\nIngresa el nombre del equipo      :  ";
				getline (cin, team);
				torneo.read_team( team );
				getche();
			}			
			if(stoi(op) == 4){
				cout << "\nIngresa el nombre del equipo       :  ";
				getline (cin, team);
				cout << "\nIngresa el nombre del jugador      :  ";
				getline (cin, player);
				torneo.read_player( player, team );
				getche();
			}
			if(stoi(op) == 5){
				
				cout << "\nIngresa el nombre del equipo a modificar   :  ";
				getline (cin, team); 
				
				cout << "\nIngresa el nuevo nombre del equipo a modificar   :  ";
				getline (cin, eq.nombre); 
				
				cout << "\nIngresa los partidos ganados                     :  ";
				getline (cin, aux);
				eq.p_ganados = stoi(aux);
				
				cout << "\nIngresa los partidos perdidos                    :  ";
				getline (cin, aux);
				eq.p_perdidos = stoi(aux);
				
				cout << "\nIngresa los partidos empatados                   :  ";
				getline (cin, aux);
				eq.p_empatados = stoi(aux);
				
				cout << "\nIngresa los puntos acumulados                    :  ";
				getline (cin, aux);
				eq.puntos = stof(aux);
				
				torneo.update_team( team , eq );
				cout << "\n[AVISO] Equipo "<< team << "modificado exitosamente, pulsa [ENTER] para continuar...  " << endl;
				getche();
			}
			if(stoi(op) == 6){
				
				cout << "\nIngresa el nombre del equipo involucrado   :  ";
				getline (cin, team); 
				
				cout << "\nIngresa el nombre del jugador a modificar   :  ";
				getline (cin, player); 
				
				cout << "\nIngresa el nombre del Jugador     :  ";
				getline (cin, jd.nombre);
				
				cout << "\nIngresa el numero id del Jugador  :  ";
				getline (cin, aux);
				jd.identificador = stoi(aux);
				
				cout << "\nIngresa la posicion del Jugador   :  ";
				getline (cin, jd.posicion);
				
				cout << "\nIngresa la media del Jugador      :  ";
				getline (cin, aux);
				jd.media = stof(aux);
				
				torneo.update_player( player, team, jd );
				cout << "\n[AVISO] Jugador "<< player <<" del equipo " << team << " modificado exitosamente, pulsa [ENTER] para continuar...  " << endl;
				getche();
			}
			if(stoi(op) == 7){
				cout << "\nIngresa el nombre del equipo a eliminar       :  ";
				getline (cin, team);
				torneo.delete_team( team );	
				getche();
			}
			if(stoi(op) == 8){
				cout << "\nIngresa el nombre del equipo involucrado       :  ";
				getline (cin, team);
				cout << "\nIngresa el nombre del jugador a eliminar      :  ";
				getline (cin, player);
				torneo.delete_player( player, team );
				getche();
			}
			if(stoi(op) == 9){
				torneo.state();
				getche();
			}
			
		}else{
			cout << "[ERROR] Opcion fuera de rango, oprima [Enter] para continuar..." << endl;
			getche();	
		}
	}
	return 0;
}












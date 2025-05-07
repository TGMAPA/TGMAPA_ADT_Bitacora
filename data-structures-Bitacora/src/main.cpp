
// Actividad Integral --> BITACORA

// Miguel Ángel Pérez Ávila A01369908
// Tadeo Serrano Arriaga A01771239 

// Reolución de caso particular mediante la implementación del ADT de la estructura:

#include "ADT.hpp"


void preparararchivo() {
	
    FILE *file;
    char line[100];
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int monthNum;
    int day;
    int hour, minute, second;

    // Abrir archivo para lectura
    file = fopen("bitacora.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
    }

	// Crear archivo temporal para almacenar la data modificada
    FILE *tempFile = fopen("temporal.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
    }

	// Leer lineas del archivo, modificarlas y escribirlas en el archivo temporal
    while (fgets(line, sizeof(line), file) != NULL) {
        char newLine[100];
        char month[4];

		// Extraer la abreviación de la fecha para cada linea
        sscanf(line, "%s %d %d:%d:%d", month, &day, &hour, &minute, &second);

        // Encontrar el numero de mes correspondiente
        for (int i = 0; i < 12; i++) {
            if (strcmp(month, months[i]) == 0) {
                monthNum = i + 1;
                break;
            }
        }
		
		// Dar formato a la fecha como un solo string sin separaciones
        sprintf(newLine, "%02d%02d%02d%02d%02d %s", monthNum, day, hour, minute, second, line);
		
		// Escribir la linea modificada en el archivo
        fprintf(tempFile, "%s", newLine);
    }

    // Cerrar archivos
    fclose(file);
    fclose(tempFile);

    // Reemplazar archivo temporal por archivo original
    if (remove("bitacora.txt") != 0) {
        perror("Error deleting original file");
    }
    if (rename("temporal.txt", "bitacora.txt") != 0) {
        perror("Error renaming temporary file");
    }

}

string convertInputToOutput(const char* input) {
	const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char month[4];
    int day, hour, minute, second;
    sscanf(input, "%s %d %d:%d:%d", month, &day, &hour, &minute, &second);

    int monthNum = -1;
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            monthNum = i + 1;
            break;
        }
    }

    if (monthNum == -1) {
        cerr << "Invalid month in input: " << month << endl;
        return "";
    }

    char output[13];
    sprintf(output, "%02d%02d%02d%02d%02d", monthNum, day, hour, minute, second);
    return string(output);
}

int main(){

	//preparararchivo();   //--> Agrega columna clave a la bitacora para convertirse en el campo clave de la estructura
	//					   --> SOLO UTILIZAR LA PRIMERA VEZ QUE SE UTILIZA EL ARCHIVO BASE "bitacora.txt" PARA CARGAS POR LOTE
	
	// Crear el objeto Bitacora indicando el campo clave y el nombre del archivo principal para la bitacora del usuario
	string nom_Bit;		
	string indice;
	int iindice;
	
	cout << "\nIndica el nombre de tu bitacora :  ";
	getline (cin, nom_Bit);
	nom_Bit = nom_Bit + ".txt";
	cout << "Indica el indice del campo clave de tu bitacora :  ";
	getline (cin, indice);
	iindice = stoi(indice);
	
	Bitacora Bitac(iindice, nom_Bit);
	
	string op;	
	
	while(true){
		
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "=============== Menu de prueba ===============\n" << endl;
		cout << "1) Agregar evento "             << endl;
		cout << "2) Cargar eventos por lote "    << endl;
		cout << "3) Revisar Estado  "            << endl;
		cout << "4) Ordenar bitacora "           << endl;
		cout << "5) Buscar evento"               << endl;
		cout << "6) Consultar rango de eventos " << endl;
		cout << "7) Limpiar bitacora "           << endl;
		cout << "0) Salir \n\n\n"                << endl;
		
		cout << "Opcion deseada :  "             << endl;
		getline (cin, op);
		
		if (stoi(op) < 8 && stoi(op) >= 0){	
			
			if(stoi(op) == 0){
				break;
			}
			if(stoi(op) == 1){
				
				string evento;
				cout << "\nIngresa el nuevo evento (Recuerda seguir el formato de la bitacora que has definido) :  ";
				getline (cin, evento);
				
				Bitac.agregar_Evento(evento);
			}
			if(stoi(op) == 2){
				
				string archivobase;
				cout << "\nIngresa el nombre del archivo del cual se cargaran los eventos (eg. archivo.txt) :  ";
				getline (cin, archivobase);
				
				Bitac.agregar_Evento_lote(archivobase);
			}
			if(stoi(op) == 3){
				
				if (Bitac.Estado() == false){
					cout << "\nBitacora vacia\n\n";
					getche();
				}else{
					cout << "\nBitacora con contenido\n\n";
					getche();
				}
			}
			if(stoi(op) == 4){
				string inp_y_n;
				while(true){
					
					cout << "\nDesea mostrar los elementos de la bitacora ya ordenada? :  1) Si  2) No" << endl;
					getline(cin, inp_y_n);
					if (stoi(inp_y_n) > 2 && stoi(inp_y_n) < 1){
						cout << "[Error] Opción fuera de rango, ingresa 1) Si   o   un 2) No" << endl;
						cout << "Oprima [Enter] para continuar..."<< endl;
						getche();
					}else{
						break;
					}
				}
				if (stoi(inp_y_n) == 1){
					Bitac.ordenar(true);
					cout << "\nLa bitacora ha sido ordenada" << endl;
					getche();
				}else{
					Bitac.ordenar();
					cout << "\nLa bitacora ha sido ordenada" << endl;
					getche();
				}
			}
			if(stoi(op) == 5){
				
				string aux;
				cout << "\nIngresa el campo a buscar (eg. 'Oct 6 06:35:22' ) :  " << endl;
				getline (cin, aux);
				
				string campoclave = convertInputToOutput(aux.c_str());
				
				cout << "Evento encontrado : " << endl;
				Bitac.buscar(campoclave);
				getche();
			}
			if(stoi(op) == 6){
				
				string aux_inicial;
				string aux_final;
				cout << "\nIngresa el campo inicial (eg. 'Oct 6 06:35:22' ) :  " << endl;
				getline (cin, aux_inicial);
				cout << "\nIngresa el campo final   (eg. 'Oct 21 23:56:40' ) :  " << endl;
				getline (cin, aux_final);
				
				string campoclave_inicial = convertInputToOutput(aux_inicial.c_str());
				string campoclave_final   = convertInputToOutput(aux_final.c_str());
				
				cout << "Eventos en el rango " << aux_inicial << " a " << aux_final << " : \n" << endl;
				Bitac.consultar_rango(campoclave_inicial, campoclave_final);
				getche();
			}
			if(stoi(op) == 7){
				
				Bitac.vaciar();
				cout << "Limpieza realizada ... "<< endl;
				getche();
				
			}
			
		}else{
			cout << "[ERROR] Opcion fuera de rango, oprima [Enter] para continuar..." << endl;
			getche();	
		}
	}
	return 0; 
}
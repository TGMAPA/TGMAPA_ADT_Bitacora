

//  Definición de métodos  -> outline

#include "ADT.hpp"

// Privates =====================================================================================

// Merge - Comparación y unión de vectores   -   Orden O(n2)
void Bitacora::Mezcla( vector<string>&array, int first_ind, int mid, int end_ind ){
		
		int leftn = mid - first_ind+1;
		int rightn= end_ind - mid;
		vector<string> left(leftn);
		vector<string> right(rightn);
		
		for(int i=0; i < leftn; i++){
			
			left[i] = array[first_ind+i];
		}
		for(int j=0; j < (rightn); j++){
			
			right[j] = array[mid + j+1];
		}
		
		int i = 0;
		int j = 0;
		int k= first_ind;
		
		while(i < leftn && j < rightn){
			
			vector<string> auxline_array_left_i;
			istringstream ss(left[i]);
			
			for (string x; ss >> x;) {
		        auxline_array_left_i.push_back(x);    
		        if (ss.peek() == ' ')
		            ss.ignore();
		    }
		    
		    vector<string> auxline_array_right_j;
			istringstream ss1(right[j]);
			
			for (string x; ss1 >> x;) {
		        auxline_array_right_j.push_back(x);    
		        if (ss1.peek() == ' ')
		            ss1.ignore();
		    }
		    
			if(stoi(auxline_array_left_i[ind_campo_clave]) < stoi(auxline_array_right_j[ind_campo_clave])){
				array[k] = left[i];
				i++;
				k++;
			}else{
				array[k] = right[j];
				j++;
				k++;
			}
		}
		
		while(j < rightn){
			array[k] = right[j];
			j++;
			k++;
		}
		
		while(i < leftn){
			array[k] = left[i];
			i++;
			k++;
		}
	}
	
//Merge - Recursión    - Orden O(n2)
void Bitacora::mezclarecursion( vector<string>&array, int first_ind, int end_ind ){
	
	if(first_ind < end_ind){
		int mid = (end_ind+first_ind)/2;
		mezclarecursion(array, first_ind, mid);
		mezclarecursion(array, mid+1, end_ind);
		Mezcla(array, first_ind, mid, end_ind);	
	}
	
}
	
//Merge - retorno de vector     - Orden O(n2)
vector<string> Bitacora::ordenaMezcla( vector<string> array ){
	vector<string> auxarray = array;
	mezclarecursion(auxarray, 0, array.size()-1);
	return auxarray;
}

//Busqueda binaria - retorna indice de campo encontrada     -   Orden O(nlogn)
int Bitacora::busqBinaria( vector<string> array, string campo ){
	
	int start = 0;
	int end = event_ord.size()-1;
	int mean;
	
	while(true){
		mean= (start + end)/2;
		
		vector<string> auxline_array_mean;
		istringstream ss(array[mean]);
		
		for (string x; ss >> x;) {
	        auxline_array_mean.push_back(x);    
	        if (ss.peek() == ' ')
	            ss.ignore();
	    }
	
		if(auxline_array_mean[ind_campo_clave] == campo){
			return mean;
		}else{
			if (auxline_array_mean[ind_campo_clave] > campo){
				end = mean;
			}else{
				start = mean;
			}
		}
	}
	return -1;
}


// Public =======================================================================================

// Orden O(1)
void Bitacora::agregar_Evento( string evento ){
	
		// user input --> string armado de acuerdo a la estructura del evento del usuario
		
		ofstream archwrite;
		archwrite.open(Bit_name, ios_base::app);
		
		if(archwrite.fail()){
	        cout<<"No se pudo abrir el archivo" << Bit_name;
	        exit(1);
   		}
		
		string input;
	    input = evento + "\n";
	    archwrite << input;
		
		archwrite.close();
		
	}

// Orden O(n)
void Bitacora::agregar_Evento_lote( string archivo ){
		
	//   Cargar los eventos de un archivo del usuario al archivo de la bitacora
	string lectura;
	
	ifstream arch;
	arch.open(archivo, ios::in);
	
	ofstream archwrite;
	archwrite.open(Bit_name, ios_base::app);
	
	if(arch.fail()){
        cout<<"No se pudo abrir el archivo" << archivo;
        exit(1);
	}
	
	while(!arch.eof()){
        getline(arch, lectura);
        lectura = lectura + "\n";
        archwrite << lectura;
	}
	
	archwrite.close();
	arch.close();
}
	
// Orden O(1)
void Bitacora::vaciar(){
		
	// Borrar bitacora completa
	// Abre el archivo en modo de salida, que trunca el archivo si existe o crea un archivo vacío si no existe.
    ofstream arch(Bit_name, ios::out);

    if (!arch) {
        cerr << "Error opening file" << endl;
        return;
    }
	arch.close();
	
}	

// Orden O(1)
bool Bitacora::Estado(){
		
	// Retornar el estado de la bitacora:     LLeno = True  ,   Vacío = False
	
	ifstream arch(Bit_name);

    // Compruebe si el archivo está abierto y legible
    if (!arch.is_open()) {
        cerr << "Error opening file" << endl;
        return false; // No se puede determinar el vacío si el archivo no se puede abrir
    }

    char contenido;
    arch.get(contenido);

    if (arch.eof()) {
        return false; // archivo vacio
    } else {
        return true; // archivo con contenido
	}
}	

// Orden O(n)
void Bitacora::ordenar( bool mostrar  ){                                                                                                 
		
	// Tomar el indice del campo clave definido al instanciar la clase y aplicar metodo de ordenamiento
	// Escribir la bitacora ordenada en un nuevo .txt
	
	if (Estado() == false){
		
		cout<< "Error, la bitacora no tiene elementos para ordenar...\n";
	}else{
		
		//Crear archivo para depositar valores ordenados
		ofstream arch_ord;    
		//string arch_ord_name = Bit_name-".txt"+"_ordenado.txt" ;
		arch_ord.open("Bitacora_ordenada.txt", ios::out);
		//arch_ord.close();
		
		//Lectura de campos clave en eventos
		ifstream arch;
		arch.open(Bit_name, ios::in);
		
		if(arch.fail()){
	        cout<<"No se pudo abrir el archivo" << Bit_name;
	        exit(1);
		}
		
		vector<string> array_aux;
		string evento;
		
		while (getline(arch, evento)){
		    array_aux.push_back(evento);  
	    }
		
		vector<string> arrayordenado = ordenaMezcla(array_aux);
		
		if (mostrar){
			printf("Vector ordenado: \n");
		
			for (int i = 0; i< arrayordenado.size(); i++){
				cout << arrayordenado.at(i)  << endl;
			}
				
			cout << "\n" << arrayordenado.size()  << endl;
		}
		
		arch.close();
		string linea;
		
		for(int i ; i < arrayordenado.size() ; i++){
			linea = arrayordenado.at(i) + "\n";
			arch_ord << linea;
		}
		event_ord= arrayordenado;
		arch_ord.close();
	}	
}

// Orden O(nlogn)
void Bitacora::buscar( string campo ){
		
	// De la bitacora ordenada, buscar el campo clave 
	// Retornar evento 
	if (event_ord.size()!= 0){
		
		int ind_campo_encontrado = busqBinaria(event_ord, campo);
		
		cout << event_ord.at(ind_campo_encontrado) << endl;	
	}else{
		cout << "[ERROR] Es necesario ordenar la bitacora para poder realizar una busqueda..." << endl;	
	}	
}

// Orden O(n2)	
void Bitacora::consultar_rango( string campo_inicial, string campo_final ){
		
	// Desplegar de la bitacora los eventos desde el evento con el campo clave inicial hasta el campo clave final 
	if (event_ord.size()!= 0){
		int ind_campo_incial = busqBinaria(event_ord, campo_inicial);
		int ind_campo_final = busqBinaria(event_ord, campo_final);
		
		for (int i = ind_campo_incial; i <= ind_campo_final; i++){
			cout << event_ord.at(i) << endl;	
		}
	}else{
		cout << "[ERROR] Es necesario ordenar la bitacora para poder realizar una consulta por rango..." << endl;	
	}	
}
	

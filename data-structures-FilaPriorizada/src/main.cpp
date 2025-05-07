#include "ADT.hpp"

// Funcion para mostrar la fila del objeto
void show(vector<Input> fila){
	
	cout << "Data - Priority" << endl;
	if(!fila.empty()){
		for(int i=0; i< fila.size(); i++){	
			Input aux= fila.at(i);
			cout << aux.getdata() << "   - ";
			cout << aux.getprio()<< endl;
		}
	}	
}

//MAIN
int main(){
	
	PriorityQueue fila; // Instancia de clase
	
	//Muestra del estado incial de la fila
	cout << "INICIAL STATE ----------" << endl;
	cout << "SIZE : " << fila.size() << "\n\n\n" << endl;
	
	//Instancia de clase Input con valores iniciales
	Input aux(23,0);
	//Aplicación del método Push para todos los Inputs a continuación:
	cout << "\nAplicando Push : "  << endl;
	fila.push( aux );
	
	aux.changeD(24);
	aux.changePrior(1);
	fila.push( aux );
	
	aux.changeD(25);
	aux.changePrior(1);
	fila.push( aux );
	
	aux.changeD(26);
	aux.changePrior(1);
	fila.push( aux );
	
	aux.changeD(27);
	aux.changePrior(0);
	fila.push( aux );
	
	aux.changeD(28);
	aux.changePrior(0);
	fila.push( aux );
	
	aux.changeD(29);
	aux.changePrior(3);
	fila.push( aux );
	
	aux.changeD(30);
	aux.changePrior(8);
	fila.push( aux );
	
	aux.changeD(31);
	aux.changePrior(2);
	fila.push( aux );
	
	aux.changeD(32);
	aux.changePrior(1);
	fila.push( aux );
	
	aux.changeD(33);
	aux.changePrior(8);
	fila.push( aux );
	
	aux.changeD(34);
	aux.changePrior(2);
	fila.push( aux );
	
	aux.changeD(35);
	aux.changePrior(9);
	fila.push( aux );
	
	aux.changeD(36);
	aux.changePrior(3);
	fila.push( aux );
	
	//Funcion para mostrar la fila del objeto
	show(fila.getrow());
	
	//Método para obtener el tamaño de la fila
	int size= fila.size();
	cout << "\nSize: " << size << endl;
	
	
	//Aplicación del método pop para sacar el primer elemento de mayor prioridad 
	cout << "\nAplicando Pop : " << endl;
	fila.pop();
	
	//Funcion para mostrar la fila del objeto
	show(fila.getrow());
	
	//Método para obtener el primer elemento de mayor prioridad 
	int top= fila.top();
	cout << "\n\nTop: " << top << endl;
	
	//Método para obtener el estado de la fila
	if(fila.empty()){
		cout << "Empty : True"  << endl;
	}else{
		cout << "Empty : False"  << endl;
	}
	
	//Método para obtener el tamaño de la fila
	size= fila.size();
	cout << "Size: " << size << endl;
	
	return 0;
}
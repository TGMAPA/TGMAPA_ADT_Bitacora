
//  Definición de métodos  -> outline

#include "ADT.hpp"

// Public =======================================================================================

bool PriorityQueue::push( Input data ){
	
	if(data.getprio()<0 || data.getprio()>9){
		return false;
	}else{
		if(!empty()){
			for(int i=0; i<fila.size(); i++){
				if(fila.at(i).getprio() > data.getprio()){
					auto it = fila.begin()+i;
					fila.insert(it, data);
					return true;		
				}
				if(fila.at(i).getprio() == data.getprio()){
					int c=1;
					for(int j=i; j<fila.size(); j++){
						if(fila.at(j).getprio() != data.getprio() || j == fila.size()){
							auto it = fila.begin()+j;
							fila.insert(it, data);
							return true;
						}else{
							auto it = fila.begin()+j;
							fila.insert(it, data);
							return true;
						}
					}
				}
				if(fila.at(i).getprio() < data.getprio() && i==fila.size()-1){
					auto it = fila.begin()+i+1;
					fila.insert(it, data);
					return true;
				}
				if(i== fila.size()){
					fila.push_back(data);
					return true;
				}
			}	
		}else{
			fila.push_back(data);
			return true;
		}
	}	
}
	
bool PriorityQueue::pop(){
	if(!empty()){
		fila.pop_back();
		return true;
	}else{
		return false;
	}
}

int PriorityQueue::top(){
	if(!empty()){
		return fila.back().getdata();
	}else{
		return 0;
	}	
}

bool PriorityQueue::empty(){
	return fila.empty();
}

int PriorityQueue::size(){
	return(fila.size());
}

vector<Input> PriorityQueue::getrow(){
	
	return fila;
}

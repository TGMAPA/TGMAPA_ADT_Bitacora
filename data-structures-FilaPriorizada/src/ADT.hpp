#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdint.h>
#include <vector>

using namespace std;

class Input{
		
	private:
		int data;
		int priority;
		
	public:
		Input(int n, int p){
			data= n;
			priority= p;				
		}
		
	int getdata(){
		return data;
	}
	int getprio(){
		return priority;
	} 	
	void changeD(int newD){
		data= newD;
	}
	void changePrior(int newP){
		priority= newP;
	}
};
	
class PriorityQueue{
	
	private:
		vector<Input> fila;
					
	public:
		
		//Constructor de clase
		PriorityQueue(){
			
		}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool push( Input data );
	
	bool pop();
	
	int top();
	
	bool empty();
	
	int size();
	
	void show();
	
	vector<Input> getrow();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

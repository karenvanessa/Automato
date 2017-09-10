#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

enum class Estado {Q, SUMAR, RESTAR, ASIGNAR, Q4, ENTERO, Q6, LETRAS, Q8, Q9, Q10, Q11, IMPRIMIR, LETRAS1, NO_RECONOCIDO};

Estado reconocerExpresion(const string& inputString);

int main(){
	cout<<"Ingrese la Expresion: " << endl;
	string inputString;
	cin>>inputString;
	
	Estado ultimo=reconocerExpresion(inputString);
	if(ultimo == Estado::SUMAR){
		cout<<"La expresion ingresada existe yes suma " <<inputString <<endl;
	}else
	if(ultimo == Estado::RESTAR){
		cout<<"La expresion ingresada existe yes RESTA " <<endl;
	}else
	if(ultimo == Estado::ASIGNAR){
		cout<<"La expresion ingresada existe yes AIGNAR	 " <<endl;
	}	else
	if(ultimo == Estado::ENTERO){
		cout<<"La expresion ingresada existe y es entero " <<endl;
	}else
	if(ultimo == Estado::LETRAS){
		cout<<"La expresion ingresada existe y es letra " <<endl;
	}else
	if(ultimo == Estado::IMPRIMIR){
		cout<<"La expresion ingresada existe y es impresa " <<endl;
	}else
	if(ultimo == Estado::LETRAS1){
		cout<<"La expresion ingresada existe y es letras1 " <<endl;
	}else{
		cout<<"La expresion ingresada no es valida " <<endl;
	}
	
	cout<<endl;
	system("pause");
	system("cls");
	main();
	cout<<endl;
	return 0;
}
Estado reconocerExpresion(const string& inputString){
	unsigned int poscicion=0;
	Estado actual = Estado::Q;
	bool expresionRechazada = false;
	while(not expresionRechazada and poscicion < inputString.length()){
		char simbolo = inputString[poscicion];
		switch(actual){
			case Estado::Q:
				if(simbolo=='+'){
					actual = Estado::SUMAR;
					
				}else if(simbolo=='-'){
					actual=Estado::RESTAR;
				}else if(simbolo=='='){
					actual=Estado::ASIGNAR;
				}else if(isdigit(simbolo) && simbolo!=0){
					actual=Estado::Q4;
				}else if(isalpha(simbolo)&&simbolo!='p'){
					actual=Estado::Q6;
				}else if(simbolo == 'p'){
					actual=Estado::Q8;
				}else{
					expresionRechazada = true;
				}
				
				break;
			case Estado::SUMAR:
				if(simbolo!='+'){
					actual=Estado::Q;
					poscicion--;
				}
				break;
			case Estado::RESTAR:
				if(simbolo!='-'){
					actual=Estado::Q;
					poscicion--;
				}
				break;
			case Estado::ASIGNAR:
				if(simbolo!='='){
					actual=Estado::Q;
					poscicion--;
				}
				break;
			case Estado::Q4:
				if(isdigit(simbolo)){
					actual=Estado::Q4;
				}else if(!isdigit(simbolo)){ 	
					actual=Estado::ENTERO;
				}else {
					expresionRechazada=true;
				}
				break;
				
			case Estado::ENTERO:
				if(!isdigit(simbolo)){
					actual=Estado::Q;
					poscicion--;
				}
				//poscicion--;
				
				break;
				
			case Estado::Q6:
				if(isalpha(simbolo)){
					actual:Estado::Q6;
				}else if(simbolo!=isalpha(simbolo)){
					actual=Estado::LETRAS;
				}else{
					expresionRechazada=true;
				}
				break;
				
			case Estado::LETRAS:
				if(!isalpha(simbolo)){
					actual=Estado::Q;
					poscicion--;
				}
				break;
				
			case Estado::Q8:
				if(isalpha(simbolo)&&simbolo!='r'){
					actual=Estado::Q6;
				}else if(simbolo=='r'){
					actual=Estado::Q9;
				}else if(simbolo!=isalpha(simbolo)){
					actual=Estado::LETRAS1;
				}
				break;
				
			case Estado::Q9:
				if(isalpha(simbolo)&&simbolo!='i'){
					actual=Estado::Q6;
				}else if(simbolo=='i'){
					actual=Estado::Q10;
				}else if(simbolo!=isalpha(simbolo)){
					actual=Estado::LETRAS1;
				}
				break;
				
			case Estado::Q10:
				if(isalpha(simbolo)&&simbolo!='n'){
					actual=Estado::Q6;
				}else if(simbolo=='n'){
					actual=Estado::Q11;
				}else if(simbolo!=isalpha(simbolo)){
					actual=Estado::LETRAS1;
				}
				break;
				
			case Estado::Q11:
				if(isalpha(simbolo)&&simbolo!='t'){
					actual=Estado::Q6;
				}else if(simbolo=='t'){
					actual=Estado::IMPRIMIR;
				}else if(simbolo!=isalpha(simbolo)){
					actual=Estado::LETRAS1;
				}
				break;
				
			case Estado::IMPRIMIR:
				actual=Estado::IMPRIMIR;
				break;
				
			case Estado::LETRAS1:
				if(!isalpha(simbolo)){
					actual=Estado::Q;
					poscicion--;
				}
				break;
		}
		poscicion++;
		
	}
	
	if(expresionRechazada){
		return Estado::NO_RECONOCIDO;
	}
	return actual;
	
};



#include <iostream>
using namespace std;

const char *palabrastxt = "palabras.txt";

void ingreso_texto(){
	FILE *archivo = fopen(palabrastxt, "rb");
	
	string *lineas;
	lineas = new string [5];
	cout<<"----------------SU CODIGO AQUI--------------------"<<endl;
	//De momento solo lee 5 lineas para pruebas
	cin.ignore();
	for(int i=0;i<5;i++){
		cout<<i+1<<"| ";
		getline(cin, lineas[i]);
	}
	
	cout<<"\n\n-------------------Resultado-----------------------"<<endl;
	for(int i=0;i<5;i++){
		cout<<i+1<<"| "<<lineas[i]<<endl;
	}
	
	delete lineas;
	fclose(archivo);

};

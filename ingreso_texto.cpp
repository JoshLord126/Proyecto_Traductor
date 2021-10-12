#include <iostream>
using namespace std;

const char *palabrastxt = "palabras.txt";

void ingreso_texto(){
	FILE *archivo = fopen(palabrastxt, "rb");
	
	string prueba;
	cout<<"----------------SU CODIGO AQUI--------------------"<<endl;
	cout<<"Presione enter para empezar..."<<endl;
	cin.ignore();
	getline(cin, prueba);
	cout<<prueba;
	fclose(archivo);

};

#include <iostream>
#include <string.h>
#include "ingreso_texto.cpp"
using namespace std;

//const char *palabrastxt = "palabras.txt";

struct palabra{
	char nombre[50];
	char traduccion[50];
	char significado[150];
};

//Variables que ayudaran a no modificar un campo en especifico
string nombre_tem, traduccion_tem, significado_tem;

void crear_archivo(){
	FILE *archivo = fopen(palabrastxt, "r+b");
	if (!archivo){
		archivo = fopen(palabrastxt,"w+b");	
	}
}

void leer(int buscar){
	//Si buscar es igual a "1" la función buscara un item; Si buscar es distinto a "1" mostrara todos los items
	FILE *archivo = fopen(palabrastxt, "rb");
	palabra pal;
	int id=1, bus;	
	fread(&pal,sizeof(palabra),1,archivo);
	if(buscar == 1){
		cout<<"Ingrese el ID del objeto a buscar: ";
		cin>>bus;
	}

	do{	
		if(buscar == 1 && id == bus || buscar == 0){
			cout<<"ID: "<<id<<"\nNombre: "<<pal.nombre<<"\nTraduccion: "<<pal.traduccion<<"\nSignificado: "<<pal.significado<<endl<<endl;
		}
		fread(&pal,sizeof(palabra),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
	
	fclose(archivo);
}


void ayuda_remplazar(int help){
	FILE *archivo = fopen(palabrastxt, "rb");
	palabra pal;
	int id = 1;
	fread(&pal,sizeof(palabra),1,archivo);
	do{	
		if(id == help){
			nombre_tem = pal.nombre;
			traduccion_tem = pal.traduccion;
			significado_tem = pal.significado;
		}
		fread(&pal,sizeof(palabra),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
}


void ingreso(int cremo){
	//Si cremo es igual a "1" la función agregara valores; Si cremo es distingo a "1" la función modificara valores
	palabra pal;
	FILE* archivo = fopen(palabrastxt,"ab");	
	string str_nombre, str_traduccion, str_significado;

	fflush(stdin);
	if (cremo == 1){
		cout<<"¡--Ingreso de valores--!"<<endl<<endl;
	}else{
		fclose(archivo);
		FILE* archivo = fopen(palabrastxt,"r+b");
		int id;
		//Si no se quiere modificar un campo colocar "0"
		cout<<"Ingrese el ID que desea Modificar: ";
		cin>>id;
		fseek(archivo,(id-1) * sizeof(palabra),SEEK_SET);
		ayuda_remplazar(id);
		cin.ignore();
	}
	
	cout<<"Ingrese el nombre:";
	getline(cin,str_nombre);
	if(str_nombre == "0"){
		strcpy(pal.nombre, nombre_tem.c_str());
	}else{
		strcpy(pal.nombre, str_nombre.c_str());
	}
	
	cout<<"Ingrese la traduccion:";
	getline(cin,str_traduccion);
	if(str_traduccion == "0"){
		strcpy(pal.traduccion, traduccion_tem.c_str());
	}else{
		strcpy(pal.traduccion, str_traduccion.c_str());
	}
	
	
	cout<<"Ingrese el significado:";
	getline(cin,str_significado);
	if(str_significado == "0"){
		strcpy(pal.significado, significado_tem.c_str());
	}else{
		strcpy(pal.significado, str_significado.c_str());
	}
	
	//cin.ignore();
	fwrite(&pal,sizeof(palabra),1,archivo);
	fclose(archivo);
	leer(0);
}



int main(){
	
	crear_archivo();
	ingreso_texto();
	/*
	char in;
	leer(0);
	cout<<"Desea modificar o agregar (m/a)?..";
	cin>>in;
	if(in == 'a' || in == 'A'){
		ingreso(1);
	}else if(in == 'm' || in == 'M'){
		ingreso(0);
	}else{
		cout<<"Ingresa un valor correcto la proxima vez.";
	}
	*/

}


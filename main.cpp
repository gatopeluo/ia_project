#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <math.h>
#include "rangosDias.h"
#include "diasLibres.h"
#include "cobertura.h"
#include "advancer.h"

using namespace std;

class Instance{
	int days;
	int nurses;
	int shifts;
	bool sol;
	int** cov_mat;
	int** pref_mat;
	int* total_shifts;
	int* consec_shifts;
public:
	void setInstance();

};
/*		
void backtracker(int* array, int shifts, int iterator, int len){
	if(array[iterator]<shifts){
		array[iterator]++;
	}else if(iterator+1 < len){
		array[iterator]=1;
		backtracker(array, shifts, (iterator+1), len);
	}
}
*/

int main(int argc, char* argv[])
{
	std::clock_t start_s=clock();
	std::vector<int>input;
	int n;
	int p=3;		//el indice del input en que comienza la matriz de cobertura.
	fstream file;
	Instance instancia;
//Lectura de la data, siendo esta el argumento en la linea de comando
	file.open(argv[1]);
	int count=0;
	while(file >> n)
	{
		input.push_back(n);
		count++;
	}	
//Estos son los datos de enfermeras, dias y turnos(4). 
//Tambien se declaran las matrices de preferencia y cobertura 
	int nurses=input[0];
	int days=input[1];
	int shifts=input[2];
	int pref_matrix[nurses][days*shifts];
	
//definicion de variables
//usamos variables binarias x_{ijk}, para la enfermera que trabaja en un turno en un dia
	std::vector<int> variables;
	variables.reserve(nurses*days+1);	
	for(int i=0; i<nurses*days; i++){
		variables.push_back(0);
	}
	

//matriz de cobertura
	int **min_nurses2= new int* [days];
	
	for(int i=0; i<days; i++){
		min_nurses2[i]= new int [shifts];
	}
	
	for(int i=0; i<days; i++){
		for(int j=0; j<shifts; j++){
			min_nurses2[i][j] = input[p];
			p++;
		}
	}

//matriz de preferencia
	for(int i=0; i<nurses; i++){
		for(int j=0; j<(days*shifts); j++){
			pref_matrix[i][j] = input[p];
			p++;
		}
	}
	p+=2;
	
	int rango_dias_totales[2];
	int rango_dias_consecutivos[2];
	for(int i=0; i<2; i++){
		rango_dias_totales[i]=input[p];
		p++;
	}
	for(int i=0; i<2; i++){
		rango_dias_consecutivos[i]=input[p];
		p++;
	}
	int** rango_turnos_iguales_consecutivos=new int* [shifts];
	int** rango_turnos_iguales_totales=new int* [shifts];
	for(int i=0; i<shifts; i++){
		rango_turnos_iguales_totales[i]=new int[2];
		rango_turnos_iguales_consecutivos[i]=new int[2];
	}
	for(int i=0; i<shifts; i++){
			rango_turnos_iguales_consecutivos[i][0]=input[p];
			p++;
			rango_turnos_iguales_consecutivos[i][1]=input[p];
			p++;
			rango_turnos_iguales_totales[i][0]=input[p];
			p++;
			rango_turnos_iguales_totales[i][1]=input[p];
			p++;
	}

//matrices extra
	
/*testing un monton de weas, outputs y demases
	variables[0]=3;
	variables[1]=1;
	variables[2]=3;
	variables[3]=2;
	variables[4]=3;
	variables[5]=1;
	variables[6]=1;
	variables[7]=2;
	variables[8]=1;
	variables[9]=1;
	variables[10]=3;
	variables[11]=2;
	variables[12]=1;
	variables[13]=1;
	variables[14]=2;
	variables[15]=3;
	variables[16]=2;
	variables[17]=2;
	for(int i=0; i<days*nurses; i++){
		cout << variables[i] << " " ;
	}
	
	
	for(int i=0; i<5; i++){
		variables[i]=1;
	}
	*/
	std::vector<std::vector<int> > vars;
	bool cobertura_actual=revisar_cobertura(min_nurses2, variables, days, shifts, nurses);
		//variables[0]=4;
 	std::vector<int> solucion=advancer(variables, days, shifts, nurses, min_nurses2, rango_dias_totales, rango_dias_consecutivos, 0, vars);
 	std::clock_t stop_s=clock();
 	for (int j=0; j<vars[vars.size()-1].size(); j++){
		cout << vars[vars.size()-1][j] <<" ";
		if ((j+1)%nurses==0){
			cout << endl;
		}
	}
	cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC) << endl;
    cout << vars.size(); <<endl;
    return 0;
}
using namespace std;
int revisar_rangos_dias(int* rango_total, int* rango_consec, std::vector<int> variables, int days, int shifts, int nurses){
	int* contador=new int [nurses];
	int* contador_aux=new int [nurses];
	int* contador_min=new int [nurses];
	int* contador_max=new int [nurses];
	std::vector<int> consec;
	int tru=false;

	for(int i=0; i<nurses; i++){
		contador[i]=0;
		contador_aux[i]=0;
		contador_min[i]=0;
		contador_max[i]=0;
	}
	
	for(int j=0; j<nurses; j++){
		for(int i=j; i<variables.size(); i+=nurses){
			if(variables[i]!=shifts){
				contador[j]++;
				contador_aux[j]++;
			}else{
				consec.push_back(contador_aux[j]);
				contador_aux[j]=0;
			}	
		}
	}
	for(int i=0; i<nurses; i++){
		if(contador[i]>=rango_total[0] && contador[i]<=rango_total[1]){
			tru=0;
		} else {
			return (i+1);
		}
	}
	for(std::vector<int>::iterator it=consec.begin(); it!=consec.end(); it++){
			if( *it>=rango_consec[0] || *it<=rango_consec[1]){
				tru=0;
			} else {
				return 20;
			}
	}
	return tru;
}

int min_days(std::vector<int> vectr , int* rango_total, int nurses, int days, int shifts){
	int* contador = new int[nurses];
	for (int i=0; i< nurses; i++){
		contador[i]=0;
	}
	for(int j=0; j<nurses; j++){
		for(int i=j; i<nurses*days; i=i+nurses){
			if (vectr[i]!=shifts && vectr[i]!=0){
				contador[j]++;
			}
		}
	}
	for (int i=0; i<nurses; i++){
		if (contador[i]<rango_total[0]){
			delete [] contador;
			return (i+1);
		}
	}
	return 0;
}

int max_days(std::vector<int> vectr , int* rango_total, int nurses, int days, int shifts){
	int* contador = new int[nurses];
	for (int i=0; i< nurses; i++){
		contador[i]=0;
	}
	for(int j=0; j<nurses; j++){
		for(int i=j; i<vectr.size(); i+=nurses){
			if (vectr[i]!=shifts && vectr[i]!=0){
				contador[j]++;
			}
		}
	}
	for (int i=0; i<nurses; i++){
		if (contador[i]>rango_total[1]){
			delete [] contador;
			return i+1;
		}
	}
	return 0;
}

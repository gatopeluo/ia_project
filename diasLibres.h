int revisar_dias_libres(std::vector<int> variables, int** cobertura, int days, int shifts, int nurses){
	int* aux= new int [shifts];
	for(int i=0; i<=shifts; i++){
		aux[i]=0;
	}	
	int** aux2 = new int* [days];
	int aux1=0;
	for(int i=0; i<variables.size(); i++){
		if(variables[i]==0){
			for (int k = 0; k < shifts; ++k){
				aux[k]++;
			}
		}
		for(int j=0; j<shifts; j++){
			if(variables[i]==(j+1)){
				aux[j]=aux[j]+1;
			}
		}
		if((i+1)%nurses==0){
			aux2[(i+1)/nurses-1] = new int [shifts];
			std::copy(aux, aux+shifts, aux2[(i+1)/nurses-1]);
			for(int j=0; j<shifts; j++){
				aux[j]=0;
			}
		}
	}
	for(int i=0; i<days; i++){
		for(int j=0; j<(shifts-1); j++){
			if (cobertura[i][j]<aux2[i][j]){
				return i;
			}
		}
	}
	return days;
}
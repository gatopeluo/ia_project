bool revisar_cobertura(int** &cobertura, std::vector<int> &variables, int day, int shifts, int nurses){
	int* aux= new int [shifts];
	for(int i=0; i<=shifts; i++){
		aux[i]=0;
	}	
	int** aux2 = new int* [day];
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
	delete [] aux;
	for(int i=0; i<day; i++){
		for(int j=0; j<shifts; j++){
			if (cobertura[i][j]<=aux2[i][j]) aux1++;
		}
	}
	for(int i=0; i<day; i++){
		delete [] aux2[i];
	}
	delete [] aux2;

	if(aux1==day*shifts){
		
		return true;
	}
	return false;
}

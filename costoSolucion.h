int costoSol(std::vector<int> &solucion, int** &preferencia, int days, int nurses, int shifts){
	unsigned int costo=0;
	int contador=0;
	for(int i=0; i<nurses*days; i++){
		for (int j=1; j<=shifts; j++){
			if (solucion[i]==j){
				costo+=1;
			}	
		}

	}
	return 0;
}

bool solsUnicas(std::vector<int> sol, std::vector<std::vector<int> > soluciones){
	bool res=true;
	if (soluciones.size()>1){
		for (int i=0; i<sol.size(); i++){
			if (sol[i]!=soluciones[0][i]){
				res=false;
			}
		}
	}else{
		return false;
	}
	return res;
}
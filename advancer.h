using namespace std;
void advancer(std::vector<int> &vectr, int days, int shifts, int nurses, int** cobertura, int* rango_total, int* rango_consec, int position){
	std::vector<int>::iterator aux=vectr.begin();
	std::vector<int>::iterator fin=vectr.end();
	fin--;
	int start = clock();
	bool backjump=false;
	int act_pos=0;
	for(int i=days*nurses; i>position; i--){
		vectr[i]=0;
	}
	while(aux!=vectr.end()){
		for (int j=0; j<nurses*days; j++){
			cout << vectr[j] <<" ";
		}
		cout<<endl;
		if (revisar_cobertura(cobertura, vectr, days, shifts, nurses) && (*aux==0)){
			*aux=shifts;
			backjump=false;
			/*if (max_days(vectr, rango_total, nurses, days, shifts)!=0){
				cout <<max_days(vectr, rango_total, nurses, days, shifts)<<endl;
				*aux=1;
			}*/			
		}else if (revisar_cobertura(cobertura, vectr, days, shifts, nurses) && (*aux!=0)){
			if(!backjump){
				aux++;
				backjump=false;	
			} else {
				if (*aux<shifts-1){
					(*aux)++;
					backjump=false;
				}else if((*aux)==shifts-1){
					(*aux)=0;
					aux--;
					backjump=true;
				}else if((*aux)==shifts){
					(*aux)=1;
					backjump=false;
				}
			}

		}else if (!revisar_cobertura(cobertura, vectr, days, shifts, nurses)){
			if (*aux==shifts){
				(*aux)=1;
			}else if((*aux)<shifts-1){
				(*aux)++;
			}else if((*aux)==shifts-1){
				(*aux)=0;
				aux--;
				backjump=true;
			}
		}

		if(aux == fin){
			if (min_days(vectr, rango_total, nurses, days, shifts)!=0){
				int nurse=min_days(vectr, rango_total, nurses, days, shifts);
				bool aux_day=true;
				while(aux_day){
					for(int i=0; i<(nurses-nurse); i++){
						(*aux)=0;
						aux--;
					}
					if((*aux)==shifts){
						backjump=true;
						aux_day=false;
					}else{
						for(int i=0; i<nurse; i++){
							(*aux)=0;
							aux--;	
						}
						
					}
				}
			}
		}
		/*for (int j=0; j<nurses*days; j++){
			cout << vectr[j] <<" ";
		}
		cout<<endl;*/		
	}
}
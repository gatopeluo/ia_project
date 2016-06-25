using namespace std;
std::vector<int> advancer(std::vector<int> &vectr, int days, int shifts, int nurses, int** cobertura, int* rango_total, int* rango_consec, int position){
	std::vector<int>::iterator aux=vectr.begin();
	std::vector<int>::iterator fin=vectr.end();
	fin--;
	std::clock_t start = clock();
	bool backjump=false;
	int act_pos=0;
	std::vector<int> variables;
	variables.reserve(nurses*days+1);
	for(int i=days*nurses; i>position; i--){
		vectr[i]=0;
	}
	while(aux!=vectr.end()){
		/*for (int j=0; j<nurses*days; j++){
			cout << vectr[j] <<" ";
		}*/
		//cout<<endl;
		if (revisar_cobertura(cobertura, vectr, days, shifts, nurses) && (*aux==0)){
			*aux=shifts;
			backjump=false;			
		}else if (revisar_cobertura(cobertura, vectr, days, shifts, nurses) && (*aux!=0)){
			if(!backjump){
				aux++;
				backjump=false;	
			} else {
				if (*aux<shifts-1){
					(*aux)++;
					backjump=false;
					/*if (max_days(vectr, rango_total, nurses, days, shifts)!=0){
						*aux=shifts;
						aux++;
					}*/
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
		if ((clock()-start)/double(CLOCKS_PER_SEC)>120){
			for (int j=0; j<nurses*days; j++){
				cout << vectr[j] <<" ";
				variables.push_back(vectr[j]);
			}
			cout << endl;
			return variables;
		}
		/*for (int j=0; j<nurses*days; j++){
			cout << vectr[j] <<" ";
		}
		cout<<endl;*/		
	}
	for (int j=0; j<nurses*days; j++){
		variables.push_back(vectr[j]);
	}
	return variables;
}
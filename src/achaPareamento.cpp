#include "achaPareamento.hpp"

void achaPareamento(mapProf &professores,mapEsc &escolas,map<int,int> &parPE,map<int,ii> &parEP){
	while(1){
		int escola=0;
		int professor=0;
		FOR2(i,1,51){
			ii profs=parEP[i];
			//cout << "checando escola = " << i << " (" << parEP[i].first << "," << parEP[i].second << ")" << endl;
			if(!profs.first || !profs.second){
				FOR2(j,1,101){
					//cout << "checando professor " << professores[j] << endl;
					if(professores[j].nivel==escolas[i].preferencia
						&& professores[j].prefere(i,parPE[j]))
					{
						escola=i;
						professor=j;
						break;
					}
				}
				if(escola || professor)break;
			}
		}
		if(!escola || !professor)return;



		associa(parPE,parEP,escola,professor);
		//professores[professor].removePreferenciasMenores(escola);


		cout << "escola = " << escola << " (" << parEP[escola].first << "," << parEP[escola].second << ")" << endl;
	}
}

void associa(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor){
	if(!parEP[escola].first)parEP[escola].first=professor;
	else if(!parEP[escola].second)parEP[escola].second=professor;
	else return;

	desassocia(parPE,parEP,parPE[professor],professor);
	parPE[professor]=escola;
}

void desassocia(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor){
	if(!escola)return;

	if(parEP[escola].first==professor)parEP[escola].first=0;
	else if(parEP[escola].second==professor)parEP[escola].second=0;

	parPE[professor]=0;
}

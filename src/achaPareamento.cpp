#include "achaPareamento.hpp"

void achaPareamento(mapProf &professores,mapEsc &escolas,map<int,int> &parPE,map<int,ii> &parEP){
	while(1){
		bool changed=false;
		FOR2(escola,1,51){
			FOR2(professor,1,101){
				if(professores[professor].prefere(escola,parPE[professor])){
					if(escolaPrefere(escola,professor,escolas,professores,parEP[escola].first)){
						// cout << "professor " << professores[professor] << " escola " << escolas[escola] << endl;
						changed=true;
						desassocia(parPE,parEP,escola,parEP[escola].first);
						associa(parPE,parEP,escola,professor);
						//professores[professor].removePreferenciasMenores(escola);
					}
					if(escolaPrefere(escola,professor,escolas,professores,parEP[escola].second)){
						// cout << "professor " << professores[professor] << " escola " << escolas[escola] << endl;
						changed=true;
						desassocia(parPE,parEP,escola,parEP[escola].second);
						associa(parPE,parEP,escola,professor);
						//professores[professor].removePreferenciasMenores(escola);
					}
				}
			}
		}
		if(!changed)return;
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

bool escolaPrefere(int escola,int novoProf,mapEsc &escolas,mapProf &professores,int professor){
	if(professor==0)return true;
	if(professores[novoProf].nivel<escolas[escola].preferencia)return false;
	if(professores[professor].nivel<escolas[escola].preferencia)return true;
	return false;
}

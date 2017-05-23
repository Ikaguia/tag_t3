#include "professor.hpp"

professor::professor(int i,const array<int,5>& pref,int n){
	id=i;
	preferencia=pref;
	nivel=n;
}

void professor::removePreferenciasMenores(int id){
	int it=0;
	for(;it<5;it++)if(preferencia[it]==id)break;
	for(it++;it<5;it++)preferencia[it]=0;
}

bool professor::prefere(int escola,int escolaAtual){
	//cout << "professor " << id << " e" << escola << " ea" << escolaAtual << endl;
	if(!escolaAtual)return true;
	if(escola==escolaAtual)return false;
	for(int pref:preferencia){
		if(pref==escola)return true;
		if(pref==escolaAtual || !pref)return false;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const professor& obj){
	return os << "P(" << obj.id << ", " << obj.nivel << "): (" <<
		"E" << obj.preferencia[0] << ", " <<
		"E" << obj.preferencia[1] << ", " <<
		"E" << obj.preferencia[2] << ", " <<
		"E" << obj.preferencia[3] << ", " <<
		"E" << obj.preferencia[4] << ")";
}

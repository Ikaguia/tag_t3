#include "professor.hpp"

professor::professor(int i,const array<int,5>& pref,int n){
	id=i;
	preferencia=pref;
	nivel=n;
}

//Metodo utilizado para remover preferencias, no caso do professor ser associado a uma escola com preferencia maior que as que serao removidas
void professor::removePreferenciasMenores(int id){
	int it=0;
	for(;it<5;it++)if(preferencia[it]==id)break;
	for(it++;it<5;it++)preferencia[it]=0;
}

//Verifica a preferencia do professor por escolas
bool professor::prefere(int escola,int escolaAtual){
	//cout << "professor " << id << " e" << escola << " ea" << escolaAtual << endl;
	
	//Se o professor nao estiver associado a uma escola, ele prefere a escola nova
	if(!escolaAtual)return true;
	
	//Se a nova escola for a mesma escola a qual o professor ja esta associado, ele nao prefere a escola nova
	if(escola==escolaAtual)return false;
	
	//Checa a lista de preferencias do professor, em busca da escola nova
	for(int pref:preferencia){
		
		//Se a escola nova for encontrada primeiro na lista, significa que ela esta acima da escola atual
		if(pref==escola)return true;
		
		//Se a escola atual for encontrada primeiro na lista, significa que ela esta acima da escola nova
		//A condicao tambem checa se a lista ja foi percorrida por completo
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

#include "achaPareamento.hpp"

//OBS: Tratar 'aa' como uma letra 'a' craseada. Tratar 'eh' como uma letra 'e' com acento agudo.

//Metodo principal do trabalho, que realiza o pareamento entre os vertices "professores" e "escolas"
void achaPareamento(mapProf &professores,mapEsc &escolas,map<int,int> &parPE,map<int,ii> &parEP){
	//"Looping infinito", pois a condicao de parada pode ser encontrada tanto procurando professores quanto procurando escolas
	while(1){
		
		bool changed=false;
		
		//"for" das escolas, percorre todas as escolas no objeto escolas
		FOR2(escola,1,51){
			
			//"for" dos professores, percorre todas os professores no objeto professores
			FOR2(professor,1,101){
				
				//Verifica a preferencia do professor e disponibilidade pelo metodo "prefere", na classe "professor"
				if(professores[professor].prefere(escola,parPE[professor])){
					
					//Verifica a preferencia da escola pelo metodo "escolaPrefere"
					if(escolaPrefere(escola,professor,escolas,professores,parEP[escola].first)){
						// cout << "professor " << professores[professor] << " escola " << escolas[escola] << endl;
						changed=true;
						
						//Caso o pareamento verificado for melhor do que o atual, substitui a escola do professor pela escola analisada
						desassocia(parPE,parEP,escola,parEP[escola].first);
						associa(parPE,parEP,escola,professor);
						
						
						//professores[professor].removePreferenciasMenores(escola);
					}
					
					//A condicao abaixo eh parecida com a anterior pois eh necessario verificar a preferencia da escola
					//para ambos os professores cadastrados na escola sendo analisada
					else if(escolaPrefere(escola,professor,escolas,professores,parEP[escola].second)){
						// cout << "professor " << professores[professor] << " escola " << escolas[escola] << endl;
						changed=true;
						
						//Caso o pareamento verificado for melhor do que o atual, substitui a escola do professor pela escola analisada
						desassocia(parPE,parEP,escola,parEP[escola].second);
						associa(parPE,parEP,escola,professor);
						
						
						//professores[professor].removePreferenciasMenores(escola);
					}
				}
			}
		}
		//Se nao houve mudancas no pareamento, significa que o pareamento perfeito ja foi atingido, logo, interrompe o metodo
		if(!changed)return;
	}
}

//Metodo que "associa" um professor aa uma escola, ja tomando o cuidado de selecionar se eh o primeiro ou segundo professor da escola
void associa(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor){
	
	//Verifica qual posicao da escola esta livre para associar o professor e o associa
	if(!parEP[escola].first)parEP[escola].first=professor;
	else if(!parEP[escola].second)parEP[escola].second=professor;
	else return;

	//Realiza a desassociacao da escola anterior do professor associado aa nova
	desassocia(parPE,parEP,parPE[professor],professor);
	
	//Associa o professor aa escola nova
	parPE[professor]=escola;
}

//Metodo que "desassocia" um professor de uma escola, alterando ambas as "direcoes" da matriz de adjacencia
void desassocia(map<int,int> &parPE,map<int,ii> &parEP,int escola,int professor){
	
	//Se nao ha escola associada ao professor, nao ha o que desassociar
	if(!escola)return;

	//Se nao ha professor associado aa escola, nao ha o que desassociar
	if(!professor)return;

	//Verifica se o professor esta na primeira ou segunda posicao da escola a ser desassociada e o desassocia
	if(parEP[escola].first==professor)parEP[escola].first=0;
	else if(parEP[escola].second==professor)parEP[escola].second=0;

	//Desassocia o professor aa escola
	parPE[professor]=0;
}

//Metodo que verifica se um professor eh melhor para a escola do que um dos atuais, de acordo com o nivel de habilitacao dele
bool escolaPrefere(int escola,int novoProf,mapEsc &escolas,mapProf &professores,int professor){
	
	//Se nao ha professor recebido, o professor novo eh preferido
	if(professor==0)return true;
	
	//Se o novo professor nao tiver nivel de habilitacao necessario para a escola, ele nao eh preferido pela escola
	if(professores[novoProf].nivel<escolas[escola].preferencia)return false;
	
	//Se o professor antigo nao tiver nivel de habilitacao necessario para a escola, ele nao eh preferido pela escola
	if(professores[professor].nivel<escolas[escola].preferencia)return true;
	return false;
}

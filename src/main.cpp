#include "common.hpp"
#include "professor.hpp"
#include "escola.hpp"
#include "achaPareamento.hpp"

//OBS: Tratar 'aa' como uma letra 'a' craseada. Tratar 'eh' como uma letra 'e' com acento agudo.

int main(){
	
	//Definicao dos vetores de vertices para professores e escolas
	mapProf professores;
	mapEsc escolas;
	
	//Definicao das matrizes de adjacencia entre Professores-Escolas e Escolas-Professores
	map<int,int> pareamentoPE;
	map<int,ii> pareamentoEP;

	//Cadeia de caracteres que armazena cada linha do arquivo texto lido
	string line;

	//Leitura do arquivo texto "entrada.txt", com tratamento de erro
	ifstream file("entrada.txt");
	if(!file.is_open()){
		cout << "Erro ao abrir arquivo \"entrada.txt\", o programa ira encerrar agora" << endl;
		return EXIT_FAILURE;
	}

	getline(file,line);getline(file,line);getline(file,line);//ignora tres linhas de comentario + linha vazia

	FOR2(i,1,101){//ler 100 professores
		getline(file,line);
		sscanf(line.c_str(),"(P%d, %d): (E%d, E%d, E%d, E%d, E%d)",
			&professores[i].id,
			&professores[i].nivel,
			&professores[i].preferencia[0],
			&professores[i].preferencia[1],
			&professores[i].preferencia[2],
			&professores[i].preferencia[3],
			&professores[i].preferencia[4]
		);
	}

	getline(file,line);getline(file,line);getline(file,line);//ignora tres linhas de comentario + linha vazia

	FOR2(i,1,51){//ler 50 escolas
		getline(file,line);
		sscanf(line.c_str(),"(E%d):(%d)",&escolas[i].id,&escolas[i].preferencia);
	}

	file.close();

	// //printa de novo so para ver que leu direito
	// FOR2(i,1,101)cout << professores[i] << endl;cout << endl;
	// FOR2(i,1,51)cout << escolas[i] << endl;cout << endl;

	//Metodo principal do programa: o que encontra o pareamento perfeito entre professores e escolas
	achaPareamento(professores,escolas,pareamentoPE,pareamentoEP);

	
	//Impressao do resultado do pareamento
	for(auto p:pareamentoPE)cout << "Professor " << p.first << " pareado com escola " << p.second << endl;
	for(auto p:pareamentoEP)cout << "Escola " << p.first << " pareado com professores " << p.second.first << " e " << p.second.second << endl;

	return 0;
}
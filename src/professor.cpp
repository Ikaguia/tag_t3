#include "professor.hpp"

professor::professor(int i,const array<int,5>& pref,int n){
	id=i;
	preferencia=pref;
	nDeHabilitacoes=n;
}

std::ostream& operator<<(std::ostream& os, const professor& obj){
	return os << "P(" << obj.id << ", " << obj.nDeHabilitacoes << "): (" <<
		"E" << obj.preferencia[0] << ", " <<
		"E" << obj.preferencia[1] << ", " <<
		"E" << obj.preferencia[2] << ", " <<
		"E" << obj.preferencia[3] << ", " <<
		"E" << obj.preferencia[4] << ")";
}

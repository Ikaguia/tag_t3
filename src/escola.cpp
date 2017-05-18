#include "escola.hpp"

escola::escola(int i,int pref):id{i},preferencia{pref}{}

std::ostream& operator<<(std::ostream& os, const escola& obj){
	return os << "E(" << obj.id << "):(" << obj.preferencia << ")";
}

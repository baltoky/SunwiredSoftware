#include "ErrorSystem.h"

namespace Fission{
	#define E(e) #e
	std::string f_ErrorNames[] = {ERRORS(E)};
	#undef E

	std::string getError(f_Error e){
		return f_ErrorNames[e];
	}

}


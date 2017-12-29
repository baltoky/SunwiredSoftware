#ifndef FIS_ERROR_SYSTEM
#define FIS_ERROR_SYSTEM

#include <string>

#define ERRORS(E) \
	E(Critical_Error),\
	E(Runtime_Error),\
	E(Unknown_Error)

namespace Fission{

	#define f_E(e) e
	enum f_Error{
		ERRORS(f_E),
		NUM_ERRORS
	};
	#undef f_E

	std::string getError(f_Error e);

}

#endif

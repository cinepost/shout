#ifndef __SCN_Registry_h__
#define __SCN_Registry_h__

#include <string>
#include <vector>

#include "SCN_IOTranslator.h"

typedef SCN_IOTranslator *(*IO_Constructor)();

class SCN_IORegistry {
	public:
		SCN_IORegistry();

		void	addIOTranslator(std::std::vector<char *> extensions, IO_Constructor);

	private:
		std::std::vector<char *> translatorsByExtension;
};


#endif // __SCN_Registry_h__
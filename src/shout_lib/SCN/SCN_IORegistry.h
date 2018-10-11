#ifndef __SCN_Registry_h__
#define __SCN_Registry_h__

#include <string>
#include <vector>
#include <map>

#include "SCN_IOTranslator.h"

typedef SCN_IOTranslator *(*IO_Constructor)();
typedef std::vector<std::string> *(*IO_Extensions)();

class SCN_IORegistry {
	public:
		SCN_IORegistry();

		void	          addIOTranslator(IO_Extensions extensions, IO_Constructor constructor);
		SCN_IOTranslator *getTranslatorByExt(std::string ext);

	private:
		std::map<std::string, IO_Constructor> translatorsByExtension;
};


#endif // __SCN_Registry_h__
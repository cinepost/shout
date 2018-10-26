#include <string>
#include <vector>

#include "SCN_IORegistry.h"

void SCN_IORegistry::addIOTranslator(IO_Extensions extensions, IO_Constructor constructor) {
	for (auto ext : *extensions()) {
		translatorsByExtension.insert ( std::pair<std::string, IO_Constructor>(ext, constructor) );
	}
}

SCN_IOTranslator *SCN_IORegistry::getTranslatorByExt(std::string ext) {
	return translatorsByExtension[ext]();
}
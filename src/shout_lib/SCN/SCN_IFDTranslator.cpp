#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include <string>
#include <iostream>
#include <sstream>

#include "SCN_IFDTranslator.h"


SCN_IFDTranslator::SCN_IFDTranslator() {
  BOOST_LOG_TRIVIAL(debug) << "IFD file translator constructed!";
}


SCN_IFDTranslator::~SCN_IFDTranslator() {
  BOOST_LOG_TRIVIAL(debug) << "IFD file translator destructed!";
}


const char *SCN_IFDTranslator::formatName() const{
    return "Mantra IFD";
}


int SCN_IFDTranslator::checkExtension(const char *name) {
    if (strcmp(name, ".ifd"))return 0;
    return 1;
}


void SCN_IFDTranslator::getFileExtensions(std::vector<std::string> &extensions) const{
    extensions.insert(extensions.end(), _ifd_extensions.begin(), _ifd_extensions.end());
}


int SCN_IFDTranslator::checkMagicNumber(unsigned magic) {
    return 0;
}


SCN_Scene::IOStatus SCN_IFDTranslator::fileLoad(SCN_Scene *scn, std::istream *in, bool ate_magic) {
  std::string line;
  while (std::getline(*in, line)) {
    std::cout << line << std::endl;
  }
    return true;
}


// factory methods

std::vector<std::string> *SCN_IFDTranslatorFactory::myExtensions() {
    return &_ifd_extensions;
}



SCN_IOTranslator *SCN_IFDTranslatorFactory::myConstructor() {
    return new SCN_IFDTranslator();
}
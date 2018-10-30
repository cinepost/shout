#include <string>
#include <iostream>
#include <sstream>
 
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "SCN_OBJTranslator.h"


SCN_OBJTranslator::SCN_OBJTranslator() {
  BOOST_LOG_TRIVIAL(debug) << "OBJ file translator constructed!";
}


SCN_OBJTranslator::~SCN_OBJTranslator() {
  BOOST_LOG_TRIVIAL(debug) << "OBJ file translator destructed!";
}


const char *SCN_OBJTranslator::formatName() const{
    return "Wavefront OBJ";
}


int SCN_OBJTranslator::checkExtension(const char *name) {
    if (strcmp(name, ".obj"))return 0;
    return 1;
}


void SCN_OBJTranslator::getFileExtensions(std::vector<std::string> &extensions) const{
    extensions.insert(extensions.end(), _obj_extensions.begin(), _obj_extensions.end());
}


int SCN_OBJTranslator::checkMagicNumber(unsigned magic) {
    return 0;
}


SCN_Scene::IOStatus SCN_OBJTranslator::fileLoad(SCN_Scene *scn, std::istream *in, bool ate_magic) {
  std::string line;
  while (std::getline(*in, line)) {
    
  }
  return true;
}


// factory methods

std::vector<std::string> *SCN_OBJTranslatorFactory::myExtensions() {
    return &_obj_extensions;
}



SCN_IOTranslator *SCN_OBJTranslatorFactory::myConstructor() {
    return new SCN_OBJTranslator();
}
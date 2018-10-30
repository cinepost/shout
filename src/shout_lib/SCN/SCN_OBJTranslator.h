#ifndef __SCN_OBJTranslator_h__
#define __SCN_OBJTranslator_h__

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <SCN/SCN_IOTranslator.h>

static std::vector<std::string> _obj_extensions = {".obj"};


class SCN_OBJTranslator : public SCN_IOTranslator {
  public:
    SCN_OBJTranslator();
    ~SCN_OBJTranslator();

    const char         *formatName() const;
    int                 checkExtension(const char *name);

    void                getFileExtensions(std::vector<std::string> &extensions) const;

    // Method to check if the given magic number matches the magic number. Return true on a match.
    int                 checkMagicNumber(unsigned magic);

    SCN_Scene::IOStatus fileLoad(SCN_Scene *scn, std::istream *in, bool ate_magic);
};


class SCN_OBJTranslatorFactory {
    public:
        // factory methods
        static SCN_IOTranslator         *myConstructor();
        static std::vector<std::string> *myExtensions();
};

#endif // __SCN_OBJTranslator_h__
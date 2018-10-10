#include <dlfcn.h>
#include <stdlib.h>
#include <boost/format.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

#include "utils.h"
#include "display.h"

Display::Display(std::string driver_name) {
	char *error;
    
    boost::format libdspy_name(expandEnvVars("${SHOUT_HOME}/lib/d_%1%.so"));
	libdspy_name % driver_name;

	void* lib_handle = dlopen(libdspy_name.str().c_str(), RTLD_NOW);//RTLD_LOCAL|RTLD_LAZY);
    if (!lib_handle) {
        printf("[%s] Unable to load library: %s\n", __FILE__, dlerror());
        exit(1);
    } else {
    	m_OpenFunc = (PtDspyOpenFuncPtr)dlsym(lib_handle, "DspyImageOpen");
        if ((error = dlerror()) != NULL) {
            fputs(error, stderr);
            exit(1);
        }
        m_CloseFunc = (PtDspyCloseFuncPtr)dlsym(lib_handle, "DspyImageClose");
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }
    }

    this->driver_name = driver_name;
    BOOST_LOG_TRIVIAL(debug) << "Display \"" << driver_name << "\" constructed using driver " << libdspy_name.str();
}

Display::~Display() {
    BOOST_LOG_TRIVIAL(debug) << "Display \"" << driver_name << "\" destructed!";
}

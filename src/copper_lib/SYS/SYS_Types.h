#ifndef __SYS_Types__
#define __SYS_Types__

#include "SYS_Compiler.h"

/* Include system types */
#include <limits>
#include <sys/types.h>

// <sys/types.h> defines macros with the names 'major' and 'minor'.
// glibc 2.25+ emits deprecation warnings for this, so eventually the include
// of <sys/sysmacros.h> will be removed and the undef'ing won't be necessary.
#undef major
#undef minor

/*
 * Integer types
 */
typedef signed char     int8;
typedef unsigned char   uint8;
typedef short           int16;
typedef unsigned short  uint16;
typedef int             int32;
typedef unsigned int    uint32;

typedef unsigned char   uchar;
#ifndef MBSD
typedef unsigned int    uint;
#endif

/*
 * Unicode code units for Unicode Transformation Formats
  Copper uses UTF8.
 */
typedef char            utf8;
typedef unsigned short  utf16;
typedef unsigned int    utf32;

#endif // __SYS_Types__
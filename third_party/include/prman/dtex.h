#ifndef DTEX_H
#define DTEX_H

/*
# ------------------------------------------------------------------------------
#
# Copyright (c) 2003-2010 Pixar Animation Studios. All rights reserved.
#
# The information in this file (the "Software") is provided for the
# exclusive use of the software licensees of Pixar.  Licensees have
# the right to incorporate the Software into other products for use
# by other authorized software licensees of Pixar, without fee.
# Except as expressly permitted herein, the Software may not be
# disclosed to third parties, copied or duplicated in any form, in
# whole or in part, without the prior written permission of
# Pixar Animation Studios.
#
# The copyright notices in the Software and this entire statement,
# including the above license grant, this restriction and the
# following disclaimer, must be included in all copies of the
# Software, in whole or in part, and all permitted derivative works of
# the Software, unless such copies or derivative works are solely
# in the form of machine-executable object code generated by a
# source language processor.
#
# PIXAR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
# ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT
# SHALL PIXAR BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES
# OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
# WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
# ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
# SOFTWARE.
#
# Pixar
# 1200 Park Ave
# Emeryville CA 94608
#
# ------------------------------------------------------------------------------
*/

/*
 * libdtex
 *
 * This library provides the structures and functions necessary to create,
 * load, and modify deep texture map files.  It maintains a tile cache
 * under the covers, making it possible to work on files without loading
 * them entirely into memory.
 *
 * The API supports an arbitrary number of images in a single file, each
 * with its own resolution, tile size, and view matrices.
 *
 * The library can read and write old deep shadow files in addition to
 * newer, more general deep texture files.  Deep shadow files are
 * limited to a single sub-image, but otherwise have the same API as the
 * newer interface.
 */


#include "prmanapi.h"

/* The following struct types aren't exported; users may only
   access members through the API calls defined below. */

typedef struct DtexFile DtexFile;
typedef struct DtexImage DtexImage;
typedef struct DtexMetadata DtexMetadata;
typedef struct DtexPixel DtexPixel;
typedef struct DtexCache DtexCache;
typedef struct DtexDeepFilter DtexDeepFilter;

/* DtexCreate and DtexOpen let the user specify their
   own file access functions, in case read() and write() aren't
   good enough.  Following are the types for these functions: */

typedef void *(*DtexCreateFunc)(const char *name);
typedef void *(*DtexOpenFunc)(const char *name, const char *mode);
typedef long (*DtexReadFunc)(void *handle, char *data, long seek, long size);
typedef long (*DtexWriteFunc)(void *handle, char *data, long seek, long size);
typedef void (*DtexCloseFunc)(void *handle);

/* DtexAccessor encapsulates the various file access functions.  A
   pointer to one of these can be passed to DtexCreate() or
   DtexOpen() if nonstandard file access methods are needed. */

typedef struct DtexAccessor 
{
    DtexCreateFunc createFunc;    /* function to create a file */
    DtexOpenFunc openFunc;        /* function to open a file */
    DtexReadFunc readFunc;        /* function to read from a file handle */
    DtexWriteFunc writeFunc;      /* function to write to a file handle */
    DtexCloseFunc closeFunc;      /* function to close a file handle */
} DtexAccessor;

/* The following types are similiar, but add support for large 2GB+ files
 * with 64 bit offsets. */

typedef long (*DtexLargeReadFunc)(void *handle, char *data, RtUInt64 seek, long size);
typedef long (*DtexLargeWriteFunc)(void *handle, char *data, RtUInt64 seek, long size);

typedef struct DtexLargeAccessor
{
    DtexLargeReadFunc readFunc;        /* function to read from a file handle */
    DtexLargeWriteFunc writeFunc;      /* function to write to a file handle */
} DtexLargeAccessor;

/* Tile compression type. */
typedef enum DtexCompression
{
    DTEX_COMPRESSION_NONE = 0,
    DTEX_COMPRESSION_RLE = 2,
    DTEX_COMPRESSION_LZW = 3,
    DTEX_COMPRESSION_HUFFMAN = 5,
    DTEX_COMPRESSION_ZIP = 6
} DtexCompression; 

/* Type of data stored with each pixel. (Note that the depth is always
   stored as a float. */
typedef enum DtexDataType
{
    DTEX_TYPE_BYTE = 1,
    DTEX_TYPE_SHORT = 2,
    DTEX_TYPE_WORD = 3,
    DTEX_TYPE_FLOAT = 4,
    DTEX_TYPE_HALF = 5
} DtexDataType;

/* Error codes: */

enum{
    DTEX_NOMETADATA  = -14,   /* Metadata entry was not found or was invalid */
    DTEX_BADCHANNEL  = -13,   /* Channel mismatch between pixels or tiles */
    DTEX_READONLY    = -12,   /* Attempt to modify file loaded as read only */
    DTEX_CAPACITY    = -11,   /* Tried to go past 2GB on a small capacity file */
    DTEX_TILECOMPRESSION  = -10,  /* Something happened during tile compression */
    DTEX_UNFINISHED  =  -9,   /* Illegal operation on pixel with unresolved
				 compression state */
    DTEX_RANGE       =  -8,   /* Out of range parameter */
    DTEX_NOMEM       =  -7,   /* Ran out of memory */
    DTEX_EMPTY       =  -6,   /* Illegal operation on an empty structure */
    DTEX_NOIMAGE     =  -5,   /* The specified image was not found */
    DTEX_UNSUPPORTED =  -4,   /* The specified operation is not supported. */
    DTEX_BADFILE     =  -3,   /* File was corrupt */
    DTEX_NOFILE      =  -2,   /* File was not found or was invalid */
    DTEX_ERR         =  -1,   /* File was not found or was invalid */
    DTEX_NOERR       =   0    /* No worries */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 *********************************************************************
 *  CACHE FUNCTIONS:
 *********************************************************************
 *
 * The following functions are used to maintain deep texture tile
 * caches.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern DtexCache * DtexCreateCache(int numTiles,
				   DtexAccessor *accessor);
/*
 * create a new tile cache.  accessor specifies a set of I/O functions
 * to use upon faults.  If accessor is NULL, standard system calls
 * are used.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern DtexCache * DtexCreateReadOnlyCache(
                        int numTilesPerThread, DtexAccessor *accessor,
                        DtexLargeAccessor *largeAccessor);
/*
 * Create a new tile cache that is safe for read-only use in a
 * multithreaded environment.  Accessor specifies a set of I/O functions to
 * use upon faults.  LargeAccessor provides 64-bit offset versions.  If
 * either is NULL, standard system call are used.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexSetLargeAccessor(DtexCache *c,
                        DtexLargeAccessor *accessor);

/*
 * Specify a set of I/O functions to use upon faults when dealing with
 * large capacity files.  If not called, default implementations using
 * standard system calls are used.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexDestroyCache(DtexCache *c);

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexSyncCache(DtexCache *dsc);

/*
 * write out all modified tiles of all files in the cache, causing the
 * files on disk to reflect any changes that have been made.
 */

/* ----------------------------------------------------------------- */

/*
 *********************************************************************
 *  FILE OPENING/CLOSING FUNCTIONS:
 *********************************************************************
 *
 * The following functions are used to create new deep texture files,
 * or to open existing deep texture files.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexIsDeepFile(const char *name,
                                   DtexCache *cache,
                                   int *version);
/*
 * Attempt to open a file with the given filename, and check whether it
 * appears to be a deep texture file.  Returns DTEX_NOERR and sets version
 * to the file format version if the file is a deep texture file.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexOpenFile(const char *name,
			const char *mode,
			DtexCache *cache,
			DtexFile **result);
/* 
 * Open a deep texture file with the given filename, managed by the
 * given cache.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexCreateFile(const char *name,
			  DtexCache *cache,
			  DtexFile **result);

/* 
 * Open a deep texture file with the given filename, managed by the
 * given cache. 
 */

/* ----------------------------------------------------------------- */

#define DTEX_CREATE_FILE_PARAMS_VERSION 1

typedef struct {
    int version;                // DTEX_CREATE_FILE_PARAMS_VERSION
    int forceFormatVersion;
} DtexCreateFileParams ;

PRMANAPI extern int DtexCreateFileEx(const char *name,
			  DtexCache *cache,
			  DtexFile **result,
                          DtexCreateFileParams *params);

/* 
 * Open a deep texture file with the given filename, managed by the
 * given cache. Force new format
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexFileVersion(DtexFile *f);
/*
 * return the format version of the given file.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexGetFileMetadata(DtexFile *f, DtexMetadata **result);
/*
 * return a handle to the file-wide metadata.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexAddImage(DtexFile *f,
			const char *name,
			int numChan,
			int w, int h,
			int tw, int th,      /* tile width and height */
			float *NP,
			float *Nl,
			enum DtexCompression compression,
			enum DtexDataType datatype,
			DtexImage **result);
/*
 * Add an image to the given file.
 */

/* ----------------------------------------------------------------- */

#define DTEX_DEEPOPACITY_VERSION 1
#define DTEX_AREASHADOW_VERSION 1
#define DTEX_DEEPCOMP_VERSION 1

#define DTEX_ADD_IMAGE_PARAMS_VERSION 1

typedef struct {
    int version;                // DTEX_ADD_IMAGE_PARAMS_VERSION
    char const *formatType;     // "deepopacity", "areashadow", or "deepcomp"
    int formatVersion;          // DTEX_DEEPOPACITY_VERSION, etc.
} DtexAddImageParams;

PRMANAPI extern int DtexAddImageEx(DtexFile *f,
			const char *name,
			int numChan,
			int w, int h,
			int tw, int th,      /* tile width and height */
			float *NP,
			float *Nl,
			enum DtexCompression compression,
			enum DtexDataType datatype,
                        DtexImage **result,
                        DtexAddImageParams *params);
/*
 * Add an image to the given file.  May take additional parameters such as
 * formatType and formatVersion.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexCountImages(DtexFile *f);

/*
 * Return the number of images in the given file.
 */

/* ----------------------------------------------------------------- */

/* 
 * If the given file contains an image with the given name, return a
 * pointer to it.  Returns DTEX_NOIMAGE if the given image doesn't exist. 
 * The resulting pointer is guaranteed to be valid until DtexClose() is
 * called on the containing
 * file.
 */

PRMANAPI extern int DtexGetImageByName(DtexFile *f,
			      const char *name,
			      DtexImage **result);

/* ----------------------------------------------------------------- */

/*
 * Return the nth image from the given file.  Returns DTEX_NOFILE
 * if the file doesn't exist, or DTEX_NOIMAGE if the given image doesn't
 * exist.  The resulting pointer is guaranteed to be valid until
 * DtexClose() is called on the containing file.
 */

PRMANAPI extern int DtexGetImageByIndex(DtexFile *f,
			       int index,
			       DtexImage **result);

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexClose(DtexFile *ds);
/*
 * close a deep texture file, writing out all modified tiles.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexSync(DtexFile *ds);

/*
 * write out all modified tiles of deep texture "ds", causing the
 * file on disk to reflect any changes that have been made.
 */

/* ----------------------------------------------------------------- */

/*
 *********************************************************************
 *  FILE ACCESS FUNCTIONS:
 *********************************************************************
 *
 * The following functions let the user access and modify the
 * contents of an open deep texture file.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexWidth(DtexImage *i);
/*
 * return the width of the given image in pixels
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern char *DtexImageName(DtexImage *i);
/*
 * return the name of the given image.  The resulting pointer is
 * guaranteed to be valid until DtexClose() is called on the containing
 * file.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexNumChan(DtexImage *i);
/*
 * return the number of channels in the given image
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexHeight(DtexImage *i);
/*
 * return the height of the given image in pixels
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexTileWidth(DtexImage *i);
/*
 * return the width of the tiles in the given image, in pixels
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexTileHeight(DtexImage *i);
/* 
 * return the height of the tiles in the given deep texture, in pixels
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexNP(DtexImage *i, float *NP);
/*
 * copy the projection matrix from the given image to NP.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexNl(DtexImage *i, float *Nl);
/*
 * copy the light-space matrix from the given image to Nl.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern DtexCompression DtexGetCompression(DtexImage *i);
/*
 * return the compression type of the image.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern DtexDataType DtexGetDataType(DtexImage *i);
/*
 * return the data type of the image.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexGetImageMetadata(DtexImage *i, DtexMetadata **result);
/*
 * return a handle to the metadata associated with the image.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexSetPixelData(DtexImage *img,
			    int x, int y,
			    int numChan,
			    int numPoints,
			    float *data);
/*
 * copy the given pixel data into pixel x,y of the specified image. 
 * numChan indicates how many channels of data are being provided,
 * and numPoints indicates how many points there are.  data should
 * point to numPoints*(numChan+1) floats.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexSetPixel(DtexImage *img,
			int x, int y,
			DtexPixel *pix);
/*
 * copy the given pixel into pixel x,y of the specified image.  pix
 * must have either the same number of channels as img, or one channel.
 *
 * If pix has any unresolved compression state, DTEX_ERR is returned.
 * Call DtexFinishPixel before you use DtexSetPixel.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexGetPixel(DtexImage *img,
			int x, int y,
			DtexPixel *pix);
/*
 * copy the pixel at position x,y in "ds" into the given pixel
 * structure.  The pixel structure is resized if necessary, and if
 * the number of channels in pix is different than the number of
 * channels in img, pix is modified to match.
 *
 * Returns DTEX_NOERR if no error, DTEX_RANGE if the requested pixel
 * is outside the image, or DTEX_BADFILE if the file is found to be
 * corrupt.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexEval(DtexImage *img,
		    int x, int y,
		    float z,
		    int n,
		    float *data);
/*
 * look up the pixel's interpolated value at depth z, and put the
 * result in data.  n must indicate how many floats are
 * allocated in data, and must be no less than the number of
 * channels in the image.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexGetZRange(DtexImage *img,
			 int x, int y,
			 float *min,
			 float *max);
/*
 * computes the range over which the specified pixel is defined.
 * if the pixel is non-empty, the range is returned in min and max
 * and the function returns DTEX_NOERR.  If the pixel is empty, 
 * DTEX_EMPTY is returned and min and max are undefined.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexGetMeanDepth(DtexImage *img,
			    int x, int y,
			    float *mean,
			    float *alpha);
/*
 * computes the mean depth found in the pixel and the overall
 * coverage.  This is useful for displaying deep images.
 */

/* ----------------------------------------------------------------- */

/*
 *********************************************************************
 *  METADATA STRUCTURE FUNCTIONS:
 *********************************************************************
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexMetadataSet(DtexMetadata *meta,
                                    char const *token,
                                    void const *value);
/*
 * Add or update a metadata field associated with an image or file. The
 * token is a string specifying the type and name of the field and
 * is given in the standard RenderMan style, e.g., ``float bbox[6]``.
 * Supported types are: float, int, point, color, vector, normal, hpoint,
 * matrix, and string.
 *
 * The associated data to write is given by the value pointer.  In the
 * case of string data, this should point to ``char *`` pointers that
 * point to the strings themselves (i.e., argv style).  If the value
 * pointer is null, the metadata field will be removed if it exists.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexMetadataCount(DtexMetadata *meta);
/*
 * Return how many metadata fields the image has.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexMetadataGetByIndex(DtexMetadata *meta,
                                           int index,
                                           char const **token,
                                           void const **value);
/*
 * The metadata fields are retrieved in no particular order.
 * This function is simply a convenience for enumerating all attached
 * metadata.  Returns DTEX_NOMETADATA if the given field doesn't exists.
 * The resulting pointers, stored in token and value are valid until
 * either DtexClose() is called on the containing file, or until
 * DtexSetMetadata() modifies this particular field.  Data behind these
 * pointers must not be changed.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexMetadataGetByName(DtexMetadata *meta,
                                          char const *name,
                                          char const **token,
                                          void const **value);
/*
 * Metadata fields may also be retrieved by an unadorned name.
 */

/* ----------------------------------------------------------------- */

/*
 *********************************************************************
 *  PIXEL STRUCTURE FUNCTIONS:
 *********************************************************************
 *
 * Because deep texture pixels are varying in size, a pixel's storage
 * must be dynamically allocated.  This library
 * provides a type, DtexPixel, which allows users to build and evaluate
 * pixels.  The structure is fairly heavyweight because it stores
 * auxiliary information related to compression.  We don't recommend
 * allocating an entire image of these structures yourself; keep
 * a small number of DtexPixel's around, and use DtexSetPixel to
 * modify a DtexImage.
 *
 * The following functions let the user create, modify, and
 * destroy DtexPixel's.  Pixels may be cleared with DtexClearPixel().
 * New datapoints may be added (in increasing Z order) with
 * DtexAppendPixel().  If compression is used, a pixel must
 * be DtexFinish()'ed before lookups can be performed in the pixel.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern DtexPixel * DtexMakePixel(int numChan);
/*
 * create a DtexPixel structure.  It should be destroyed with
 * DtexDestroyPixel, not free().
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern void DtexDestroyPixel(DtexPixel *pix);
/*
 * free a DtexPixel structure.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexClearPixel(DtexPixel *pix, int numChan);
/*
 * set the specified pixel structure to be empty.  Its allocation
 * stays around, but the pixel is marked as empty.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexEmptyPixel(DtexPixel *pix);

/*
 * Clear out all the allocation in the given pixel, but don't free
 * the pixel itself.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexSpecifyPixel(DtexPixel *pix,int numChan,int numPoints,
			    float *data);

/*
 * Set the given pixel to have numChan channels and set its data
 * directly.  Assumes no compression.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexIsPixelMonochrome(DtexPixel *p);

/*
 * Return 1 if the specific pixel has duplicates for all its values,
 * zero otherwise.  If the pixel has no control points, returns 1.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexPixelGetNumChan(DtexPixel *pix);
/*
 * Return the number of channels in the pixel.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexPixelGetNumPoints(DtexPixel *pix);
/*
 * Return the number of control points in the pixel.  Returns zero
 * if there are no control points, -1 if the point has unresolved
 * compression state.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexPixelGetPoint(DtexPixel *pix, int i, float *z, float *data);
/*
 * Get the i'th control point in the given pixel.  If the indicated
 * control point is accessible, z and data are set, and DTEX_NOERR
 * is returned.  If the pixel does not exist, DTEX_NOPOINT is
 * returned and *z and *data are undefined.  If the pixel has
 * unresolved compression state, DTEX_UNFINISHED is returned and
 * *z and *data are undefined.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexPixelSetPoint(DtexPixel *pix, int i, float z, float *data);

/*
 * Modify the i'th control point in the given pixel.  If the indicated
 * control point is accessible, and if the supplied z is legal,
 * the pixel is modified and DTEX_NOERR
 * is returned.  If the pixel does not exist, DTEX_NOPOINT is
 * returned.  If the pixel has unresolved compression state,
 * DTEX_UNFINISHED is returned and *z and *data are undefined.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexCopyPixel(DtexPixel *dest,
			 DtexPixel *src);
/*
 * copy src to dest.  If dest has a different number of channels
 * than src, dest is modified to match. This includes current
 * compression state.
 */


/* ----------------------------------------------------------------- */
PRMANAPI extern int DtexMergePixel(DtexPixel *dest,
                         DtexPixel *src);
/*
 * Merges data from src to dest - the resulting data in dest will have
 * all control points that were present in both pixels. Both pixels
 * must have the same number of channels, and must not have unresolved
 * compression state.
 */

PRMANAPI extern int DtexMergePixelEx(DtexPixel *dest, DtexPixel *src,
                                     int rgbChannel, int alphaChannel);
/*
 * Like DtexMergePixel, this merges data from src into dest.  In addition,
 * it can correctly handle embedding geometry in volumes and overlapping
 * volumes.  These volume segments are flagged with a negative alpha and
 * extend to the next sample in the pixel.  There must be at least one
 * non-volume sample marking the end of chain (which may be completely
 * transparent).
 *
 * This assumes a four channel RGBA pixel function when splitting and
 * merging volume regions. The rgbChannel must be the index of the first
 * color channel, with the assumption that all three color channels are
 * contiguous. The alphaChannel must be the index of the alpha channel.
 * Any additional channels will be copied unchanged from the most recent
 * volume sample.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexFinishPixel(DtexPixel *dest);
/*
 * If the specified pixel is in "compress mode" (non-zero compression),
 * this function finishes compression and sets compression error to zero.
 * This must be called before any lookups on the pixel structure.
 *
 * If the pixel already has a zero compression error, this function has
 * no effect.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexAppendPixel(DtexPixel *pix,
			   float z,
			   int n,
			   float *data,
			   float error);
/*
 * add a data point to the end of the specified pixel.  n must
 * specify how many floats are stored in data, and must match
 * the number of channels in the pixel.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexEvalPixel(DtexPixel *pix,
			 float z,
			 int n,
			 float *data);
/*
 * evaluate the pixel's function at depth z, and put the
 * result in data.  n must indicate how many floats are
 * allocated in data, and must be no less than the number of
 * channels in the image.
 */


/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexCompositePixel(DtexPixel *pix,
			 int rgbChannel,
                         int alphaChannel,
			 float *data);
/*
 * Composite a four channel RGBA pixel function and store the result
 * in data. rgbChannel must be the index of the first color channel,
 * with the assumption that all three color channels are
 * contiguous. alphaChannel must be the index of the alpha
 * channel. data must be a buffer of at least four floats. If the
 * pixel is empty, DTEX_EMPTY is returned and data is filled with
 * zeros. Otherwise, data[0], data[1], and data[2] contain the
 * composited color values and data[3] contains the composited alpha
 * value, and DTEX_NOERR is returned.
 */

    
/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexGetPixelZRange(DtexPixel *pix,
			      float *min,
			      float *max);
/*
 * computes the range over which the specified pixel is defined.
 * if the pixel is non-empty, the range is returned in min and max
 * and the function returns DTEX_NOERR.  If the pixel is empty, 
 * DTEX_EMPTY is returned and min and max are undefined.  If the pixel
 * has unresolved compression state, DTEX_UNFINISHED is returned and
 * min and max are undefined.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexPrintPixel(DtexPixel *p);
/*
 * print a representation of the given pixel to stdout
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern int DtexAveragePixels(int n,
			     DtexPixel **pixels,
			     float *weights,
			     float error,
			     DtexPixel *result);
/*
 * compute the weighted pointwise average of the given pixels and put the
 * result in result.
 */

/* ----------------------------------------------------------------- */

PRMANAPI extern void DtexPrintStats(void);

/* ----------------------------------------------------------------- */

/* Create a new Deep filter */

PRMANAPI extern DtexDeepFilter *DtexCreateDeepFilter(void);

/* Create a new Deep filter */

#define DTEX_CREATE_DEEP_FILTER_PARAMS_VERSION 2

typedef struct {
    // v1...
    int version;
    float error;
    float simplifyerror;
    int assumesmooth;
    int logfunction;
    // v2...
    float deptherror;
} DtexCreateDeepFilterParams;

PRMANAPI extern DtexDeepFilter *DtexCreateDeepFilterEx(DtexCreateDeepFilterParams *p);

/* Destroy a new Deep filter */

PRMANAPI extern void DtexDestroyDeepFilter(DtexDeepFilter *filter);

/*
 * Prepare the given filter to take samples.  numChan is the number of
 * channels (in addition to z) per delta.  numSamples is the number of
 * samples in the filter.  numDeltas is an array with numSamples values
 * indicating, for each sample, how many deltas are in that sample.
 * filterWeights is an array with numSamples floats indicating, for each
 * sample, what that sample's filterweight is.  totalNumDeltas is the
 * sum of the values in numDeltas.
 *
 * When this function is done, all the samples will be set up.  The
 * user can then run through and fill in the actual deltas.
 */

PRMANAPI extern float *DtexGetDeepFilterData(DtexDeepFilter *filter,
				    int numChan,
				    int numSamples,
				    int *numDeltas,
				    float *filterWeights,
				    int totalNumDeltas);

/* ----------------------------------------------------------------- */

/* Execute the given filter to produce point data.  pointData must
   contain enough space to hold "totalNumDeltas" deltas as specified
   in DtexGetDeepFilterData.

   If assumeSmooth is non-zero, the computation will assume that the
   underlying function is smooth, and that any discontinuities encountered
   are part of the sampling error.  It will thus not try to reproduce
   discontinuities.

*/

PRMANAPI extern int DtexComputeDeepPointData(DtexDeepFilter *filter,
				    float *pointData,
				    float error,
				    int assumeSmooth);

/* Execute the given filter to produce point data.  pointData must
   contain enough space to hold "totalNumDeltas" deltas as specified
   in DtexGetDeepFilterData.

   If assumeSmooth is non-zero, the computation will assume that the
   underlying function is smooth, and that any discontinuities encountered
   are part of the sampling error.  It will thus not try to reproduce
   discontinuities.

    The filter is assumed to have been configured with relevant error
    and other configurations via DtexCreateDeepFilterEx
*/


PRMANAPI extern int DtexComputeDeepPointDataEx(DtexDeepFilter *filter,
				    float *pointData);

/* ----------------------------------------------------------------- */

/* Given a series of points, compress it. */

PRMANAPI extern int DtexCompressPointData(float *pointData,
				 int numChan,
				 int numPoints,
				 float *result,
				 float error);

/* ----------------------------------------------------------------- */

/* Compress one pixel and put the result in another.  Doesn't work
 * in place.  (dest must not == src.)
 */

PRMANAPI extern int
DtexCompressPixel(DtexPixel *src,DtexPixel *dest,float error);

/* ----------------------------------------------------------------- */

PRMANAPI extern void
DtexQueryMemory(unsigned long *current,unsigned long *peak);

#ifdef __cplusplus
}
#endif

#endif /* DTEX_H */


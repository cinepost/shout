#ifndef _RX_H
#define _RX_H
/* $Revision: #4 $  (Pixar - RenderMan Division)  $Date: 2014/12/10 $ */
/*
# ------------------------------------------------------------------------------
#
# Copyright (c) 2010 Pixar Animation Studios. All rights reserved.
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

#include "prmanapi.h"
#include "ri.h"
#include <stdio.h> 		/* for FILE */

#ifdef  __cplusplus
extern "C" {
#endif

/*
** Public (DSO) interface for obtaining RixInterface objects (C++ only).
**
** A pointer to the global RixContext is returned, from which RixInterface
** objects can be obtained.
*/
#ifdef __cplusplus
PRMANAPI extern class RixContext *RxGetRixContext();
#endif 

/*
** Public (DSO) interface for creating unique strings 
**
** Create a unique string based on the UUID and put the null-terminated string
** into the variable "sixty_four_chars_buffer".
*/

PRMANAPI extern void RxUUIDCreateString( char *sixty_four_chars_buffer );

/*
** Public (DSO) interface for noise.
*/
PRMANAPI extern RtInt RxNoise(int inDimension, float *in,
		     int outDimension, float *out);

PRMANAPI extern RtInt RxPNoise(int inDimension, float *in, float *period,
		      int outDimension, float *out);

PRMANAPI extern RtInt RxCellNoise(int inDimension, float *in,
			 int outDimension, float *out);

/*
** RxAttribute, RxOption, and RxRendererInfo return the
** current values of the named Attribute or Option.
** NB: these interfaces are deprecated.  The RixRenderState
** interface is the suggested replacement for this functionality.
**
** The caller passes in a buffer and it is filled-in with the
** resulting requested info.  Return value is 0 on success, or
** -1 if name can't be found, or N if the supplied buffer was
** too short and needs to be at least N bytes long.  Caller
** supplies the addresses of several other return values which
** are filled in:  resulttype is the RxInfoType_t of the values
** put into the result buffer, and resultcount is the number of
** those (multibyte) items.
*/

typedef enum {
    RxInfoFloat, RxInfoInteger, RxInfoStringV, RxInfoColor,
    RxInfoNormal, RxInfoVector, RxInfoPoint, RxInfoHPoint,
    RxInfoMPoint, RxInfoMatrix
} RxInfoType_t;

PRMANAPI extern int RxOption (const char *name, void *result, int resultlen,
				RxInfoType_t *resulttype, int *resultcount);
PRMANAPI extern int RxAttribute (const char *name, void *result, int resultlen,
				RxInfoType_t *resulttype, int *resultcount);
PRMANAPI extern int RxRendererInfo (const char *name, void *result,
				     int resultlen, RxInfoType_t *resulttype,
				     int *resultcount);

/*
** RxAttrIdNameStack returns a list of names representing the
** attribute scopes enclosing the current Ri stream position.
** Caller provides memory into which the renderer writes the
** name at each level.
** Positive returncode represents success and will be less than
** the provided maximum length. idstack[0] is the 'innermost' scope.
** idstack[returnval-1] is the outtermost scope.
** Nonpositive return codes represent failure, the magnitude of the
** result represents the size of the memory block needed to store a 
** result.  A Return value of 0 indicates other exceptional (error)
** conditions.
*/
PRMANAPI extern int RxAttrIdNameStack(const char *idstack[], unsigned maxlen);

/*
** Public (DSO) interface for textures.
*/
PRMANAPI extern int RxEnvironmentPointsV(RtString filename, RtInt nPoints, 
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *dir0, RtFloat *dir1, RtFloat *dir2, RtFloat *dir3,
	RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxEnvironmentPoints(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *dir0, RtFloat *dir1, RtFloat *dir2, RtFloat *dir3,
	RtFloat *result, ...);

PRMANAPI extern int RxEnvironmentV(RtString filename, RtInt firstchannel,
	RtInt nchannels, RtPoint dir0, RtPoint dir1, RtPoint dir2, RtPoint dir3,
	RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxEnvironment(RtString filename, RtInt firstchannel,
	RtInt nchannels, RtPoint dir0, RtPoint dir1, RtPoint dir2, RtPoint dir3,
	RtFloat *result, ...);

PRMANAPI extern int RxShadowPointsV(RtString filename, RtInt nPoints, 
        RtInt firstchannel,
	RtFloat *P0, RtFloat *P1, RtFloat *P2, RtFloat *P3,
	RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxShadowPoints(RtString filename, RtInt nPoints, 
        RtInt firstchannel,
	RtFloat *P0, RtFloat *P1, RtFloat *P2, RtFloat *P3, RtFloat *result, ...);

PRMANAPI extern int RxShadowV(RtString filename, RtInt firstchannel,
	RtPoint P0, RtPoint P1, RtPoint P2, RtPoint P3,
	RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxShadow(RtString filename, RtInt firstchannel,
	RtPoint P0, RtPoint P1, RtPoint P2, RtPoint P3, RtFloat *result, ...);

PRMANAPI extern int RxSourceShadowV(RtString filename, RtInt firstchannel,
                           RtPoint P0, RtPoint P1, RtPoint P2, RtPoint P3,
                           RtPoint sourceP0, RtPoint sourceP1,
                           RtPoint sourceP2, RtPoint sourceP3,
                           RtFloat *result, RtInt n,
                           RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxSourceShadow(RtString filename, RtInt firstchannel,
                          RtPoint P0, RtPoint P1, RtPoint P2, RtPoint P3,
                          RtPoint sourceP0, RtPoint sourceP1,
                          RtPoint sourceP2, RtPoint sourceP3,
                          RtFloat *result, ...);

/* single-point texture lookup */
PRMANAPI extern int RxTexturePoints1(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *s, RtFloat *t, RtFloat *result, ...);

PRMANAPI extern int RxTexturePoints1V(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *s, RtFloat *t, 
        RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

/* four-point texture lookup */
PRMANAPI extern int RxTexturePoints4(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *s0, RtFloat *t0, RtFloat *s1, RtFloat *t1, 
        RtFloat *s2, RtFloat *t2, RtFloat *s3, RtFloat *t3, 
        RtFloat *result, ...);

PRMANAPI extern int RxTexturePoints4V(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *s0, RtFloat *t0, RtFloat *s1, RtFloat *t1, 
        RtFloat *s2, RtFloat *t2, RtFloat *s3, RtFloat *t3, 
        RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

/* Filter Region texture lookup */
PRMANAPI extern int RxTexturePointsFr(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *fr, RtFloat *result, ...);

PRMANAPI extern int RxTexturePointsFrV(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, RtFloat *fr, 
        RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

/* Filter Region ptexture lookup */
PRMANAPI extern int RxPTexturePointsFr(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels,  RtFloat *faceIndex,
        RtFloat *fr, RtFloat *result, ...);

PRMANAPI extern int RxPTexturePointsFrV(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, RtFloat *faceIndex, RtFloat *fr, 
        RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

/* Explicit derivative based ptexture lookup */
PRMANAPI extern int RxPTexturePoints(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels,  RtFloat *faceIndex,
        RtFloat *u, RtFloat *v, 
        RtFloat *du1, RtFloat *dv1,
        RtFloat *du2, RtFloat *dv2,
        RtFloat *result, ...);

PRMANAPI extern int RxPTexturePointsV(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, RtFloat *faceIndex,
        RtFloat *u, RtFloat *v, 
        RtFloat *du1, RtFloat *dv1,
        RtFloat *du2, RtFloat *dv2,
        RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

/* RxTexturePoints/RxTexturePointsV return the same result as
** RxTexturePoints4/RxTexturePoints4V; they were used before the single-point
** calls were added, and remain for compatibility with old plugins.
** For new plugins, using the above explicit single-point or four-point calls
** is recommended.
*/
PRMANAPI extern int RxTexturePointsV(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *s0, RtFloat *t0, RtFloat *s1, RtFloat *t1, 
        RtFloat *s2, RtFloat *t2, RtFloat *s3, RtFloat *t3, 
        RtFloat *result, RtInt n, RtToken tokens[],
	RtPointer parms[]);

PRMANAPI extern int RxTexturePoints(RtString filename, RtInt nPoints,
        RtInt firstchannel, RtInt nchannels, 
        RtFloat *s0, RtFloat *t0, RtFloat *s1, RtFloat *t1, 
        RtFloat *s2, RtFloat *t2, RtFloat *s3, RtFloat *t3, 
        RtFloat *result, ...);

PRMANAPI extern int RxTextureV(RtString filename, 
        RtInt firstchannel, RtInt nchannels,
	RtFloat s0, RtFloat t0, RtFloat s1, RtFloat t1, 
        RtFloat s2, RtFloat t2, RtFloat s3, RtFloat t3, 
        RtFloat *result, RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxTexture(RtString filename, 
        RtInt firstchannel, RtInt nchannels,
	RtFloat s0, RtFloat t0, RtFloat s1, RtFloat t1, 
        RtFloat s2, RtFloat t2, RtFloat s3, RtFloat t3, 
        RtFloat *result, ...);

PRMANAPI extern int RxTexture3dV(RtString filename,
        RtPoint point, RtNormal normal, RtFloat filterradius,
        RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxTexture3d(RtString filename,
        RtPoint point, RtNormal normal, RtFloat filterradius, ...);

PRMANAPI extern int RxBake3dV(RtString filename,
        RtPoint point, RtNormal normal, RtFloat radius, 
        RtInt n, RtToken tokens[], RtPointer parms[]);

PRMANAPI extern int RxBake3d(RtString filename,
        RtPoint point, RtNormal normal, RtFloat radius, ...);

PRMANAPI extern int RxTextureInfo(const char *filename, 
        const char *attrname, void *result,
        int resultlen, RxInfoType_t *resulttype, int *resultcount);

PRMANAPI extern int RxPTextureInfo(const char *filename, 
        const char *attrname, void *result,
        int resultlen, RxInfoType_t *resulttype, int *resultcount,
        int faceindex);

PRMANAPI extern int RxTextureGetData(const char *filename, 
        int numchannels, int *chanids, int mipmaplevel, int face,
        void *result);


    
/*
** Public (DSO) interface for getting RIB context.
**
** Copies the linenumber of the current position in the input RIB to the
** int at location pointed to by linenumber.
** Copies the address of a string containing the current RIB filename to the
** pointer at the location pointed to by filename.  This string memory is owned
** by the renderer and should not be deallocated by a DSO.  If no RIB file name
** is available, *filename is set to NULL.
** Returns 0 if successful, 1 otherwise.
*/

PRMANAPI extern int RxGetRIBFileContext(int *linenumber, char **filename);

/*
** Public interface for obtaining the contents of an in-memory archive,
** useful to serialize a sequence of Ri calls.
** returns 0 if successful, 1 otherwise.  Resulting archive data must
** be copied-out, since the lifetime of the referenced data is undefined.
** RiArchiveBegin(":memory/ascii:yourarchivename");
** .. misc ri calls ..
** RiArchiveEnd()
** const char *rib;
** if(0 == RxGetRIBArchive("yourarchivename", &rib))
** {
**    // archive found, we need to strdup it
** }
*/

PRMANAPI extern int RxGetRIBArchive(const char *filename, const char **archive);

/*
** Public (DSO) interface for transforming points
**
** Take the point array p, and transform it from the "from"
** space to the "to" space.
*/
PRMANAPI extern RtInt RxTransformPoints(RtToken fromspace, RtToken tospace,
	                           RtInt n, RtPoint p[], RtFloat time);
PRMANAPI extern RtInt RxTransform(RtToken fromspace, RtToken tospace,
       				RtFloat time, RtMatrix m);

    
#ifdef  __cplusplus
}
#endif

#endif /* ndef _RX_H */

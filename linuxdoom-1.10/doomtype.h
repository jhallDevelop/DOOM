// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//	Simple basic typedefs, isolated here to make it easier
//	 separating modules.
//    
//-----------------------------------------------------------------------------


#ifndef __DOOMTYPE__
#define __DOOMTYPE__


#ifndef __BYTEBOOL__
#define __BYTEBOOL__
#ifdef OSX
    // Undefine the true and false macros, so we can redefine them in our enum.
    #ifdef true
        #undef true
    #endif
    #ifdef false
        #undef false
    #endif

    // Define the boolean type for C and C++.
    #ifdef __cplusplus
        typedef bool boolean;  // For C++, use the built-in bool type.
    #else
        #ifdef __STDBOOL_H__  // If stdbool.h is included, use the built-in bool.
            typedef bool boolean;
        #else  // Otherwise, define the boolean using an enum with default values.
            typedef enum { false = 0, true = 1 } boolean;
        #endif
    #endif
#else
    // Fixed to use builtin bool type with C++.
    #ifdef __cplusplus
    typedef bool boolean;
    #else
    typedef enum {false, true} boolean;
    #endif
#endif
typedef unsigned char byte;  // Define byte type.
#endif  // __BYTEBOOL__


// Predefined with some OS.
#ifdef LINUX
#include <values.h>
#else
#define MAXCHAR		((char)0x7f)
#define MAXSHORT	((short)0x7fff)

// Max pos 32-bit int.
#define MAXINT		((int)0x7fffffff)	
#define MAXLONG		((long)0x7fffffff)
#define MINCHAR		((char)0x80)
#define MINSHORT	((short)0x8000)

// Max negative 32-bit integer.
#define MININT		((int)0x80000000)	
#define MINLONG		((long)0x80000000)
#endif




#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------

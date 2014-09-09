//
// Copyright (c) 2007 Rigaku Corporation, Rigaku Americas Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No.
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// hipic.h        Initial author: S.Yasukawa           5-Oct-2007
//   This file is the header file for a HiPic style image file routines

/*
 *
 * Copyright (C) 2014 Rigaku Americas Corporation
 *                    9009 New Trails Drive
 *                    The Woodlands, TX, USA  77381
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice(s), this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice(s), this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the Rigaku Americas Corporation nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL RIGAKU AMERICAS CORPORATION BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS INTERUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 */
 
#ifndef DT_HIPIC_H
#define DT_HIPIC_H

//+Include files

#include "Cstring.h"

//+Code begin

typedef struct {
	char name[2];
	short length;
	short xpxl;
	short zpxl;
	short xoffset;
	short yoffset;
	short byte;
	char  reserve[40];
} _HiPic_header;

// Forward declaration of classes needed by the function prototypes below

class Cimage;
class Cimage_header;

int nReadHiPicHeader(const int* pnFile, const Cstring& rsFilename,
		       char *pcBuffer, Cimage_header *poHeader);

int nReadHiPicData(const int *pnFile, unsigned short int *puiData,
		   Cimage_header *poHeader);

//+Code begin

#endif   // DT_HIPIC_H

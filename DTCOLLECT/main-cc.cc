//
// README: Portions of this file are merged at file generation
// time. Edits can be made *only* in between specified code blocks, look
// for keywords <Begin user code> and <End user code>.
//
//////////////////////////////////////////////////////////////////////
//
// Created by Builder Xcessory Version 5.0.
// Generated by Code Generator Xcessory 5.0 (05/22/98) .
//
//////////////////////////////////////////////////////////////////////


// Begin user code block <file_comments>
// Copyright (c) 1995 Molecular Structure Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No. 
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// main-cc.cc           Initial author: J.W. Pflugrath           16-Dec-1995
//    This file contains the main routine for dtcollect
//    It was automatically generated by ICS Builder Xcessory.
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

// End user code block <file_comments>

//
// Motif.
//
#include <X11/StringDefs.h>
#include <Xm/Xm.h>
#include <Xm/DialogS.h>
#include <Xm/MwmUtil.h>
#if (XmVersion >= 1002)
#include <Xm/RepType.h>
#endif

//
// Globally included information (change thru Output File Names Dialog).
//


//
// Headers for classes used in this program.
//
#include "CUIeditdetector.h"
#include "CUIom8.h"
#include "CUIom2.h"
#include "CUIom9.h"
#include "CUIimagefileSelect.h"
#include "CUInumberField.h"
#include "CUIPSfileSelect.h"
#include "CUIheaderEdit.h"
#include "CUIviewheader.h"
#include "CUIwavelength.h"
#include "MainWindow.h"

//
// Convenience functions from utilities file.
//
extern void RegisterBxConverters(XtAppContext);
extern XtPointer BX_CONVERT(Widget, char *, char *, int, Boolean *);
extern XtPointer BX_DOUBLE(double);
extern XtPointer BX_SINGLE(float);
extern void BX_MENU_POST(Widget, XtPointer, XEvent *, Boolean *);
extern Pixmap XPM_PIXMAP(Widget, char **);
extern void BX_SET_BACKGROUND_COLOR(Widget, ArgList, Cardinal *, Pixel);
//
// Function declarations for shell callbacks..
//

// Begin user code block <globals>
#include "Cstring.h"

/****************************************************************************
 * This routine is a crude command line parser.  It assumes that options    *
 * begin with '-' and that they have at most 1 parameter.  Note that para-  *
 * meters that are -ve numbers will be interpreted as options.  The routine *
 * returns the element index into the sOptions array of the option that was *
 * found, or -1 if no options were found.                                   *
 ****************************************************************************/

int nGetOpt(int argc,          // total number of command line arguments
            char **argv,       // command line arguments
            Cstring *sOptions, // array of options (including '-')
            int nOptions,      // number of options in array
            char **pcValue)    // return parameter position (argv[n])
{
   int i;
   static int nIndex = 1;

/*
 * Find the first argument that contains a '-', which indicates an option.
 * Note that nIndex is static, so that repeated calls will start with the
 * next argument.
 */
   while(nIndex < argc)
     {
       if ('-' == argv[nIndex][0])
         break;
       nIndex++;
     }
/*
 * If at the end of the argument list, return now.
 */
   if (nIndex >= argc)
     return -1;
/*
 * Loop through the list of options, until we find one that matches or we
 * run out of options.
 */
   for (i = 0; i < nOptions; i++)
     {
/*
 * If we find one, check the next argument in the list to see if it is an 
 * option or a parameter.  Note that this will fail for parameters that are
 * negative numbers.
 */
       if (sOptions[i] == argv[nIndex])
	 {
	   nIndex++;
	   if (nIndex >= argc)               // no more arguments in the list
	     *pcValue = NULL;
	   else if ('-' == argv[nIndex][0])  // next argument is an option
	     *pcValue = NULL;
	   else 
	     {                               // next argument is a parameter
	       *pcValue = argv[nIndex];
	       nIndex++;
	     }
	   return i;
	 }
     }
/*
 * Didn't find an match.  Index is incremented so that if this is called again,
 * it will return at the top of the routine.
 */
   nIndex++;

   return -1;
}

// For the R-AXIS4 dtcollect (with/without client/server), 
// we need the following 2 global variables
// that are used with the device classes.
// CRAXISSERIAL_H would be defined in a device class #include file.

#ifdef CRAXISSERIAL_H
CRAXIS4       *g_poRAXIS4 = NULL;
CRAXIS4serial *g_poTTY    = NULL;
#endif

// For the R-AXIS4 dtcollect (as client)
// we need the following global variable
// RAXIS4_CLIENT would be defined by a #include file in a device class

#ifdef RAXIS4_CLIENT
#include "CsocketR4.h"
CsocketR4       *g_poSocketRAXIS4 = NULL;
#endif

#ifdef RIGAKUMSC_CLIENT
#include "CinstrumentClient.h"
CinstrumentClient *g_poInstrumentClient = NULL;
#endif

// End user code block <globals>
//
// Change this line via the Output Application Names Dialog.
//
#define BX_APP_CLASS "Dtcollect"

int main ( int argc, char **argv )
{
    Widget       parent;
    XtAppContext app;
    Arg          args[256];
    Cardinal     ac;
    Boolean      argok=False;
    
    // Begin user code block <declarations>

    char *pcValue;
    int i;
    int nOption,nReadOkay;
    Cstring sOptions[] = {"-scan", "-go"};
    Cstring sFile = "no scan file";

    // End user code block <declarations>
    
    // Initialize Xt. 
    //
    // The shell returned by XtAppInitialize is used as an unrealized
    // parent for multiple shell.  Each shell in this program
    // is created as a popup child of the main applicationShell.
    // This is a recommendation of Paul Asente & Ralph Swick in
    // "X Window System Toolkit", p. 677.
    
    parent = XtVaAppInitialize ( &app, BX_APP_CLASS, NULL, 0, 
#ifndef XlibSpecificationRelease
    (Cardinal *) &argc, 
#else
#if (XlibSpecificationRelease>=5)
    &argc, 
#else
    (Cardinal *) &argc, 
#endif
#endif
    argv, NULL, 
    NULL );
    
    RegisterBxConverters(app);
#if (XmVersion >= 1002) 
    XmRepTypeInstallTearOffModelConverter();
#endif
    
    // Begin user code block <create_shells>
    vDtrekSetModuleName("dtcollect");
    if ( 1 < argc )
      {
	// Filename argument on the command line.
        // But only if first character is not a -, which implies 
        // that it is a command line option

        if ('-' != argv[1][0])
	  {
	    MainWindow::ms_sDefaultHeaderTemplateFile = argv[1];

	    // Display argument for dtdisplay on the command line.
	    // But only if first character is not a -, which implies 
	    // that it is a command line option
	    if ( 2 < argc )
	      {
		if ('-' != argv[2][0])
	          MainWindow::ms_sDtdisplay = argv[2];
	      }
	  }
      }

    // End user code block <create_shells>
    //
    // Instantiate the classes used in this program.
    //
    
    
    // Begin user code block <create_dtcollect>
    // End user code block <create_dtcollect>
    
    Widget dtcollect;
    
    ac = 0;
    XtSetArg(args[ac], XmNx, 192); ac++;
    XtSetArg(args[ac], XmNy, 122); ac++;
    XtSetArg(args[ac], XmNwidth, 880); ac++;
    XtSetArg(args[ac], XmNheight, 746); ac++;
    dtcollect = XtCreatePopupShell("dtcollect",
        topLevelShellWidgetClass,
        parent,
        args, 
        ac);
    
    MainWindow *_mainWindow = new MainWindow("mainWindow");
    
    // Begin user code block <new_mainWindow>
    // End user code block <new_mainWindow>
    
    _mainWindow->create(dtcollect);
    _mainWindow->manage();
    
    //
    // Set exposed resources.
    //
    ac = 0;
    XtSetArg(args[ac], XmNx, 192); ac++;
    XtSetArg(args[ac], XmNy, 122); ac++;
    XtSetArg(args[ac], XmNwidth, 880); ac++;
    XtSetArg(args[ac], XmNheight, 746); ac++;
    XtSetValues(_mainWindow->baseWidget(), args, ac);
    XtPopup(dtcollect, XtGrabNone);
    
    // Begin user code block <app_procedures>
    // End user code block <app_procedures>
    
    // Begin user code block <main_loop>

    _mainWindow->m_hAppContext = app;  // Let mainwindow know about AppContext

   // Read in the command line options
 
    cout << "The command line arguments are \n";
    for (i = 0; i < argc; i++)
      cout << i << " " << argv[i] << "\n";
    while (-1 != (nOption=nGetOpt(argc,argv,sOptions,5,&pcValue)))
      {
	// Read in a scan file

	if (0 == nOption)
	  {
	    if (NULL != pcValue)
	      {
		sFile = pcValue;
		nReadOkay = _mainWindow->nCommandLineReadScan(sFile);
		if (0 != nReadOkay)
		  sFile = "no scan file";
	      }
	  }
	else if (1 == nOption)
	  {
	    // Execute the scan

	    if ("no scan file" != sFile)
	      _mainWindow->vCommandLineStartScan();
	  }
      }
    
    // Make a call to the workproc 
    // which also polls hardware devices for current settings to
    // make sure things are initialized all the way.  If the hardware
    // is still in an active state, then this will setup continued polling
    // until the devices are quiet (i.e. not doing anything)

    _mainWindow->vWorkProc1(_mainWindow, NULL);

    // End user code block <main_loop>
    
    XtAppMainLoop(app);
    
    //
    // A return value even though the event loop never ends. 
    //
     return(0); 
}

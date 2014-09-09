//
// Copyright (c) 1995 Molecular Structure Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No. 
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// CUIimagefileSelect.cc   Initial author: J.W. Pflugrath           16-Dec-1995
//    This file contains the methods to implement the user interface class
//    CUIimagefileSelect which implements a d*TREK image file selection box.
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

//
// README: Portions of this file are merged at file generation
// time. Edits can be made *only* in between specified code blocks, look
// for keywords <Begin user code> and <End user code>.
//
/////////////////////////////////////////////////////////////
//
// Source file for CUIimagefileSelect
//
//    This file generated by Builder Xcessory 3.5.1.
//
//    This class is a user interface "component", as described
//    in "Object-Oriented Programming with C++ and OSF/Motif",
//    by Douglas Young, Prentice Hall, 1992. ISBN 0-13-630252-1
//
/////////////////////////////////////////////////////////////
#include <X11/StringDefs.h>
#include <Xm/FileSB.h>
#include <Xm/Form.h>
#include <Xm/Text.h>
#include <Xm/DialogS.h>
#include <Xm/MwmUtil.h>
#include <Xm/MessageB.h>
#include "CUIimagefileSelect.h"
#include "CUInumberField.h"

//
// Convenience functions from utilities file.
//
extern void RegisterBxConverters(XtAppContext);
extern XtPointer BX_CONVERT(Widget, char *, char *, int, Boolean *);
extern XtPointer DOUBLE(double);
extern XtPointer SINGLE(float);
extern void MENU_POST(Widget, XtPointer, XEvent *, Boolean *);
extern Pixmap XPM_PIXMAP(Widget, char**);
extern void SET_BACKGROUND_COLOR(Widget, ArgList, Cardinal*, Pixel);


// Begin user code block <head> 
// End user code block <head> 

//
// This table is used to define class resources that are placed
// in app-defaults. This table is necessary so each instance
// of this class has the proper default resource values set.
// This eliminates the need for each instance to have
// its own app-defaults values. This table must be NULL terminated.
//
#if defined(cxx_bx_compat)

Boolean CUIimagefileSelect::_initAppDefaults = True;
UIAppDefault  CUIimagefileSelect::_appDefaults[] = {
    {"", NULL, "dialogTitle", NULL},
    {"", NULL, "selectionLabelString", NULL},
    {"", NULL, "okLabelString", NULL},
    {"", NULL, "filterLabelString", NULL},
    {"text", NULL, "value", NULL},
    {"numImages", "", "sensitive", NULL},
    {"numImages", "scrollBar", "minimum", NULL},
    {"numImages", "scrollBar", "maximum", NULL},
    {"numImages", "textField", "value", NULL},
    {"numImages", "label", "labelString", NULL},
    {"seqIncr", "", "sensitive", NULL},
    {"seqIncr", "textField", "value", NULL},
    {"seqIncr", "label", "labelString", NULL},
    {"seqStart", "", "sensitive", NULL},
    {"seqStart", "textField", "value", NULL},
    {"seqStart", "label", "labelString", NULL},
    {"messageBox", NULL, "dialogTitle", NULL},
    {"messageBox", NULL, "messageString", NULL},
    {NULL, NULL, NULL, NULL}
};
#endif

// These are default resources for widgets in objects of this class
// All resources will be prepended by *<name> at instantiation,
// where <name> is the name of the specific instance, as well as the
// name of the baseWidget. These are only defaults, and may be overriden
// in a resource file by providing a more specific resource name

String  CUIimagefileSelect::_defaultCUIimagefileSelectResources[] = {
        NULL
};

//
// Old style constructor, for compatibility only.
//
CUIimagefileSelect::CUIimagefileSelect(const char *name, Widget parent) : 
    UIComponent(name)
{
    
    // Begin user code block <alt_constructor> 
    // End user code block <alt_constructor> 
    create(parent);
}

//
// Class constructor.
//
CUIimagefileSelect::CUIimagefileSelect(const char *name) : UIComponent(name)
{
    
    // Begin user code block <constructor> 

  m_sFilename       = "";
  m_sTemplate       = "";
  m_sDirectory      = ".";
  m_sHelpLine       = (Cstring)name + (Cstring) "$$"; // No default html file

  m_prvFileCallback = NULL; // Make sure the filecallback is initialized to NULL
  m_pObj            = NULL; //  and there is no object to pass in callback
  m_nImageSize      = (3072 * 3072 * 2) + 4096;

    // End user code block <constructor> 
}

//
// Minimal Destructor. Base class destroys widgets.
//
CUIimagefileSelect::~CUIimagefileSelect() 
{
    
    // Begin user code block <destructor> 

  if (NULL != m_poXhelp)
    {
      delete m_poXhelp;
      m_poXhelp = NULL;
    }

    // End user code block <destructor> 
    delete _clientDataStructs;
}

//
// Handle creation of all widgets in the class.
//
void CUIimagefileSelect::create(Widget parent) 
{
    Arg      args[256];
    Cardinal ac=0;
    Boolean  argok=False;
    
    //
    // Load any class-defaulted resources for this object.
    //
    setDefaultResources(parent, _defaultCUIimagefileSelectResources);
    
#if defined(cxx_bx_compat)
    //
    // Setup app-defaults fallback table if not already done.
    //
    if (_initAppDefaults)
    {
        initAppDefaults(parent, "CUIimagefileSelect", _appDefaults);
        _initAppDefaults = False;
    }
    //
    // Now set the app-defaults for this instance.
    //
    setAppDefaults(parent, _appDefaults, _name, False);
#endif
    
    //
    // Register the converters for the widgets.
    //
    RegisterBxConverters(XtWidgetToApplicationContext(parent)); 
    XtInitializeWidgetClass(xmFileSelectionBoxWidgetClass);
    XtInitializeWidgetClass(xmFormWidgetClass);
    XtInitializeWidgetClass(xmTextWidgetClass);
    XtInitializeWidgetClass(xmDialogShellWidgetClass);
    XtInitializeWidgetClass(xmMessageBoxWidgetClass);
    
    //
    // Create an unmanaged widget as the top of the hierarchy.
    //
    
    ac = 0;
    XtSetArg(args[ac], XmNx, 551); ac++;
    XtSetArg(args[ac], XmNy, 236); ac++;
    XtSetArg(args[ac], XmNwidth, 592); ac++;
    XtSetArg(args[ac], XmNheight, 552); ac++;
    _CUIimagefileSelect = XmCreateFileSelectionBox(parent,
        _name,
        args, 
        ac);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_CUIimagefileSelect,
        XmNokCallback,
        CUIimagefileSelect::vImagefileSelectCBCallback,
        (XtPointer)_clientDataStructs);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_CUIimagefileSelect,
        XmNapplyCallback,
        CUIimagefileSelect::vImagefileSelectCBCallback,
        (XtPointer)_clientDataStructs);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_CUIimagefileSelect,
        XmNcancelCallback,
        CUIimagefileSelect::vImagefileSelectCBCallback,
        (XtPointer)_clientDataStructs);
    
    _w = _CUIimagefileSelect;
    //
    // Install callback to guard against unexpected widget destruction..
    //
    installDestroyHandler();
    
    ac = 0;
    _form = XmCreateForm(_CUIimagefileSelect,
        "form",
        args, 
        ac);
    XtManageChild(_form);
    
    ac = 0;
    XtSetArg(args[ac], XmNtraversalOn, False); ac++;
    XtSetArg(args[ac], XmNeditMode, XmMULTI_LINE_EDIT); ac++;
    XtSetArg(args[ac], XmNautoShowCursorPosition, False); ac++;
    XtSetArg(args[ac], XmNeditable, False); ac++;
    XtSetArg(args[ac], XmNrows, 5); ac++;
    XtSetArg(args[ac], XmNscrollLeftSide, True); ac++;
    XtSetArg(args[ac], XmNscrollTopSide, True); ac++;
    XtSetArg(args[ac], XmNcursorPositionVisible, False); ac++;
    XtSetArg(args[ac], XmNx, 300); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 270); ac++;
    _text = XmCreateText(_form,
        "text",
        args, 
        ac);
    XtManageChild(_text);
    
    #if defined(cxx_bx_compat)
    setAppDefaults(_form, _appDefaults, "numImages");
    #endif
    _numImages = new CUInumberField("numImages");
    _numImages->create(_form);
    _numImages->manage();
    _numImages->set_cuinumberfield_width((XtPointer)100);
    _numImages->set_cuinumberfield_height((XtPointer)110);
    ac = 0;
    XtSetArg(args[ac], XmNx, 200); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 100); ac++;
    XtSetValues(_numImages->baseWidget(), args, ac);
    
    #if defined(cxx_bx_compat)
    setAppDefaults(_form, _appDefaults, "seqIncr");
    #endif
    _seqIncr = new CUInumberField("seqIncr");
    _seqIncr->create(_form);
    _seqIncr->manage();
    _seqIncr->set_cuinumberfield_width((XtPointer)100);
    _seqIncr->set_cuinumberfield_height((XtPointer)110);
    ac = 0;
    XtSetArg(args[ac], XmNx, 100); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 100); ac++;
    XtSetValues(_seqIncr->baseWidget(), args, ac);
    
    #if defined(cxx_bx_compat)
    setAppDefaults(_form, _appDefaults, "seqStart");
    #endif
    _seqStart = new CUInumberField("seqStart");
    _seqStart->create(_form);
    _seqStart->manage();
    _seqStart->set_cuinumberfield_width((XtPointer)100);
    _seqStart->set_cuinumberfield_height((XtPointer)110);
    ac = 0;
    XtSetArg(args[ac], XmNx, 0); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 100); ac++;
    XtSetValues(_seqStart->baseWidget(), args, ac);
    
    ac = 0;
    XtSetArg(args[ac], XmNx, 435); ac++;
    XtSetArg(args[ac], XmNy, 266); ac++;
    XtSetArg(args[ac], XmNwidth, 478); ac++;
    XtSetArg(args[ac], XmNheight, 135); ac++;
    _xmDialogShell = XtCreatePopupShell("xmDialogShell",
        xmDialogShellWidgetClass,
        _form,
        args, 
        ac);
    
    ac = 0;
    XtSetArg(args[ac], XmNdialogStyle, XmDIALOG_FULL_APPLICATION_MODAL); ac++;
    XtSetArg(args[ac], XmNdialogType, XmDIALOG_QUESTION); ac++;
    XtSetArg(args[ac], XmNokLabelString, 
        BX_CONVERT(parent, "OK, Create", 
        XmRXmString, 0, &argok)); if (argok) ac++;
    XtSetArg(args[ac], XmNx, 435); ac++;
    XtSetArg(args[ac], XmNy, 266); ac++;
    XtSetArg(args[ac], XmNwidth, 478); ac++;
    XtSetArg(args[ac], XmNheight, 135); ac++;
    _messageBox = XmCreateMessageBox(_xmDialogShell,
        "messageBox",
        args, 
        ac);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_messageBox,
        XmNokCallback,
        CUIimagefileSelect::vMessageBoxCBCallback,
        (XtPointer)_clientDataStructs);
    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = this;
    _clientDataStructs->client_data = (XtPointer)0;
    XtAddCallback(_messageBox,
        XmNcancelCallback,
        CUIimagefileSelect::vMessageBoxCBCallback,
        (XtPointer)_clientDataStructs);
    
    ac = 0;
    XtSetArg(args[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
    XtSetArg(args[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
    XtSetArg(args[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
    XtSetArg(args[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNtopWidget, _numImages->baseWidget()); ac++;
    XtSetArg(args[ac], XmNbottomWidget, _numImages->baseWidget()); ac++;
    XtSetArg(args[ac], XmNleftWidget, _numImages->baseWidget()); ac++;
    XtSetArg(args[ac], XmNtopOffset, 0); ac++;
    XtSetArg(args[ac], XmNbottomOffset, 0); ac++;
    XtSetArg(args[ac], XmNleftOffset, 0); ac++;
    XtSetArg(args[ac], XmNrightOffset, 0); ac++;
    XtSetValues(_text, args, ac);
    
    ac = 0;
    XtSetArg(args[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
    XtSetArg(args[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
    XtSetArg(args[ac], XmNleftWidget, _seqIncr->baseWidget()); ac++;
    XtSetArg(args[ac], XmNtopOffset, 0); ac++;
    XtSetArg(args[ac], XmNleftOffset, 0); ac++;
    XtSetArg(args[ac], XmNrightOffset, 0); ac++;
    XtSetValues(_numImages->baseWidget(), args, ac);
    
    ac = 0;
    XtSetArg(args[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
    XtSetArg(args[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
    XtSetArg(args[ac], XmNleftWidget, _seqStart->baseWidget()); ac++;
    XtSetArg(args[ac], XmNtopOffset, 0); ac++;
    XtSetArg(args[ac], XmNleftOffset, 0); ac++;
    XtSetArg(args[ac], XmNrightOffset, 0); ac++;
    XtSetValues(_seqIncr->baseWidget(), args, ac);
    
    // Begin user code block <endcreate> 

  // Make the 3 CUInumberField widgets use integer.  The way to do this
  // is to get the values as integers, then set them as integers.  From then
  // on, the scrollbar will always use an integer format string to update
  // the textfield.

    int nTemp;
    nTemp = _numImages->nGetValue();
    _numImages->vSetValue(nTemp);
    nTemp = _seqIncr->nGetValue();
    _seqIncr->vSetValue(nTemp);
    nTemp = _seqStart->nGetValue();
    _seqStart->vSetValue(nTemp);

    // Add the help callback
    
    m_poXhelp = new CXhelp(_w);

    _clientDataStructs = new UICallbackStruct;
    _clientDataStructs->object = (UIComponent *)m_poXhelp;
    _clientDataStructs->client_data = (XtPointer) (m_sHelpLine.string());
    XtAddCallback(_CUIimagefileSelect,
        XmNhelpCallback,
        CXhelp::vHTMLHelpCallback,
        (XtPointer)_clientDataStructs);

    char *pcTemp;

    pcTemp = XmTextGetString(_text);
    if (NULL != pcTemp)
      {
	if ('\0' != *pcTemp)
	  {
#if defined(SUNOS) || defined(LINUX)
            m_sFormatSpace = "Disk space:  %d kbytes\nFree space:  %d kbytes\nImage size:  %d kbytes\nFree space:  %d images";
#else	    
	    m_sFormatSpace = pcTemp;
#endif
	  }
	else
	  m_sFormatSpace = "%d\n%d\n%d\n%d";
	XtFree(pcTemp);
      }

    // End user code block <endcreate> 
}

//
// Classname access.
//
const char *const CUIimagefileSelect::className()
{
    return ("CUIimagefileSelect");
}

void CUIimagefileSelect::vImagefileSelectCBCallback(Widget w, 
		XtPointer clientData, XtPointer callData)
{
    UICallbackStruct *data = (UICallbackStruct *) clientData;
    CUIimagefileSelect *obj = (CUIimagefileSelect *)data->object;
    obj->vImagefileSelectCB(w, data->client_data, callData);
}

void CUIimagefileSelect::vImagefileSelectCB (Widget w, XtPointer clientData, XtPointer callData)
{
    
    // Begin user code block <vImagefileSelectCB> 


  XmFileSelectionBoxCallbackStruct *pCBS
    = (XmFileSelectionBoxCallbackStruct *) callData;

  if (XmCR_CANCEL == pCBS->reason)
    {
/*
      vSetTemplate((Cstring) "no template");
      vSetFilename((Cstring) "no filename");
*/
      XtUnmanageChild(w);
    }
  else if (XmCR_OK == pCBS->reason)
    {
      // Ok selected

      if (!bCheckDirectory())
	{
	  // Directory is invalid just return

	  return;
/////////////////
	}

      char    *pcTemp;
      pcTemp  = NULL;
      if (XmStringGetLtoR(pCBS->value,
#if (XmVersion >= 1002)
			   XmFONTLIST_DEFAULT_TAG,
#else
			   XmSTRING_DEFAULT_CHARSET,
#endif
			   &pcTemp))
	{
	  m_sFilename = pcTemp;   // There is a problem here if MSCstring class
	                          //   is compiled optimized? 
	}
      if (NULL != pcTemp) XtFree(pcTemp);
      pcTemp  = NULL;
      if (XmStringGetLtoR(pCBS->mask,
#if (XmVersion >= 1002)
			   XmFONTLIST_DEFAULT_TAG,
#else
			   XmSTRING_DEFAULT_CHARSET,
#endif
			  &pcTemp))
	{
	  m_sTemplate = pcTemp;
	}
      if (NULL != pcTemp) XtFree(pcTemp);

      m_nSeqStart = _seqStart->nGetValue();
      m_nSeqIncr  = _seqIncr->nGetValue();
      m_nNumImgs  = _numImages->nGetValue();

      if (   (m_sFilename.contains('*')) 
          || (m_sFilename.contains('?'))
          || ( m_sFilename.length()-2 == m_sFilename.index("..")))
	{
	  // Filename contains an asterisk or question mark,
	  // place in the mask and re-filter
	  
	  m_sTemplate = m_sFilename;

	  vSetTemplate(m_sTemplate);         // Update fsb with new filter

	  // Do search with new filter

	  XmFileSelectionDoSearch(w, NULL);
	  return;
        }
     else if (0 <= m_sTemplate.find('*'))
	{
	  // Template contains an asterisk, try to convert to something
	  // with question marks and re-filter
	  
	  m_sTemplate = m_sFilename;

	  // Change last 3 digits in m_sTemplate to ?'s
	  // but stop at a slash character

	  int i, j, nTemp;
	  int nStart, nEnd;
	  nTemp = 0;
	  for (i = m_sTemplate.length()-1; (nTemp < 3) && (i >= 0); i--)
	    {
	      j = m_sTemplate.GetAt(i);
	      if ( (j >= '0') && (j <= '9') )
		{
		  if (0 == nTemp) nEnd = i;  // Save starting and ending
		  nStart = i;                // position of the digits
		  m_sTemplate.SetAt(i, '?');
		  nTemp++;
		}
	      else if (0 < nTemp)
		{
		  // After find at least 1 digit, stop search at first non-digit
		  i = 0;
		}
	    }

	  vSetTemplate(m_sTemplate);         // Update fsb with new filter

	  // Do search with new filter, so the list is updated with new number
	  // of matches, and try to set num images by number of items in list

	  XmFileSelectionDoSearch(w, NULL);

	  XtVaGetValues(w, XmNfileListItemCount, &nTemp, NULL);
	  vSetNumImgs(nTemp);

	  // Try to determine sequence start from the replaced digits

	  Cstring sTemp;
	  sTemp = m_sFilename.substr(nStart, nEnd-nStart+1);
	  nStart = sscanf(sTemp.string(), "%d", &nTemp);
	  if (1 == nStart)
	    {
	      vSetSeqStart(nTemp);
	    }
	  if (0 == m_nSeqIncr)
	    {
	      // Set sequence increment to 1 if it is 0

	      vSetSeqIncr(1);
	    }
	  XtUnmanageChild(w);
	}
      else
	{
	  // Filename contains no wildcards, so unmanage FSD

	  XtUnmanageChild(w);
	}

/*
      cout << "m_sFilename is: " << m_sFilename << endl;      
      cout << "m_sTemplate is: " << m_sTemplate << endl;
      cout << "start is:    " << _seqStart->nGetValue() << endl;
      cout << "incr  is:    " << _seqIncr->nGetValue() << endl;
      cout << "num image is:" << _numImages->nGetValue() << endl;
*/
      // If a callback has been specified, then call it

      if (NULL != m_prvFileCallback)
	{
	  m_prvFileCallback(m_pObj, m_sFilename, m_sTemplate, m_nSeqStart,
			    m_nSeqIncr, m_nNumImgs);
	}
    }

   else if (pCBS->reason == XmCR_APPLY)
    {
      // Filter

      char    *pcTemp;
      (void) bCheckDirectory();
      pcTemp  = NULL;
      if (XmStringGetLtoR(pCBS->dir,
#if (XmVersion >= 1002)
			   XmFONTLIST_DEFAULT_TAG,
#else
			   XmSTRING_DEFAULT_CHARSET,
#endif
			   &pcTemp))
	{
	  vUpdateFileStats(pcTemp);
	}
      if (NULL != pcTemp) XtFree(pcTemp);
    }
  else if (pCBS->reason == XmCR_HELP)
    {
      // How to pass in help for this widget?
      // No need, it was done above!
    }

    // End user code block <vImagefileSelectCB> 
}

void CUIimagefileSelect::vMessageBoxCBCallback(Widget w, 
		XtPointer clientData, XtPointer callData)
{
    UICallbackStruct *data = (UICallbackStruct *) clientData;
    CUIimagefileSelect *obj = (CUIimagefileSelect *)data->object;
    obj->vMessageBoxCB(w, data->client_data, callData);
}

void CUIimagefileSelect::vMessageBoxCB (Widget w, XtPointer clientData, XtPointer callData)
{
    
    // Begin user code block <vMessageBoxCB> 
  XmAnyCallbackStruct *pCBS
    = (XmAnyCallbackStruct *) callData;

  if (XmCR_OK == pCBS->reason)
    {
      int nStat;
      nStat = nFileCreateDirectory(m_sDirectory);
      if (0 == nStat)
	{
	  XmFileSelectionDoSearch(baseWidget(), NULL);	  
	}
    }

    // End user code block <vMessageBoxCB> 
}

// Begin user code block <tail> 

int
CUIimagefileSelect::nGetNumImgs()
{
    return( _numImages->nGetValue());
}

int
CUIimagefileSelect::nGetSeqIncr()
{
    return( _seqIncr->nGetValue());
}

int
CUIimagefileSelect::nGetSeqStart()
{
    return( _seqStart->nGetValue());
}

void
CUIimagefileSelect::vSetFilename(const Cstring& sFilename)
{
  m_sFilename = sFilename;
  XmString stxTemp;

  stxTemp = XmStringCreateLtoR(m_sFilename.string(),
#if (XmVersion >= 1002)
			       XmFONTLIST_DEFAULT_TAG);
#else
			       XmSTRING_DEFAULT_CHARSET);
#endif
  if (NULL != stxTemp)
    {
      XtVaSetValues(_CUIimagefileSelect, XmNtextString, stxTemp, NULL);
      XmStringFree(stxTemp);
    }
}

void
CUIimagefileSelect::vSetNumImgs(int nNum)
{
  _numImages->vSetValue(nNum);
  m_nNumImgs = nNum;
}

void
CUIimagefileSelect::vSetSeqIncr(int nIncr)
{
  _seqIncr->vSetValue(nIncr);
  m_nSeqIncr = nIncr;
}

void
CUIimagefileSelect::vSetSeqStart(int nStart)
{
  _seqStart->vSetValue(nStart);
  m_nSeqStart = nStart;
}

void
CUIimagefileSelect::vSetTemplate(const Cstring& sTemplate)
{
  m_sTemplate = sTemplate;
  XmString stxTemp;
  stxTemp = XmStringCreateLtoR(m_sTemplate.string(),
#if (XmVersion >= 1002)
			       XmFONTLIST_DEFAULT_TAG);
#else
			       XmSTRING_DEFAULT_CHARSET);
#endif
  if (NULL != stxTemp)
    {
      XtVaSetValues(_CUIimagefileSelect, XmNdirMask, stxTemp, NULL);
      XmStringFree(stxTemp);
    }
}

Cstring 
CUIimagefileSelect::sGetTemplate(void)
{
  return (m_sTemplate);
}

Cstring 
CUIimagefileSelect::sGetFilename(void)
{
  return (m_sFilename);
}

void
CUIimagefileSelect::vUpdateFileStats(const char *pcFile)
{
  int nStat;
  char a255cBuffer[255];
  float fkBytesPerBlock;
  struct statfs *ptStatFS;    
  ptStatFS = &m_tStatFS;

#if defined(__NUTC__)
  nStat = -1;
#else
#ifdef LINUX
  nStat = statfs(pcFile, &m_tStatFS);
#else
#ifdef OSF1
  char *pcTemp;
  pcTemp = new char [sizeof(pcFile)+2];
  strcpy(pcTemp, pcFile);
  nStat = statfs(pcTemp, &m_tStatFS, sizeof(struct statfs), 0);
  delete [] pcTemp;
#else
  nStat = statfs(pcFile, &m_tStatFS, sizeof(struct statfs), 0);
#endif
#endif
#endif

  //  cout << "File for stats is: " << pcFile << endl;
  if ( (0 == nStat) && (0 < m_nImageSize) )
    {
#ifdef OSF1
      fkBytesPerBlock =  (float) m_tStatFS.f_fsize / 1024.0;
#elif defined(SUNOS)
      fkBytesPerBlock =  (float) m_tStatFS.f_bsize / 16384.0;
#else
      fkBytesPerBlock =  (float) m_tStatFS.f_bsize / 1024.0;
#endif
      sprintf(a255cBuffer, m_sFormatSpace.string(),
	      (int) ((float) m_tStatFS.f_blocks * fkBytesPerBlock),
	      (int) ((float) m_tStatFS.f_bfree * fkBytesPerBlock),
	      (int) ((float)m_nImageSize / 1024.0),
#ifdef OSF1
	      (int) ((float)m_tStatFS.f_bfree * (float)m_tStatFS.f_fsize 
#else
	      (int) ((float)m_tStatFS.f_bfree * (float)m_tStatFS.f_bsize 
#endif
		     / (float)m_nImageSize)
	      );
    }
  else
    {
      sprintf(a255cBuffer, "File system info\nunavailable!");
    }
  XmTextSetString(_text, a255cBuffer);

}

void
CUIimagefileSelect::vSetImageSize(const int nSize)
{
  m_nImageSize = nSize;
}

void
CUIimagefileSelect::manage()
{
  // Force re-filtering before every manage operation, so list is updated

  XmFileSelectionDoSearch(_CUIimagefileSelect, NULL);
  
  XmString sxTemp;
  char *pcTemp;
  XtVaGetValues(_CUIimagefileSelect, XmNdirectory, &sxTemp, NULL);
  pcTemp  = NULL;
  if (XmStringGetLtoR(sxTemp,
#if (XmVersion >= 1002)
		      XmFONTLIST_DEFAULT_TAG,
#else
		      XmSTRING_DEFAULT_CHARSET,
#endif
		      &pcTemp))
    {
      vUpdateFileStats(pcTemp);
    }
  if (NULL != pcTemp) XtFree(pcTemp);
  UIComponent::manage();
}

bool
CUIimagefileSelect::bCheckDirectory(void)
{
  bool    bReturnStat;
  char    *pcTemp;
  Boolean bDirValid = False;
  XtVaGetValues(baseWidget(), XmNdirectoryValid, &bDirValid, NULL);

  bReturnStat = TRUE;
  if (!bDirValid)
    {
      bReturnStat = FALSE;

      // Directory not valid, prompt to create it!
      // The invalid directory specification is not available in the normal
      // callback structure, so we must get it explicitly.

      pcTemp = XmTextGetString(XmFileSelectionBoxGetChild(baseWidget(), 
							 XmDIALOG_FILTER_TEXT));
      m_sDirectory = pcTemp;
      XtFree(pcTemp);
      m_sDirectory = sFileGetDirectory(m_sDirectory);
      Cstring  sTemp;
      XmString stxTemp;
      sTemp = "Directory " + m_sDirectory + "\nis invalid or DOES NOT EXIST!\nCreate it?";
      stxTemp = XmStringCreateLtoR(
				   sTemp.string(),
#if (XmVersion >= 1002)
				   XmFONTLIST_DEFAULT_TAG);
#else
                                   XmSTRING_DEFAULT_CHARSET);
#endif
      if (NULL != stxTemp)
	{
	  XtVaSetValues(_messageBox, XmNmessageString, stxTemp, NULL);
	  XmStringFree(stxTemp);
	}
      XtManageChild(_messageBox);
    }
  return (bReturnStat);
}
// End user code block <tail> 

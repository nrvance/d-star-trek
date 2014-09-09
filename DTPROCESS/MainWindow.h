//
// README: Portions of this file are merged at file generation
// time. Edits can be made *only* in between specified code blocks, look
// for keywords <Begin user code> and <End user code>.
//
//////////////////////////////////////////////////////////////
//
// Header file for MainWindow
//
//    Created by Builder Xcessory Version 5.0.
//    Generated by Code Generator Xcessory 5.0 (05/22/98) .
//
//    This class is a user interface "component", as described
//    in "Object-Oriented Programming with C++ and OSF/Motif",
//    by Douglas Young, Prentice Hall, 1992. ISBN 0-13-630252-1
//
//////////////////////////////////////////////////////////////


// Begin user code block <file_comments>
//
// Copyright (c) 1999, 1998, 1997 Molecular Structure Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No. 
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// MainWindow.h           Initial author: J.W. Pflugrath           9-Apr-1997
//    This file contains the main window include file for dtprocess.
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

#ifndef MainWindow_H
#define MainWindow_H
#include "UIComponent.h"
class CUIheaderEdit;
class CUItextnumArrow;
class CUIfileFilter;
class CUIscrolledlist;
class CUIom9;

//
// Globally included information (change thru Output File Names Dialog).
//


//
// Class Specific Includes (change thru the class in Resource Editor).
//



// Begin user code block <head>
#include "Cstring.h"
#include "CXhelp.h"
#include "CXcursor.h"
#include "CXprop.h"
#include "Cimage_header.h"
#include "Cscan.h"

#define DTP_DLG_CALIBRATE  0
#define DTP_DLG_FIND       1
#define DTP_DLG_INDEX      2
#define DTP_DLG_REFINE     3
#define DTP_DLG_PREDICT    4
#define DTP_DLG_INTEGRATE  5
#define DTP_DLG_MERGE      6
#define DTP_DLG_SCALE      7
#define DTP_DLG_ORIENT     8
#define DTP_DLG_STRATEGY   9
#define DTP_DLG_MAXBUTTONS 10
#define DTP_DLG_COMMAND    11
#define DTP_MAX_REFINE_MACROS 9

typedef struct _tagDtcalibrateOptions
{
  Cstring  sPrefix;
  Cstring  sSpatialType;
  Cstring  sSpatialInterp;
  Cstring  sSpatialSimple1;
  Cstring  sSpatialSimple2;
  Cstring  sDetDist;
  Cstring  sDetTheta;
  Cstring  sDirBeam1;
  Cstring  sDirBeam2;
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  sNonunfType;
  Cstring  sNonunfNonunf;
  Cstring  sNonunfDark;
  Cstring  sTemplate;
  Cstring  sSpacegroup;
  Cstring  sWindow1;
  Cstring  sWindow2;
  bool     bIndexChoose;
  bool     bDisplay;
} tagDtcalibrateOptions;

typedef struct _tagDtfindOptions
{
  Cstring  a2sSeqNum[2];
  Cstring  sSeqOptions;
  Cstring  sSigma;
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  sMinimum;
  Cstring  sPeakFilter;
  Cstring  a2sWindow[2];
  Cstring  sPad3D;
  Cstring  a2sBackRect[2];
  Cstring  a4sCircle[4];
  Cstring  a4sRect[4];
  Cstring  sDumpRefln;
  bool     b3Dsearch;
  bool     bDisplay;
  bool     bShowMore;
} tagDtfindOptions;

typedef struct _tagDtindexOptions
{
  Cstring  sMaxDiffs;
  Cstring  sMaxCell;
  Cstring  sGrid;
  Cstring  sMaxResid;
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  sSigma;
  Cstring  a6sErrors[6];
  Cstring  sSpacegroup;
  Cstring  sMethod;
  bool     bList;
  bool     bDiffs;
  bool     bKnown;
  bool     bPrompt;
  bool     bAdvanced;
} tagDtindexOptions;

typedef struct _tagDtrefineOptions
{
  Cstring  sSigma;
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  a3sReject[3];
  Cstring  sCycles;
  Cstring  sRelWeight;
  bool     a15bCrystal[15];
  bool     a9bDetector[9];
  bool     a4bSource[4];
  bool     bDisplay;
  bool     bPrompt;
  Cstring  sRefineRefln;
  Cstring  sRefineSeq;
  Cstring  sRefineMacroNum;
  Cstring  sRefineMacro[DTP_MAX_REFINE_MACROS];
} tagDtrefineOptions;

typedef struct _tagDtpredictOptions
{
  Cstring  a2sSeqNum[2];
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  a2sRotRange[2];
  Cstring  sMosaicity;
  bool     bSeqOrRot;
  bool     bList;
  bool     bNonunf;
  bool     bDisplay;
} tagDtpredictOptions;

typedef struct _tagDtorientOptions
{
  Cstring  sCrystal1;
  Cstring  sCrystal2;
  Cstring  sLab1;
  Cstring  sLab2;
  Cstring  sLab3;
  Cstring  sRot;
  bool     bRot;
  bool     bDisplay;
} tagDtorientOptions;

typedef struct _tagDtintegrateOptions
{
  Cstring  a2sSeqNum[2];
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  a2sWindow[2];
  Cstring  sPad3D;
  Cstring  a2sProfSize[2];  // Now used for images_per_refine_batch and per_scale_batch
  Cstring  sMinPeakRadius;
  Cstring  sBatchNum;
  Cstring  sBatchPrefix;
  Cstring  sWait;
  Cstring  sDumpRefln;
  Cstring  sPrerefine;
  bool     bDisplay;  // Now used for -differentscan
  bool     bSpecial;
  bool     bSpecial1; // No longer used
  bool     bSpecial2; // No longer used
  bool     bSpecial3; // No longer used 
  bool     bSpecial4;
  bool     bNopurge;  // Now used for -differentdet
} tagDtintegrateOptions;

typedef struct _tagDtmergeOptions
{
  Cstring  sReflnlistNames;
  Cstring  sMergeFilename;
  bool     bDisplay;
} tagDtmergeOptions;

typedef struct _tagDtscaleOptions
{
  Cstring  sExcludeSigma;
  Cstring  sRejectSigma;
  Cstring  sErrorMul;
  Cstring  sErrorAdd;
  Cstring  sMaxCycles;
  Cstring  sFixedBatch;
  Cstring  sInitScale;
  Cstring  sInitFixB;
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  sUnavgFile;
  Cstring  sMergeFile;
  Cstring  sAbscorMethod;
  Cstring  sAbscorRejectSigma;
  Cstring  sUnavgOutputFormat;
  bool     bFixB;
  bool     bUnAvg;
  bool     bAnom;
  bool     bNoHeader;
  bool     bScaleAnom;
} tagDtscaleOptions;

typedef struct _tagDtstrategyOptions
{
  Cstring  sRotStart;
  Cstring  sRotEnd;
  Cstring  sRotRangeMax;
  Cstring  sRotStepCoarse;
  Cstring  sRotStepFine;
  Cstring  sReso1;
  Cstring  sReso2;
  Cstring  sCompletenessMin;
  Cstring  sLScaleFactor;
  Cstring  sPreviousFile;
  Cstring  sPredictedFile;
  bool     bRef;
  bool     bList;
  bool     bPrevious;
  bool     bPredicted;
  bool     bAnom;
} tagDtstrategyOptions;

// End user code block <head>

class MainWindow : public UIComponent

// Begin user code block <superclass>
// End user code block <superclass>
{

// Begin user code block <friends>
// End user code block <friends>

  public:

    MainWindow(const char *, Widget);
    MainWindow(const char *);
    virtual ~MainWindow();
    virtual void create(Widget);
    const char *const  className();
    
    // Begin user code block <public>

#if defined(__NUTC__) || defined(DT_SPLIT_CREATE)
    virtual void create2(Widget);
#endif

    int  nInitValues(Cimage_header& roHeader);
    int  nUpdateHeader(Cimage_header *poHeader=NULL);

    static Cstring ms_sDefaultHeaderTemplateFile;
    static Cstring ms_sDtprocess;
    static Cstring ms_sLockFile;
    XtAppContext m_hAppContext;

    // Some static Cstrings for header items

    static Cstring ms_sSetupOptions;
    static Cstring ms_sDtfindOptions;
    static Cstring ms_sDtindexOptions;
    static Cstring ms_sDtrefineOptions;
    static Cstring ms_sDtrefineMacro[DTP_MAX_REFINE_MACROS];
    static Cstring ms_sDtpredictOptions;
    static Cstring ms_sDtintegrateOptions;
    static Cstring ms_sDtintegrateSpecial;
    static Cstring ms_sDtmergeOptions;
    static Cstring ms_sDtscaleOptions;
    static Cstring ms_sDtorientOptions;
    static Cstring ms_sDtcalibrateOptions;
    static Cstring ms_sDtstrategyOptions;
    static Cstring ms_sDtNoNe;

    int nLoadHeader(const Cstring &rsFilename, const bool bReadWidgets=FALSE);
    void vPreStartPublicCB(Widget w, XtPointer clientData, XtPointer callData);

    // End user code block <public>
  protected:
    // Classes created by this class
    CUIheaderEdit* _cUIheaderEdit;
    CUItextnumArrow* _cUItextnumArrow;
    CUIfileFilter* _cUIfileFilter;
    CUIscrolledlist* _cslLogfile;
    CUIom9* _cUIom9ScaleUnavgOutput;
    CUIom9* _cUIom9ScaleAbscor;
    CUIom9* _cUIom9IntegratePrerefine;
    CUIom9* _cUIom9IntegrateSpecial;
    CUIom9* _cUIomOrientLab3;
    CUIom9* _cUIomOrientLab2;
    CUIom9* _cUIomOrientLab1;
    CUIom9* _cUIomOrientCrystal2;
    CUIom9* _cUIomOrientCrystal1;
    CUIom9* _cUIom9RefineRefln;
    CUIom9* _cUIom9RefineMacros;
    CUIom9* _omIndexMethod;
    CUIom9* _cUIomCalibrateSpatial;
    CUIom9* _cUIomCalibrateNonunf;
    CUIscrolledlist* _cslImages;
    CUIscrolledlist* _cslHeader;
    CUIscrolledlist* _cslReflnlist;
    CUIom9* _cUIomMode;
    
    // Widgets created by this class
    Widget _MainWindow;
    Widget _xmDialogShellHeaderEdit;
    Widget _xmDialogShellTextNum;
    Widget _xmDialogShellProgress;
    Widget _mbProgress;
    Widget _xmDialogShellError;
    Widget _mbError;
    Widget _xmDialogShellFileFilter;
    Widget _meMain;
    Widget _cbFile;
    Widget _pdFile;
    Widget _pbFileOpen;
    Widget _pbFileSaveAs;
    Widget _pbFileHeader;
    Widget _pbFileTemplate;
    Widget _pbFileReflnlist;
    Widget _pbFileLogfile;
    Widget _pbFilePrint;
    Widget _spFile;
    Widget _pbFileCD;
    Widget _pbFileMkdir;
    Widget _spFile2;
    Widget _pbFileExit;
    Widget _cbEdit;
    Widget _pdEdit;
    Widget _pbEditHeader;
    Widget _spEdit;
    Widget _cbEditClear;
    Widget _pdEditClear;
    Widget _pbEditClearAll;
    Widget _pbEditClearSelected;
    Widget _pbEditClearCommand;
    Widget _cbView;
    Widget _pdView;
    Widget _pbViewHeader;
    Widget _pbViewLogfile;
    Widget _tbViewNumAdjust;
    Widget _tbViewCommand;
    Widget _cbUtils;
    Widget _pdUtils;
    Widget _pbUtilsDisplay;
    Widget _pbUtilsCollect;
    Widget _pbUtilsPurge;
    Widget _spUtils;
    Widget _pbUtilsCommand1;
    Widget _pbUtilsCommand2;
    Widget _pbUtilsCommand3;
    Widget _pbUtilsCommand4;
    Widget _pbUtilsCommand5;
    Widget _pbUtilsCommand6;
    Widget _cbHelp;
    Widget _pdHelp;
    Widget _pbHelpHelp;
    Widget _pbHelpThisMenu;
    Widget _pbHelpUpdate;
    Widget _pbHelpAbout;
    Widget _foMain;
    Widget _frLogfile;
    Widget _foLogfile;
    Widget _pbLogfileClear;
    Widget _pbLogfileNo;
    Widget _pbLogfileReturn;
    Widget _pbLogfileYes;
    Widget _tbLogfileAutoscroll;
    Widget _lbLogfileInput;
    Widget _pbLogfileAbort;
    Widget _abLogfileSearch;
    Widget _lbLogfileSearch;
    Widget _tfLogfileSearch;
    Widget _swLogfile;
    Widget _txLogfile;
    Widget _pbLogfileDismiss;
    Widget _seLogfile;
    Widget _frStrategy;
    Widget _foStrategy;
    Widget _tbStrategyAnom;
    Widget _tbStrategyRef;
    Widget _pbStrategyPredicted;
    Widget _tfStrategyPredicted;
    Widget _tbStrategyPredicted;
    Widget _tbStrategyPrevious;
    Widget _tfStrategyPrevious;
    Widget _pbStrategyPrevious;
    Widget _seStrategy;
    Widget _pbStrategyRun;
    Widget _tbStrategyList;
    Widget _tfStrategyRotStepFine;
    Widget _tfStrategyRotStepCoarse;
    Widget _tfStrategyResolution2;
    Widget _tfStrategyResolution1;
    Widget _tfStrategyRotRangeMax;
    Widget _tfStrategyCompleteness;
    Widget _tfStrategyLScale;
    Widget _tfStrategyRotEnd;
    Widget _tfStrategyRotStart;
    Widget _lbStrategyRotStep;
    Widget _lbStrategyResolution;
    Widget _lbStrategyRotRangeMax;
    Widget _lbStrategyCompleteness;
    Widget _lbStrategyLScale;
    Widget _lbStrategyRot;
    Widget _lbMode;
    Widget _frScale;
    Widget _foScale;
    Widget _tbScaleScaleAnom;
    Widget _tfScaleResolution1;
    Widget _tfScaleResolution2;
    Widget _lbScaleResolution;
    Widget _lbScaleUnavgOutput;
    Widget _tbScaleNoHeader;
    Widget _tbScaleTexsan;
    Widget _tfScaleAbscorReject;
    Widget _lbScaleAbscorReject;
    Widget _lbScaleAbscor;
    Widget _pbScaleUnAvg;
    Widget _tfScaleUnAvg;
    Widget _pbScaleMergeFile;
    Widget _tfScaleMergeFile;
    Widget _lbScaleMergeFile;
    Widget _tbScaleUnaverage;
    Widget _lbScaleCycles;
    Widget _tfScaleCycles;
    Widget _tfScaleFixedBatch;
    Widget _lbScaleFixedBatch;
    Widget _tfScaleFixedB;
    Widget _tfScaleFixedScale;
    Widget _lbScaleFixedScale;
    Widget _lbScaleFixedB;
    Widget _tfScaleSigma;
    Widget _lbScaleSigma;
    Widget _pbScaleRun;
    Widget _lbScaleErrorAdd;
    Widget _tfScaleErrorAdd;
    Widget _tfScaleReject;
    Widget _lbScaleReject;
    Widget _tbScaleAnom;
    Widget _tbScaleFixB;
    Widget _tfScaleErrorMul;
    Widget _lbScaleErrorMul;
    Widget _seScale;
    Widget _frMerge;
    Widget _foMerge;
    Widget _pbMergeMergeFile;
    Widget _tfMergeMergeFile;
    Widget _lbMergeMergeFile;
    Widget _pbMergeRun;
    Widget _seMerge;
    Widget _frIntegrate;
    Widget _foIntegrate;
    Widget _lbIntegratePrerefine;
    Widget _tbIntegrateNopurge;
    Widget _tfIntegrateMinPeakRadius;
    Widget _lbIntegrateMinPeakRadius;
    Widget _seIntegrate;
    Widget _pbIntegrateRun;
    Widget _tbIntegrateDisplay;
    Widget _tfIntegrateDump;
    Widget _tfIntegrateProfSize2;
    Widget _tfIntegrateProfSize1;
    Widget _tfIntegrateResolution2;
    Widget _tfIntegrateResolution1;
    Widget _tbIntegrateSpecial1;
    Widget _tbIntegrateSpecial2;
    Widget _tbIntegrateSpecial3;
    Widget _tbIntegrateSpecial4;
    Widget _tfIntegratePadding;
    Widget _tfIntegrateWindow2;
    Widget _tfIntegrateWindow1;
    Widget _tfIntegrateBatchNum;
    Widget _tfIntegrateBatchPrefix;
    Widget _tfIntegrateWait;
    Widget _tfIntegrateSeqEnd;
    Widget _tfIntegrateSeqStart;
    Widget _lbIntegrateDump;
    Widget _lbIntegrateProfSize;
    Widget _lbIntegrateResolution;
    Widget _seIntegrate1;
    Widget _lbIntegratePadding;
    Widget _lbIntegrateWindow;
    Widget _lbIntegrateBatchNum;
    Widget _lbIntegrateBatchPrefix;
    Widget _lbIntegrateWait;
    Widget _lbIntegrateSeq;
    Widget _frOrient;
    Widget _foOrient;
    Widget _lbOrient1;
    Widget _lbOrientRotDegrees;
    Widget _tfOrientRot;
    Widget _lbOrientRot;
    Widget _lbOrientParallel2;
    Widget _lbOrientParallel1;
    Widget _lbOrientLab2;
    Widget _lbOrientLab1;
    Widget _lbOrientCrystal2;
    Widget _lbOrientCrystal1;
    Widget _pbOrientRun;
    Widget _seOrient;
    Widget _lbOrient;
    Widget _frPredict;
    Widget _foPredict;
    Widget _tfPredictMosaicity;
    Widget _lbPredictMosaicity;
    Widget _pbPredictRun;
    Widget _lbPredictResolution;
    Widget _tfPredictResolution2;
    Widget _tfPredictResolution1;
    Widget _tfPredictSeqStart;
    Widget _tfPredictSeqEnd;
    Widget _lbPredictSeq;
    Widget _tbPredictList;
    Widget _tbPredictNonunf;
    Widget _tfPredictRotEnd;
    Widget _tfPredictRotStart;
    Widget _lbPredictRot;
    Widget _tbPredictDisplay;
    Widget _sePredict;
    Widget _frRefine;
    Widget _foRefine1;
    Widget _lbRefineRefln;
    Widget _tbRefinePrompt;
    Widget _foRefineMacro;
    Widget _lbRefineMacro;
    Widget _swRefineMacro;
    Widget _txRefineMacro;
    Widget _seRefine4;
    Widget _pbRefineRun;
    Widget _seRefine;
    Widget _tbRefineDisplay;
    Widget _lbRefineMacros;
    Widget _foRefine;
    Widget _tbRefineTestMosaicity;
    Widget _tbRefineSourceRots;
    Widget _seRefine3;
    Widget _seRefine2;
    Widget _tbRefineCrystalMosaicity;
    Widget _tbRefineCrystalCell;
    Widget _tbRefineDetAll;
    Widget _tbRefineCrystalAll;
    Widget _tfRefineRelWeight;
    Widget _tfRefineCycles;
    Widget _tfRefineReject3;
    Widget _tfRefineReject2;
    Widget _tfRefineReject1;
    Widget _lbRefineCycles;
    Widget _lbRefineRelWeight;
    Widget _lbRefineReject;
    Widget _seRefine1;
    Widget _tbRefineSourceWavelength;
    Widget _tbRefineSourceRot2;
    Widget _tbRefineSourceRot1;
    Widget _tbRefineDetRots;
    Widget _tbRefineDetTrans;
    Widget _tbRefineDetRot3;
    Widget _tbRefineDetRot2;
    Widget _tbRefineDetRot1;
    Widget _tbRefineDetTrans3;
    Widget _tbRefineDetTrans2;
    Widget _tbRefineDetTrans1;
    Widget _lbRefineSource;
    Widget _lbRefineDet;
    Widget _tbRefineCrystalRots;
    Widget _tbRefineCrystalAngles;
    Widget _tbRefineCrystalLengths;
    Widget _tbRefineCrystalRot2;
    Widget _tbRefineCrystalRot1;
    Widget _tbRefineCrystalRot3;
    Widget _tbRefineCrystalGammastar;
    Widget _tbRefineCrystalBetastar;
    Widget _tbRefineCrystalAlphastar;
    Widget _tbRefineCrystalCstar;
    Widget _tbRefineCrystalBstar;
    Widget _lbRefineCrystal;
    Widget _tbRefineCrystalAstar;
    Widget _tfRefineResolution2;
    Widget _tfRefineResolution1;
    Widget _tfRefineSigma;
    Widget _lbRefineResolution;
    Widget _lbRefineSigma;
    Widget _frIndex;
    Widget _foIndex;
    Widget _lbIndexMethod;
    Widget _tbIndexDiffs;
    Widget _tfIndexSigma;
    Widget _tfIndexResolution2;
    Widget _tfIndexResolution1;
    Widget _lbIndexResolution;
    Widget _lbIndexSigma;
    Widget _tbIndexAdvanced;
    Widget _tfIndexMaxResid;
    Widget _lbIndexMaxResid;
    Widget _tfIndexSpacegroup;
    Widget _lbIndexSpacegroup;
    Widget _tbIndexKnown;
    Widget _pbIndexRun;
    Widget _tbIndexPrompt;
    Widget _tbIndexList;
    Widget _tfIndexErrorAngle3;
    Widget _tfIndexErrorAngle2;
    Widget _tfIndexErrorAngle1;
    Widget _tfIndexErrorLength3;
    Widget _tfIndexErrorLength2;
    Widget _tfIndexErrorLength1;
    Widget _tfIndexGrid;
    Widget _tfIndexMaxCell;
    Widget _tfIndexMaxDiffs;
    Widget _lbIndexErrorAngle;
    Widget _lbIndexErrorLength;
    Widget _seIndex;
    Widget _lbIndexGrid;
    Widget _lbIndexMaxCell;
    Widget _lbIndexMaxDiffs;
    Widget _frFind;
    Widget _foFind;
    Widget _tfFindResolution1;
    Widget _tfFindResolution2;
    Widget _lbFindResolution;
    Widget _tbFindMore;
    Widget _seFind1;
    Widget _pbFindRun;
    Widget _tbFind3D;
    Widget _tbFindDisplay;
    Widget _tfFindDump;
    Widget _tfFindRect4;
    Widget _tfFindRect3;
    Widget _tfFindRect2;
    Widget _tfFindRect1;
    Widget _tfFindCircle4;
    Widget _tfFindCircle3;
    Widget _tfFindCircle2;
    Widget _tfFindCircle1;
    Widget _tfFindBackRect2;
    Widget _tfFindBackRect1;
    Widget _tfFindPadding;
    Widget _tfFindWindow2;
    Widget _tfFindWindow1;
    Widget _tfFindFilter;
    Widget _tfFindMin;
    Widget _tfFindSigma;
    Widget _tfFindSeqEnd;
    Widget _tfFindSeqStart;
    Widget _lbFindDump;
    Widget _lbFindRect;
    Widget _lbFindCircle;
    Widget _lbFindBackRect;
    Widget _seFind;
    Widget _lbFindPadding;
    Widget _lbFindWindow;
    Widget _lbFindFilter;
    Widget _lbFindMin;
    Widget _lbFindSigma;
    Widget _lbFindSeq;
    Widget _frCalibrate;
    Widget _foCalibrate;
    Widget _tbCalibrateModeSmall;
    Widget _tbCalibrateIndexPrompt;
    Widget _tfCalibratedTREKPrefix;
    Widget _lbCalibratedTREKPrefix;
    Widget _tfCalibrateWindow2;
    Widget _tfCalibrateWindow1;
    Widget _lbCalibrateWindow;
    Widget _tfCalibrateResolution1;
    Widget _tfCalibrateResolution2;
    Widget _lbCalibrateResolution;
    Widget _lbCalibrateSpacegroup;
    Widget _tfCalibrateSpacegroup;
    Widget _lbCalibrateDetTheta;
    Widget _tfCalibrateDetTheta;
    Widget _tfCalibrateDetDist;
    Widget _lbCalibrateDetDist;
    Widget _pbCalibrateTemplate;
    Widget _tfCalibrateTemplate;
    Widget _lbCalibrateTemplate;
    Widget _tfCalibrateNonunfNonunf;
    Widget _lbCalibrateNonunfNonunf;
    Widget _pbCalibrateNonunfNonunf;
    Widget _tfCalibrateNonunfDark;
    Widget _lbCalibrateNonunfDark;
    Widget _pbCalibrateNonunfDark;
    Widget _lbCalibrateNonunf;
    Widget _pbCalibrateSpatialInterp;
    Widget _tfCalibrateSpatialInterp;
    Widget _lbCalibrateSpatialInterp;
    Widget _tfCalibrateSpatialSimple2;
    Widget _tfCalibrateSpatialSimple1;
    Widget _lbCalibrateSpatialSimple;
    Widget _lbCalibrateSpatial;
    Widget _lbCalibrateDirectBeam;
    Widget _tfCalibrateDirBeam2;
    Widget _tfCalibrateDirBeam1;
    Widget _seCalibrate;
    Widget _pbCalibrateRun;
    Widget _lbCommand;
    Widget _tfCommand;
    Widget _swOutput;
    Widget _txOutput;
    Widget _frLists;
    Widget _frFlowchart;
    Widget _daFlowchart;
    Widget _pbCalibrate;
    Widget _pbFind;
    Widget _pbIndex;
    Widget _pbRefine;
    Widget _pbPredict;
    Widget _pbIntegrate;
    Widget _pbMerge;
    Widget _pbScale;
    Widget _pbOrient;
    Widget _pbStrategy;
    
    // These virtual functions are called from the private callbacks 
    // or event handlers intended to be overridden in derived classes
    // to define actions
    
    virtual void vProgressCB(Widget, XtPointer, XtPointer);
    virtual void vUnpostHelpCB(Widget, XtPointer, XtPointer);
    virtual void vPostHelpCB(Widget, XtPointer, XtPointer);
    virtual void vPopDialog(Widget, XtPointer, XtPointer);
    virtual void vExitCB(Widget, XtPointer, XtPointer);
    virtual void vEditClearCB(Widget, XtPointer, XtPointer);
    virtual void vToggleButtonCB(Widget, XtPointer, XtPointer);
    virtual void vUtilsCB(Widget, XtPointer, XtPointer);
    virtual void vHelpCB(Widget, XtPointer, XtPointer);
    virtual void vLogfileCB(Widget, XtPointer, XtPointer);
    virtual void vUnPostHelp(Widget, XtPointer, XtPointer);
    virtual void vStrategyCB(Widget, XtPointer, XtPointer);
    virtual void vStrategyTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vScaleCB(Widget, XtPointer, XtPointer);
    virtual void vScaleTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vMergeCB(Widget, XtPointer, XtPointer);
    virtual void vMergeTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vIntegrateCB(Widget, XtPointer, XtPointer);
    virtual void vIntegrateTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vOrientTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vOrientCB(Widget, XtPointer, XtPointer);
    virtual void vPredictTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vPredictCB(Widget, XtPointer, XtPointer);
    virtual void vRefineCB(Widget, XtPointer, XtPointer);
    virtual void vRefineTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vIndexCB(Widget, XtPointer, XtPointer);
    virtual void vIndexTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vFindTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vFindCB(Widget, XtPointer, XtPointer);
    virtual void vCalibrateCB(Widget, XtPointer, XtPointer);
    virtual void vCalibrateTextFieldCB(Widget, XtPointer, XtPointer);
    virtual void vCommandCB(Widget, XtPointer, XtPointer);
    virtual void vDAExposeCB(Widget, XtPointer, XtPointer);
    virtual void vFlowChartCB(Widget, XtPointer, XtPointer);
    
    // Begin user code block <protected>
    virtual void vSetLabel(Widget w, char *pcLabel, char *pcColor=NULL);
    virtual void vSetResoOther(Widget wResoIn, Widget wResoOther, Cstring sResoOtherIn, Cstring *psResoSet);
    // End user code block <protected>
  private: 
    
    //
    // Default application and class resources.
    //
    static String         _defaultMainWindowResources[];
    static UIAppDefault   _appDefaults[];
    static Boolean        _initAppDefaults;
    //
    // Callback client data.
    //
    UICallbackStruct  *_clientDataStructs;
    
    //
    // Callbacks to interface with Motif.
    //
    static void vProgressCBCallback(Widget, XtPointer, XtPointer);
    static void vUnpostHelpCBCallback(Widget, XtPointer, XtPointer);
    static void vPostHelpCBCallback(Widget, XtPointer, XtPointer);
    static void vPopDialogCallback(Widget, XtPointer, XtPointer);
    static void vExitCBCallback(Widget, XtPointer, XtPointer);
    static void vEditClearCBCallback(Widget, XtPointer, XtPointer);
    static void vToggleButtonCBCallback(Widget, XtPointer, XtPointer);
    static void vUtilsCBCallback(Widget, XtPointer, XtPointer);
    static void vHelpCBCallback(Widget, XtPointer, XtPointer);
    static void vLogfileCBCallback(Widget, XtPointer, XtPointer);
    static void vUnPostHelpCallback(Widget, XtPointer, XtPointer);
    static void vStrategyCBCallback(Widget, XtPointer, XtPointer);
    static void vStrategyTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vScaleCBCallback(Widget, XtPointer, XtPointer);
    static void vScaleTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vMergeCBCallback(Widget, XtPointer, XtPointer);
    static void vMergeTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vIntegrateCBCallback(Widget, XtPointer, XtPointer);
    static void vIntegrateTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vOrientTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vOrientCBCallback(Widget, XtPointer, XtPointer);
    static void vPredictTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vPredictCBCallback(Widget, XtPointer, XtPointer);
    static void vRefineCBCallback(Widget, XtPointer, XtPointer);
    static void vRefineTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vIndexCBCallback(Widget, XtPointer, XtPointer);
    static void vIndexTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vFindTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vFindCBCallback(Widget, XtPointer, XtPointer);
    static void vCalibrateCBCallback(Widget, XtPointer, XtPointer);
    static void vCalibrateTextFieldCBCallback(Widget, XtPointer, XtPointer);
    static void vCommandCBCallback(Widget, XtPointer, XtPointer);
    static void vDAExposeCBCallback(Widget, XtPointer, XtPointer);
    static void vFlowChartCBCallback(Widget, XtPointer, XtPointer);
    
    // Begin user code block <private>

    // Callback client data.

    UICallbackStruct  *m_ptClientDataStructs;
    Cardinal    m_nCDC;

    GC          m_hGC;
    XGCValues   m_hGCValues;
    Pixmap      m_hPixmap;

    void vDestroy(void);
    static  void vNumberAdjustCBCallback(Widget, XtPointer, XtPointer);
    virtual void vNumberAdjustCB(Widget, XtPointer, XtPointer);

    static  void vFileFilterCBCallback(XtPointer, Widget, int, XtPointer);
    virtual void vFileFilterCB(XtPointer, Widget, int, XtPointer);

    static  void vScrolledListCBCallback(XtPointer, Widget, XtPointer);
    virtual void vScrolledListCB(XtPointer, Widget, XtPointer);

    static  void vCUIom9CBCallback(XtPointer, Widget, XtPointer, XtPointer);
    virtual void vCUIom9CB(XtPointer, Widget, XtPointer, XtPointer);

    static  void vHeaderEditCBCallback(XtPointer, Widget, XtPointer, XtPointer);
    virtual void vHeaderEditCB(XtPointer, Widget, XtPointer, XtPointer);

    static void vPostError(Widget, XtPointer, XtPointer);

    virtual void vPutMessage(const char *pcMessage, const int nFlag=0);
    inline  void vPutMessage(const Cstring &sMessage, const int nFlag=0)
      {vPutMessage(sMessage.string(), nFlag); }

    void  (MainWindow::*m_prvDialogCB)(Widget, XtPointer, XtPointer);
    static  void vWorkProc1(XtPointer, XtIntervalId*);

    void vCommandExecute(const Cstring &rsCommand, const int nInput = 0);
    void vCommandDone(void);
    void vUpdateFlowChart(Widget w);
    void vDrawInFlowChart(Widget w);

    virtual int nIntegrateSpecial(Cstring *psCommand);
    virtual int nScaleAbsorp(Cstring *psCommand);

    XtIntervalId    m_hIntervalId;
    Widget          m_wpbFilterButton;
    Cimage_header  *m_poHeader;
    Cstring         m_sHeaderDir;
    Cstring         m_sHeaderName;
    Cstring         m_sHeaderMask;
    Cstring         m_sImageDir;
    Cstring         m_sImageName;
    Cstring         m_sImageMask;
    Cstring         m_sReflnlistDir;
    Cstring         m_sReflnlistName;
    Cstring         m_sReflnlistMask;
    Cstring         m_sLogfileDir;
    Cstring         m_sLogfileName;
    Cstring         m_sLogfileMask;

    Cstring         m_sCalibrateSpatialDir;
    Cstring         m_sCalibrateSpatialName;
    Cstring         m_sCalibrateSpatialMask;
    Cstring         m_sCalibrateNonunfDir;
    Cstring         m_sCalibrateNonunfName;
    Cstring         m_sCalibrateNonunfMask;
    Cstring         m_sCalibrateDarkDir;
    Cstring         m_sCalibrateDarkName;
    Cstring         m_sCalibrateDarkMask;
    Cstring         m_sMergeMergeDir;
    Cstring         m_sMergeMergeName;
    Cstring         m_sMergeMergeMask;
    Cstring         m_sScaleMergeDir;
    Cstring         m_sScaleMergeName;
    Cstring         m_sScaleMergeMask;
    Cstring         m_sScaleUnavgDir;
    Cstring         m_sScaleUnavgName;
    Cstring         m_sScaleUnavgMask;
    Cstring         m_sStrategyPreviousDir;
    Cstring         m_sStrategyPreviousName;
    Cstring         m_sStrategyPreviousMask;
    Cstring         m_sStrategyPredictDir;
    Cstring         m_sStrategyPredictName;
    Cstring         m_sStrategyPredictMask;
    
    CXhelp         *m_poXhelp;
    CXcursor       *m_poXcursor;
    CXprop         *m_poXprop;
    Cstring         m_sSubProcessCommand;
    int             m_nSubProcessPID;
    FILE           *m_pSubProcessStdIn;
    int             m_nSavePID;

    Widget         *m_pwpbFlowChart[DTP_DLG_MAXBUTTONS];
    Widget         *m_pwfrMain[DTP_DLG_MAXBUTTONS];
    Widget         *m_pwpbDialogRun[DTP_DLG_MAXBUTTONS];
    Widget         *m_pwtfRefineMacros[9];
    int             m_nRefineMacro;
    int             m_nScaleAbscorMethod;
    int             m_nIndexMethod;
    Widget          m_pbDialogRun;
    Widget          m_wpbFlowChart;
    Widget          m_wFCActive;
    int             m_nFCActive;
    bool            m_bFCDialogRun;
    Cstring         m_sLogFilename;
    Cstring         m_sLogfileSearchString;
    Cstring         m_sFilePrintCommand;
    unsigned char   m_ucLogfileSearchDirection;
    int             m_nLogfileType;
    long int        m_lLogfileSize;
    long int        m_lLogfileSizeShown;

#define DTP_MCTEMPSIZE 8192
    char       m_acTemp[DTP_MCTEMPSIZE*2 + 1]; // A temporary place to sprintf to
      
    // dtcalibrate stuff

      Cstring m_sCalibrateCommand;
      Cstring m_sCalibrateExtra;
      tagDtcalibrateOptions  m_tDtcalibrateOptions;

    // dtfind stuff

      Cstring m_sFindCommand;
      Cstring m_sFindExtra;
      tagDtfindOptions  m_tDtfindOptions;

    // dtindex stuff

      Cstring m_sIndexCommand;
      Cstring m_sIndexExtra;
      tagDtindexOptions m_tDtindexOptions;

    // dtrefine stuff

      Cstring m_sRefineCommand;
      Cstring m_sRefineExtra;
      tagDtrefineOptions m_tDtrefineOptions;

    // dtpredict stuff

      Cstring m_sPredictCommand;
      Cstring m_sPredictExtra;
      tagDtpredictOptions m_tDtpredictOptions;

    // dtintegrate stuff

      Cstring m_sIntegrateCommand;
      Cstring m_sIntegrateExtra;
      tagDtintegrateOptions  m_tDtintegrateOptions;

    // dtorient stuff

      Cstring m_sOrientCommand;
      Cstring m_sOrientExtra;
      tagDtorientOptions  m_tDtorientOptions;

    // dtreflnmerge stuff

      Cstring m_sMergeCommand;
      Cstring m_sMergeExtra;
      tagDtmergeOptions  m_tDtmergeOptions;

    // dtscalemerge stuff

      Cstring m_sScaleCommand;
      Cstring m_sScaleExtra;
      tagDtscaleOptions  m_tDtscaleOptions;

    // dtstrategy stuff

      Cstring m_sStrategyCommand;
      Cstring m_sStrategyExtra;
      tagDtstrategyOptions  m_tDtstrategyOptions;

    int   m_a2nSeqNum[2];
    Cscan *m_poScan;

    XPoint m_hPoints[3];

    // End user code block <private>
};

// Begin user code block <tail>
// End user code block <tail>
#endif
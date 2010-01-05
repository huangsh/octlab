/*******************************************************************************
*  $Id$
*  Copyright (C) 2010 Stepan A. Baranov (stepan@baranov.su)
*  All rights reserved.
*  web-site: www.OCTLab.org
*  *****                              *******                              *****
*  Use of this source code is governed by a Clear BSD-style license that can be
*  found on the http://octlab.googlecode.com/svn/trunk/COPYRIGHT.TXT web-page or
*  in the COPYRIGHT.TXT file
*******************************************************************************/

// standart headers
#include <functional>
#include <algorithm>
// common header
#include "./OCTLib.h"

// for DLL export
extern "C" {
DllExport I8 OL_simple_doppler(U32, U32, DBL *);
}

// simple Doppler main function
I8 OL_simple_doppler(U32 X, U32 Y, DBL *ptr) {
  transform(ptr, ptr + (Y - 1) * X, ptr + X, ptr, minus<DBL>());
  fill(ptr + (Y - 1) * X, ptr + Y * X, 0.0);
  return EXIT_SUCCESS;
}

/*******************************************************************************
Checked by http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py
*******************************************************************************/

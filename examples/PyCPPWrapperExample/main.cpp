/*
 *
 *  Copyright (C) 2006 MeVis Research GmbH All Rights Reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  Further, this software is distributed without any warranty that it is
 *  free of the rightful claim of any third person regarding infringement
 *  or the like.  Any license provided herein, whether implied or
 *  otherwise, applies only to this software file.  Patent licenses, if
 *  any, provided herein do not apply to combinations of this program with
 *  other software, or any other product whatsoever.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact information: MeVis Research GmbH, Universitaetsallee 29,
 *  28359 Bremen, Germany or:
 *
 *  http://www.mevis.de
 *
 */

//----------------------------------------------------------------------------------
/*!
// \file    PyGuiExample.cpp
// \author  Florian Link
// \author  Last changed by $Author: florian $
// \date    2007-04
*/
//----------------------------------------------------------------------------------

#include "PythonQt.h"
#include "gui/PythonQtScriptingConsole.h"
#include "CustomObjects.h"

#include <QApplication>

int main( int argc, char **argv )
{
  QApplication qapp(argc, argv);

  PythonQt::init(PythonQt::IgnoreSiteModule | PythonQt::RedirectStdOut);

  PythonQtObjectPtr  mainContext = PythonQt::self()->getMainModule();
  PythonQtScriptingConsole console(NULL, mainContext);

  // -----------------------------------------------------------------
  // Alternative 1: make CustomObject known and use decorators for wrapping:
  // -----------------------------------------------------------------
  
  // register the new object as a known classname
  PythonQt::self()->registerCPPClassNames(QStringList() << "CustomObject");
  // add a decorator which can access CustomObject instances
  PythonQt::self()->addDecorators(new CustomObjectWrapper());

  // -----------------------------------------------------------------
  // Alternative 2: make CustomObject2 known and use a wrapper factory for wrapping:
  // -----------------------------------------------------------------

  // add a factory that can handle pointers to CustomObject2
  PythonQt::self()->addWrapperFactory(new CustomFactory());

  // the following is optional and only needed if you want a constructor:
  // register the new object as a known classname
  PythonQt::self()->registerCPPClassNames(QStringList() << "CustomObject2");
  // add a constructor for CustomObject2
  PythonQt::self()->addClassDecorators(new CustomObject2Constructor());

  mainContext.evalFile(":example.py");

  console.appendCommandPrompt();
  console.show();

  return qapp.exec();
}


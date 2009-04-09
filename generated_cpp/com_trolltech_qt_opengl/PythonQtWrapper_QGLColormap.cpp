#include "PythonQtWrapper_QGLColormap.h"

#include <QVariant>
#include <qcolor.h>
#include <qglcolormap.h>

QGLColormap* PythonQtWrapper_QGLColormap::new_QGLColormap()
{ 
return new QGLColormap(); }

QGLColormap* PythonQtWrapper_QGLColormap::new_QGLColormap(const QGLColormap&  arg__1)
{ 
return new QGLColormap(arg__1); }

QColor  PythonQtWrapper_QGLColormap::entryColor(QGLColormap* theWrappedObject, int  idx) const
{
return theWrappedObject->entryColor(idx);
}

unsigned int  PythonQtWrapper_QGLColormap::entryRgb(QGLColormap* theWrappedObject, int  idx) const
{
return theWrappedObject->entryRgb(idx);
}

int  PythonQtWrapper_QGLColormap::find(QGLColormap* theWrappedObject, unsigned int  color) const
{
return theWrappedObject->find(color);
}

int  PythonQtWrapper_QGLColormap::findNearest(QGLColormap* theWrappedObject, unsigned int  color) const
{
return theWrappedObject->findNearest(color);
}

bool  PythonQtWrapper_QGLColormap::isEmpty(QGLColormap* theWrappedObject) const
{
return theWrappedObject->isEmpty();
}

void PythonQtWrapper_QGLColormap::setEntries(QGLColormap* theWrappedObject, int  count, const unsigned int*  colors, int  base)
{
theWrappedObject->setEntries(count, colors, base);
}

void PythonQtWrapper_QGLColormap::setEntry(QGLColormap* theWrappedObject, int  idx, const QColor&  color)
{
theWrappedObject->setEntry(idx, color);
}

void PythonQtWrapper_QGLColormap::setEntry(QGLColormap* theWrappedObject, int  idx, unsigned int  color)
{
theWrappedObject->setEntry(idx, color);
}

int  PythonQtWrapper_QGLColormap::size(QGLColormap* theWrappedObject) const
{
return theWrappedObject->size();
}

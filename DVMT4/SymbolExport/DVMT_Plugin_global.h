#ifndef DVMT_PLUGIN_GLOBAL_H
#define DVMT_PLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DVMT_PLUGIN_LIBRARY)
#  define DVMT_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define DVMT_PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // DVMT_PLUGIN_GLOBAL_H

#ifndef DL_H
#define DL_H

#include <dlfcn.h>

#ifdef __CYGWIN_
#define LOOKUP_SYMBOL(dl_handle, sym) \
	f.sym ## _fn = &sym;
#else
#define LOOKUP_SYMBOL(dl_handle, sym) \
       f.sym ## _fn = dlsym(dl_handle, #sym); \
       if ((f.sym ## _fn) == NULL) { \
               csync_fatal ("Could not lookup %s in shared library: %s\n", #sym, dlerror()); \
       }
#endif

#endif

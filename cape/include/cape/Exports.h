
#ifndef CAPE_EXPORT_H
#define CAPE_EXPORT_H

#ifdef CAPE_STATIC_DEFINE
#  define CAPE_EXPORT
#  define CAPE_NO_EXPORT
#else
#  ifndef CAPE_EXPORT
#    ifdef cape_EXPORTS
        /* We are building this library */
#      define CAPE_EXPORT 
#    else
        /* We are using this library */
#      define CAPE_EXPORT 
#    endif
#  endif

#  ifndef CAPE_NO_EXPORT
#    define CAPE_NO_EXPORT 
#  endif
#endif

#ifndef CAPE_DEPRECATED
#  define CAPE_DEPRECATED __declspec(deprecated)
#endif

#ifndef CAPE_DEPRECATED_EXPORT
#  define CAPE_DEPRECATED_EXPORT CAPE_EXPORT CAPE_DEPRECATED
#endif

#ifndef CAPE_DEPRECATED_NO_EXPORT
#  define CAPE_DEPRECATED_NO_EXPORT CAPE_NO_EXPORT CAPE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CAPE_NO_DEPRECATED
#    define CAPE_NO_DEPRECATED
#  endif
#endif

#endif /* CAPE_EXPORT_H */

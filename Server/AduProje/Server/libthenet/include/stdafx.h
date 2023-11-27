#ifndef __INC_LIBTHENET_STDAFX_H__
#define __INC_LIBTHENET_STDAFX_H__


#if __cplusplus >= 201103L
#	define CXX11_ENABLED
#endif

#if defined(__clang__) || defined(CXX11_ENABLED)
#	ifndef __STDC_LIMIT_MACROS
#		define __STDC_LIMIT_MACROS
#	endif
#	include <cinttypes>
#	include <cstdint>
#else
#	include <inttypes.h>
#	include <stdint.h>
#	ifndef INT64_MAX
#		define INT64_MAX 0x7fFFffFFffFFffFFLL
#	endif
#endif


#if defined(__GNUC__)
#define INLINE __inline__
#elif defined(_MSC_VER)
#define INLINE inline
#endif

#ifndef __FreeBSD__
#define __USE_SELECT__
#ifdef __CYGWIN__
#define _POSIX_SOURCE 1
#endif
#endif

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <dirent.h>

#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#include <sys/signal.h>
#include <sys/wait.h>

#include <pthread.h>
#include <semaphore.h>

#ifdef __FreeBSD__
#include <sys/event.h>
#endif

#define typeof(x) __typeof__(x)

#ifndef false
#define false	false
#define true	(!false)
#endif

#ifndef FALSE
#define FALSE	false
#define TRUE	(!FALSE)
#endif

#include "typedef.h"
#include "socket.h"
#include "fdwatch.h"
#include "utils.h"

#endif // __INC_LIBTHENET_STDAFX_H__
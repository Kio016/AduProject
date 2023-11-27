#ifndef __INC_LIBTHENET_FDWATCH_H__
#define __INC_LIBTHENET_FDWATCH_H__

typedef struct fdwatch FDWATCH;
typedef struct fdwatch *LPFDWATCH;

enum EFdwatch
{
    FDW_NONE, FDW_READ, FDW_WRITE
};

typedef struct kevent KEVENT;
typedef struct kevent *LPKEVENT;
typedef int KQUEUE;

struct fdwatch
{
	KQUEUE kq;

	int nfiles;

	LPKEVENT kqevents;
	int nkqevents;

	LPKEVENT kqrevents;
	int *fd_event_idx;

	void **fd_data;
	int *fd_rw;
};

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

    extern LPFDWATCH fdwatch_new(int nfiles);
    extern void fdwatch_add_fd(LPFDWATCH fdw, socket_t fd, void* client_data, int rw);

#ifdef __cplusplus
}
#endif

#endif

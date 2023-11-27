#ifndef __INC_LIBTHENET_UTILS_H__
#define __INC_LIBTHENET_UTILS_H__

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define CREATE(result, type, number)                                  \
    do                                                                \
    {                                                                 \
        if (!((result) = (type *)calloc((number), sizeof(type))))     \
        {                                                             \
            sys_err("calloc failed [%d] %s", errno, strerror(errno)); \
            abort();                                                  \
        }                                                             \
    } while (0)
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __INC_UTILS_H__
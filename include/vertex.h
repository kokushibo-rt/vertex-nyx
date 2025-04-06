#ifndef VERTEX_H_
#define VERTEX_H_

#ifdef __cplusplus
#define _SFY(x) #x
#define _TO_STR(x) _SFY(x)
# pragma message("Using C++ version of framework:" _TO_STR(__cplusplus))
#undef _TO_STR
#undef _SFY
#endif

#include "vertex/std/hardware/gpio.h"

#endif // VERTEX_H_

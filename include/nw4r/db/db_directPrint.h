#ifndef NW4R_DB_DIRECTPRINT_H
#define NW4R_DB_DIRECTPRINT_H

#ifdef VERSION_RSPE01_00

#include <revolution/GX.h>

namespace nw4r {
namespace db {

void DirectPrint_Init();
bool DirectPrint_IsActive();
void DirectPrint_ChangeXfb(void* frameBuf, u16 width, u16 height);
void DirectPrint_ChangeXfb(void* frameBuf);

namespace detail {

void* DirectPrint_SetupFB(const GXRenderModeObj* rmode);

} // namespace detail

} // namespace db
} // namespace nw4r

#endif

#endif

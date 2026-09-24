#include <egg/gfxe.h>

namespace EGG {
void LightManager::SetChanAmbColor() const {
    GXColor localColor = *m_pAmbColor0;

    GXSetChanAmbColor(GX_COLOR0A0, localColor);
    GXSetChanAmbColor(GX_COLOR1A1, DrawGX::BLACK);
}
} // namespace EGG

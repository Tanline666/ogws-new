#ifndef RP_SPORTS_MENU_BG_MODEL_H
#define RP_SPORTS_MENU_BG_MODEL_H
#include <Pack/types_pack.h>

#include <Pack/RPGraphics.h>
#include <Pack/RPKernel.h>
#include <Pack/RPSingleton.h>

class RPSportsMenuBgModel : public RP_DEBUG_STUB_1 {
protected:
    /**
     * @brief Constructor
     */
    RPSportsMenuBgModel(u8 unk, u8 drawScene, u16 flags);

    /**
     * @brief Destructor
     */
    virtual ~RPSportsMenuBgModel();

public:
    /**
     * @brief Creates background model
     *
     * @param modelArchive Pointer to archive with model data. Defaults to
     * common archive if left blank
     */
    void createData(EGG::Archive* modelArchive);

    /**
     * @brief Initializes variables and starts animation process
     */
    void initCamera();

    /**
     * @brief Calculates view transformation matrix every frame
     */
    void calcView();

private:
    u8 mViewNo;                  // at 0x4
    u8 mDrawScene;               // at 0x5
    u16 mFlags;                  // at 0x6
    RPGrpModel* mpModel;         // at 0x8
    RPGrpCamera* mpCamera;       // at 0xC
    nw4r::math::VEC3 mEyeView;   // at 0x10
    nw4r::math::VEC3 mBaseScale; // at 0x1C
};

#endif

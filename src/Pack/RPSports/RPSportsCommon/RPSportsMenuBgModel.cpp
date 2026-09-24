#include <Pack/RPSports/RPSportsCommon.h>

#include <nw4r/g3d.h>

RPSportsMenuBgModel::~RPSportsMenuBgModel() {}

RPSportsMenuBgModel::RPSportsMenuBgModel(u8 viewNo, u8 drawScene, u16 flags)
    : mViewNo(viewNo), mDrawScene(drawScene), mFlags(flags), mpModel(NULL) {
    RPGrpScreen* screen;

    mpCamera = new RPGrpCamera;
    mpCamera->SetCameraType(RPGrpCamera::ECameraType_LookAt);
    screen = new RPGrpScreen;
    screen->SetCanvasMode(EGG::Frustum::CANVAS_CC);
    screen->SetFovy(30.0f);
    RPGrpRenderer::GetCurrent()->CreateView3D(viewNo, mpCamera, screen);
}

void RPSportsMenuBgModel::createData(EGG::Archive* modelArchive) {
    void* modelFile;
    RPGrpHandle resFileHandle;
    void* resModelPtr;
    RPGrpHandle resModelHandle;
    void* resAnmChrPtr;
    void* resAnmTexSrtPtr;
    void* resAnmClrPtr;

#define RP_CREATE_MDL_DATA(type, data)                                         \
    RPGrpModelResManager::GetCurrent()->CreateData(type, data);
#define RP_GET_MDL_PTR(type)                                                   \
    RPGrpModelResManager::GetCurrent()->GetPtr(type, resFileHandle,            \
                                               "menu_BG_model");

    if (modelArchive == NULL) {
        modelArchive =
            RP_GET_INSTANCE(RPSysResourceManager)->LoadGameCommonArchive();
    }
    modelFile =
        RP_GET_INSTANCE(RPSysResourceManager)
            ->GetFileFromArchive(modelArchive, "G3D/menu_BG_model.brres");
    resFileHandle =
        RP_CREATE_MDL_DATA(RPGrpModelResManager::Type_ResFile, modelFile);

    resModelPtr = RP_GET_MDL_PTR(RPGrpModelResManager::Type_ResFile);
    resModelHandle =
        RP_CREATE_MDL_DATA(RPGrpModelResManager::Type_ResMdl, resModelPtr);

    resAnmChrPtr = RP_GET_MDL_PTR(RPGrpModelResManager::Type_ResAnmChr);
    RP_CREATE_MDL_DATA(RPGrpModelResManager::Type_ResAnmChr, resAnmChrPtr);

    resAnmTexSrtPtr = RP_GET_MDL_PTR(RPGrpModelResManager::Type_ResAnmTexSrt);
    RP_CREATE_MDL_DATA(RPGrpModelResManager::Type_ResAnmTexSrt,
                       resAnmTexSrtPtr);

    resAnmClrPtr = RP_GET_MDL_PTR(RPGrpModelResManager::Type_ResAnmClr);
    RP_CREATE_MDL_DATA(RPGrpModelResManager::Type_ResAnmClr, resAnmClrPtr);

    mpModel = RPGrpModel::Construct(resModelHandle, 1, 0, 0);

    mpModel->GetModelAnm()->CreateBuffer(RPGrpModelAnm::Anm_Chr, 1);
    mpModel->GetModelAnm()->CreateBuffer(RPGrpModelAnm::Anm_TexSrt, 1);
    mpModel->GetModelAnm()->CreateBuffer(RPGrpModelAnm::Anm_Clr, 1);
    mpModel->GetModelAnm()->Regist(RPGrpModelAnm::Anm_Chr, 0, 0);
    mpModel->GetModelAnm()->Regist(RPGrpModelAnm::Anm_TexSrt, 0, 0);
    mpModel->GetModelAnm()->Regist(RPGrpModelAnm::Anm_Clr, 0, 0);
    mpModel->SetDrawScene(mDrawScene);
}

void RPSportsMenuBgModel::initCamera() {
    nw4r::math::VEC3 camPos(0.0f, 0.0f, 65.0f);
    mpCamera->SetPosition(camPos);
    mEyeView.x = 0.0f;
    mEyeView.y = 0.0f;
    mEyeView.z = 0.0f;
    mBaseScale.x = 1.0f;
    mBaseScale.y = 1.0f;
    mBaseScale.z = 1.0f;

    mpModel->GetModelAnm()->Start(RPGrpModelAnm::Anm_Chr, 0);
    mpModel->GetModelAnm()->Start(RPGrpModelAnm::Anm_TexSrt, 0);
    mpModel->GetModelAnm()->Start(RPGrpModelAnm::Anm_Clr, 0);
    mpModel->GetModelAnm()->SetFrame(RPGrpModelAnm::Anm_Clr, (f32)0, 0.0f);
    mpModel->GetModelAnm()->SetUpdateRate(RPGrpModelAnm::Anm_Clr, 0, 0.0f);
}

void RPSportsMenuBgModel::calcView() {
    EGG::Matrix34f billboard;

    mpCamera->CalcMatrix();
    billboard.makeIdentity();

    billboard._03 = mEyeView.x;
    billboard._13 = mEyeView.y;
    billboard._23 = mEyeView.z;

#if defined(VERSION_RSPE01_00)
    nw4r::math::MTX34Copy(mpModel->GetMtxPtr(), &billboard);
#elif defined(VERSION_RSPE01_01)
    nw4r::g3d::ScnObj* scnObj = mpModel->GetModelEx()->getScnObj();
    if (scnObj) {
        scnObj->SetMtx(nw4r::g3d::ScnObj::MTX_LOCAL, &billboard);
    }
#endif
    mpModel->SetBaseScale(mBaseScale);
    mpModel->UpdateFrame();
    mpModel->Calc();
    mpModel->Entry();
}

#ifndef RP_SYSTEM_GAME_CONFIG_H
#define RP_SYSTEM_GAME_CONFIG_H
#include <Pack/types_pack.h>

#include <Pack/RPSingleton.h>
#include <Pack/RPSystem/RPSysTagParms.h>

//! @addtogroup rp_system
//! @{

/**
 * @brief Pack Project Game Config File (`gameConfig.ini`)
 *
 * @details Some of the listed people did not work (or were not
 * credited on Wii Sports, but on other Pack Project games. Some
 * names are verified with the Wii Fit config, which contains
 * commented kanji spellings.
 */
class RPSysGameConfig : public RPSysTagParameters {
    RP_SINGLETON_DECL_EX(RPSysGameConfig);

private:
    //! Scene loaded on boot
    RPSysStringTagParm mRootScene; // at 0x10
    //! TV mode (aspect ratio)
    RPSysStringTagParm mTVMode; // at 0x20
#if defined(VERSION_RSPE01_01)
    //! Game language
    RPSysStringTagParm mLanguage; // at 0x30
#endif

    //! Common print setting
    RPSysPrimTagParm<int> mRPPrint; // at 0x40
    //! System print setting
    RPSysPrimTagParm<int> mRPSysPrint; // at 0x50
#if defined(VERSION_RSPE01_01)
    //! Utility print setting
    RPSysPrimTagParm<int> mRPUtlPrint; // at 0x60
    //! Audio print setting
    RPSysPrimTagParm<int> mRPAudPrint; // at 0x70
#endif
    //! Sound print setting
    RPSysPrimTagParm<int> mRPSndPrint; // at 0x80
    //! User print setting
    RPSysPrimTagParm<int> mRPUserPrint; // at 0x90

#if defined(VERSION_RSPE01_01)
    //! Kazuya Sumaki print setting
    RPSysPrimTagParm<int> mRPSmkPrint; // at 0xA0
    //! Yuichiro Okamura(?) print setting
    RPSysPrimTagParm<int> mRPOkaPrint; // at 0xB0
    //! Unknown
    RPSysPrimTagParm<int> mRPOknPrint; // at 0xC0
    //! Shigehiro Kasamatsu print setting
    RPSysPrimTagParm<int> mRPKasPrint; // at 0xD0
    //! Kenji Matsutani print setting
    RPSysPrimTagParm<int> mRPMatPrint; // at 0xE0
    //! Yuji Sawatani print setting
    RPSysPrimTagParm<int> mRPSawPrint; // at 0xF0
    //! Masaro Sakakibara print setting
    RPSysPrimTagParm<int> mRPSakPrint; // at 0x100
    //! Kiyoshi Kohda print setting
    RPSysPrimTagParm<int> mRPKodPrint; // at 0x110
    //! Atsushi Sakaguchi print setting
    RPSysPrimTagParm<int> mRPGutPrint; // at 0x120
    //! Kouji Sakai print setting
    RPSysPrimTagParm<int> mRPSaiPrint; // at 0x130
    //! Nobuhiro Sumiyoshi print setting
    RPSysPrimTagParm<int> mRPSumPrint; // at 0x140
    //! Hiroshi Umemiya print setting
    RPSysPrimTagParm<int> mRPUmePrint; // at 0x150
#endif

    //! Game open setting
    RPSysPrimTagParm<int> mGameOpen; // at 0x160
};

//! @}

#endif

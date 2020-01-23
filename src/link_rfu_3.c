#include "global.h"
#include "decompress.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "malloc.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "constants/flags.h"

static EWRAM_DATA u8 gWirelessStatusIndicatorSpriteId = 0;

static const u16 gWirelessLinkIconPalette[] = INCBIN_U16("graphics/interface/wireless_link_icon.gbapal");

static const u32 gWirelessLinkIconPic[] = INCBIN_U32("graphics/interface/wireless_link_icon.4bpp.lz");

static const u8 sWireless_ASCIItoRSETable[] = {
    0xff, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x37,
    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
    0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    0x00, 0xab, 0xb5, 0xb6, 0xb1, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xb2, 0xf1, 0x00, 0xae, 0xad, 0xba,
    0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8,
    0xa9, 0xaa, 0x00, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
    0x00, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1,
    0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
    0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1,
    0xd2, 0xd3, 0xd4, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6,
    0x00, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb,
    0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3,
    0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb,
    0xec, 0xed, 0xee, 0x2d, 0x2f, 0x30, 0x31, 0x32,
    0x33, 0x34, 0x35, 0x36, 0x50, 0x00, 0x01, 0x02,
    0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12,
    0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a,
    0x1b, 0xad, 0xb3, 0xb4, 0x00, 0xaf, 0x7d, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xa0,
    0xae, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
    0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
    0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7e, 0xb0, 0xac,
    0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23,
    0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
    0x2c, 0x2e, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c,
    0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94
};

static const u8 sWireless_RSEtoASCIITable[] = {
    0x20, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c,
    0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
    0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c,
    0x9d, 0x9e, 0x9f, 0xa0, 0xe0, 0xe1, 0xe2, 0xe3,
    0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb,
    0xec, 0xed, 0xee, 0xef, 0xf0, 0x7b, 0xf1, 0x7c,
    0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x84, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
    0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
    0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
    0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xa6, 0xdd, 0xa7,
    0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xf2,
    0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa,
    0xfb, 0xfc, 0xfd, 0xfe, 0xff, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0xaf, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
    0x37, 0x38, 0x39, 0x21, 0xdf, 0xa1, 0xb0, 0xa5,
    0xde, 0x24, 0x2a, 0xa2, 0xa3, 0x22, 0x23, 0x20,
    0xa4, 0x20, 0x2f, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d,
    0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
    0x56, 0x57, 0x58, 0x59, 0x5a, 0x61, 0x62, 0x63,
    0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
    0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73,
    0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x20,
    0x20, 0x2b, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00
};

static const struct OamData sWirelessStatusIndicatorOamData =
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(16x16),
        .x = 0,
        .size = SPRITE_SIZE(16x16),
        .tileNum = 0,
        .priority = 0,
        .paletteNum = 0,
    };

static const union AnimCmd sWirelessStatusIndicatorAnim0[] = {
    // 3 bars
    ANIMCMD_FRAME( 4,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_FRAME(12,  5),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(12,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicatorAnim1[] = {
    // 2 bars
    ANIMCMD_FRAME( 4,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicatorAnim2[] = {
    // 1 bar
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicatorAnim3[] = {
    // searching
    ANIMCMD_FRAME( 4, 10),
    ANIMCMD_FRAME(20, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicatorAnim4[] = {
    // error
    ANIMCMD_FRAME(24, 10),
    ANIMCMD_FRAME( 4, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sWirelessStatusIndicatorAnims[] = {
    sWirelessStatusIndicatorAnim0,
    sWirelessStatusIndicatorAnim1,
    sWirelessStatusIndicatorAnim2,
    sWirelessStatusIndicatorAnim3,
    sWirelessStatusIndicatorAnim4
};

static const struct CompressedSpriteSheet sWirelessStatusIndicatorSpriteSheet = {
    gWirelessLinkIconPic, 0x0380, 0xD431
};

static const struct SpritePalette sWirelessStatusIndicatorSpritePalette = {
    gWirelessLinkIconPalette, 0xD432
};

static const struct SpriteTemplate sWirelessStatusIndicatorSpriteTemplate = {
    0xD431,
    0xD432,
    &sWirelessStatusIndicatorOamData,
    sWirelessStatusIndicatorAnims,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

void sub_80FC478(struct UnkRfuStruct_2_Sub_124 *ptr)
{
    s32 i;
    s32 j;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 70; j++)
        {
            ptr->unk_00[i][j] = 0;
        }
    }
    ptr->unk_8c1 = 0;
    ptr->unk_8c0 = 0;
    ptr->unk_8c2 = 0;
    ptr->unk_8c3 = 0;
}

void sub_80FC4D4(struct UnkRfuStruct_2_Sub_9e8 *ptr)
{
    s32 i;
    s32 j;

    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 14; j++)
        {
            ptr->unk_00[i][j] = 0;
        }
    }
    ptr->unk_231 = 0;
    ptr->unk_230 = 0;
    ptr->unk_232 = 0;
    ptr->unk_233 = 0;
}

static void sub_80FC530(struct UnkRfuStruct_Sub_Unused *ptr)
{
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 256; j++)
        {
            ptr->unk_00[i][j] = 0;
        }
    }
    ptr->unk_201 = 0;
    ptr->unk_200 = 0;
    ptr->unk_202 = 0;
    ptr->unk_203 = 0;
}

void sub_80FC588(struct UnkRfuStruct_2_Sub_124 *q1, u8 *q2)
{
    s32 i;
    u16 imeBak;
    u8 count;

    if (q1->unk_8c2 < 20)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        count = 0;
        for (i = 0; i < 70; i += 14)
        {
            if (q2[i] == 0 && q2[i + 1] == 0)
            {
                count++;
            }
        }
        if (count != 5)
        {
            for (i = 0; i < 70; i++)
            {
                q1->unk_00[q1->unk_8c0][i] = q2[i];
            }
            q1->unk_8c0++;
            q1->unk_8c0 %= 20;
            q1->unk_8c2++;
            for (i = 0; i < 70; i++)
            {
                q2[i] = 0;
            }
        }
        REG_IME = imeBak;
    }
    else
    {
        q1->unk_8c3 = 1;
    }
}

void sub_80FC63C(struct UnkRfuStruct_2_Sub_9e8 *q1, u8 *q2)
{
    s32 i;
    u16 imeBak;

    if (q1->unk_232 < 40)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        for (i = 0; i < 14; i++)
        {
            if (q2[i] != 0)
            {
                break;
            }
        }
        if (i != 14)
        {
            for (i = 0; i < 14; i++)
            {
                q1->unk_00[q1->unk_230][i] = q2[i];
            }
            q1->unk_230++;
            q1->unk_230 %= 40;
            q1->unk_232++;
            for (i = 0; i < 14; i++)
            {
                q2[i] = 0;
            }
        }
        REG_IME = imeBak;
    }
    else
    {
        q1->unk_233 = 1;
    }
}

bool8 sub_80FC6E8(struct UnkRfuStruct_2_Sub_124 *q1, u8 *q2)
{
    u16 imeBak;
    s32 i;

    imeBak = REG_IME;
    REG_IME = 0;
    if (q1->unk_8c0 == q1->unk_8c1 || q1->unk_8c3 != 0)
    {
        for (i = 0; i < 70; i++)
        {
            q2[i] = 0;
        }
        REG_IME = imeBak;
        return FALSE;
    }
    for (i = 0; i < 70; i++)
    {
        q2[i] = q1->unk_00[q1->unk_8c1][i];
    }
    q1->unk_8c1++;
    q1->unk_8c1 %= 20;
    q1->unk_8c2--;
    REG_IME = imeBak;
    return TRUE;
}

bool8 sub_80FC79C(struct UnkRfuStruct_2_Sub_9e8 *q1, u8 *q2)
{
    s32 i;
    u16 imeBak;

    if (q1->unk_230 == q1->unk_231 || q1->unk_233 != 0)
    {
        return FALSE;
    }
    imeBak = REG_IME;
    REG_IME = 0;
    for (i = 0; i < 14; i++)
    {
        q2[i] = q1->unk_00[q1->unk_231][i];
    }
    q1->unk_231++;
    q1->unk_231 %= 40;
    q1->unk_232--;
    REG_IME = imeBak;
    return TRUE;
}

void sub_80FC828(struct UnkRfuStruct_2_Sub_c1c *q1, const u8 *q2)
{
    s32 i;

    if (q2[1] == 0)
    {
        sub_80FC888(q1, NULL);
    }
    else
    {
        for (i = 0; i < 14; i++)
        {
            q1->unk_00[q1->unk_1c][i] = q2[i];
        }
        q1->unk_1c++;
        q1->unk_1c %= 2;
        if (q1->unk_1e < 2)
        {
            q1->unk_1e++;
        }
        else
        {
            q1->unk_1d = q1->unk_1c;
        }
    }
}

bool8 sub_80FC888(struct UnkRfuStruct_2_Sub_c1c *q1, u8 *q2)
{
    s32 i;

    if (q1->unk_1e == 0)
    {
        return FALSE;
    }
    if (q2 != NULL)
    {
        for (i = 0; i < 14; i++)
        {
            q2[i] = q1->unk_00[q1->unk_1d][i];
        }
    }
    q1->unk_1d++;
    q1->unk_1d %= 2;
    q1->unk_1e--;
    return TRUE;
}

static void sub_80FC8D8(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2)
{
    s32 i;

    if (q1->unk_202 < 2)
    {
        for (i = 0; i < 256; i++)
        {
            q1->unk_00[q1->unk_200][i] = q2[i];
        }
        q1->unk_200++;
        q1->unk_200 %= 2;
        q1->unk_202++;
    }
    else
    {
        q1->unk_203 = 1;
    }
}

static bool8 sub_80FC944(struct UnkRfuStruct_Sub_Unused *q1, u8 *q2)
{
    s32 i;

    if (q1->unk_200 == q1->unk_201 || q1->unk_203)
    {
        return FALSE;
    }
    for (i = 0; i < 256; i++)
    {
        q2[i] = q1->unk_00[q1->unk_201][i];
    }
    q1->unk_201++;
    q1->unk_201 %= 2;
    q1->unk_202--;
    return TRUE;
}

static void sub_80FC9B8(u8 *q1, u8 mode)
{
    s32 i;
    u8 rval;
    u16 r5 = 0;
    static u8 _3002018;

    switch (mode)
    {
        case 0:
            for (i = 0; i < 200; i++)
            {
                q1[i] = i + 1;
                r5 += i + 1;
            }
            *((u16 *)(q1 + i)) = r5;
            break;
        case 1:
            for (i = 0; i < 100; i++)
            {
                q1[i] = i + 1;
                r5 += i + 1;
            }
            *((u16 *)(q1 + 200)) = r5;
            break;
        case 2:
            for (i = 0; i < 200; i++)
            {
                rval = Random();
                q1[i] = rval;
                r5 += rval;
            }
            *((u16 *)(q1 + i)) = r5;
            break;
        case 3:
            for (i = 0; i < 200; i++)
            {
                q1[i] = i + 1 + _3002018;
                r5 += (i + 1 + _3002018) & 0xFF;
            }
            *((u16 *)(q1 + i)) = r5;
            _3002018++;
            break;
    }
}

static void PkmnStrToASCII(u8 *q1, const u8 *q2)
{
    s32 i;

    for (i = 0; q2[i] != EOS; i++)
    {
        q1[i] = sWireless_RSEtoASCIITable[q2[i]];
    }
    q1[i] = 0;
}

static void ASCIIToPkmnStr(u8 *q1, const u8 *q2)
{
    s32 i;

    for (i = 0; q2[i] != 0; i++)
    {
        q1[i] = sWireless_ASCIItoRSETable[q2[i]];
    }
    q1[i] = EOS;
}

#ifdef NONMATCHING
static u8 GetConnectedChildStrength(u8 maxFlags)
{
    u8 flagCount = 0;
    u8 flags = gRfuLinkStatus->connSlotFlag;
    u8 i;

    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        for (i = 0; i < 4; flags >>= 1, i++)
        {
            if (flags & 1)
            {
                if (maxFlags == flagCount + 1)
                    return gRfuLinkStatus->strength[i];
                flagCount++;
            }
        }
        return 0;
    }
    else
    {
        for (i = 0; i < 4; flags >>= 1, i++)
        {
            if (flags & 1)
                return gRfuLinkStatus->strength[i];
        }
        return 0;
    }
}
#else
NAKED
static u8 GetConnectedChildStrength(u8 maxFlags)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tlsls r0, 24\n"
                "\tlsrs r5, r0, 24\n"
                "\tmovs r6, 0\n"
                "\tldr r0, _080FCB04 @ =gRfuLinkStatus\n"
                "\tldr r4, [r0]\n"
                "\tldrb r2, [r4, 0x2]\n"
                "\tldrb r1, [r4]\n"
                "\tadds r7, r0, 0\n"
                "\tcmp r1, 0x1\n"
                "\tbne _080FCB32\n"
                "\tmovs r3, 0\n"
                "\tands r1, r2\n"
                "\tcmp r1, 0\n"
                "\tbeq _080FCB0E\n"
                "\tcmp r5, 0x1\n"
                "\tbne _080FCB08\n"
                "\tldrb r0, [r4, 0xA]\n"
                "\tb _080FCB4C\n"
                "\t.align 2, 0\n"
                "_080FCB04: .4byte gRfuLinkStatus\n"
                "_080FCB08:\n"
                "\tadds r0, r6, 0x1\n"
                "\tlsls r0, 24\n"
                "\tlsrs r6, r0, 24\n"
                "_080FCB0E:\n"
                "\tlsrs r2, 1\n"
                "\tadds r0, r3, 0x1\n"
                "\tlsls r0, 24\n"
                "\tlsrs r3, r0, 24\n"
                "\tcmp r3, 0x3\n"
                "\tbhi _080FCB4A\n"
                "\tmovs r0, 0x1\n"
                "\tands r0, r2\n"
                "\tcmp r0, 0\n"
                "\tbeq _080FCB0E\n"
                "\tadds r0, r6, 0x1\n"
                "\tcmp r5, r0\n"
                "\tbne _080FCB08\n"
                "_080FCB28:\n"
                "\tldr r0, [r7]\n"
                "\tadds r0, 0xA\n"
                "\tadds r0, r3\n"
                "\tldrb r0, [r0]\n"
                "\tb _080FCB4C\n"
                "_080FCB32:\n"
                "\tmovs r3, 0\n"
                "\tmovs r1, 0x1\n"
                "_080FCB36:\n"
                "\tadds r0, r2, 0\n"
                "\tands r0, r1\n"
                "\tcmp r0, 0\n"
                "\tbne _080FCB28\n"
                "\tlsrs r2, 1\n"
                "\tadds r0, r3, 0x1\n"
                "\tlsls r0, 24\n"
                "\tlsrs r3, r0, 24\n"
                "\tcmp r3, 0x3\n"
                "\tbls _080FCB36\n"
                "_080FCB4A:\n"
                "\tmovs r0, 0\n"
                "_080FCB4C:\n"
                "\tpop {r4-r7}\n"
                "\tpop {r1}\n"
                "\tbx r1");
}
#endif

void InitHostRFUtgtGname(struct GFtgtGname *data, u8 activity, bool32 r2, s32 r3)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        data->unk_00.playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];
    }
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        data->unk_04[i] = r3;
        r3 >>= 8;
    }
    data->playerGender = gSaveBlock2Ptr->playerGender;
    data->unk_0a_0 = activity;
    data->unk_0a_7 = r2;
    data->unk_00.unk_00_0 = GAME_LANGUAGE;
    data->unk_00.unk_01_2 = GAME_VERSION;
    data->unk_00.unk_00_4 = 0;
    data->unk_00.unk_00_5 = 0;
    data->unk_00.unk_00_6 = 0;
    data->unk_00.isChampion = FlagGet(FLAG_SYS_CAN_LINK_WITH_RS);
    data->unk_00.hasNationalDex = IsNationalPokedexEnabled();
    data->unk_00.gameClear = FlagGet(FLAG_SYS_GAME_CLEAR);
}

bool8 sub_80FCC3C(struct GFtgtGname *gname, u8 *uname, u8 idx)
{
    bool8 retVal;

    if (gUnknown_3005E10.unk_06 == 1)
    {
        retVal = TRUE;
        if (sub_80FA44C(gRfuLinkStatus->partner[idx].serialNo) && ((gRfuLinkStatus->getNameFlag >> idx) & 1))
        {
            memcpy(gname, &gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
            memcpy(uname, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        }
        else
        {
            memset(gname, 0, RFU_GAME_NAME_LENGTH);
            memset(uname, 0, RFU_USER_NAME_LENGTH);
        }
    }
    else
    {
        retVal = FALSE;
        if (sub_80FA44C(gRfuLinkStatus->partner[idx].serialNo))
        {
            memcpy(gname, &gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
            memcpy(uname, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        }
        else
        {
            memset(gname, 0, RFU_GAME_NAME_LENGTH);
            memset(uname, 0, RFU_USER_NAME_LENGTH);
        }
    }
    return retVal;
}

bool8 sub_80FCCF4(struct GFtgtGname *gname, u8 *uname, u8 idx)
{
    bool8 retVal = FALSE;
    if (gRfuLinkStatus->partner[idx].serialNo == 0x7F7D)
    {
        memcpy(gname, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
        memcpy(uname, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        retVal = TRUE;
    }
    else
    {
        memset(gname, 0, RFU_GAME_NAME_LENGTH);
        memset(uname, 0, RFU_USER_NAME_LENGTH);
    }
    return retVal;
}

void LinkRfu3_SetGnameUnameFromStaticBuffers(struct GFtgtGname *gname, u8 *uname)
{
    memcpy(gname, &gHostRFUtgtGnameBuffer, RFU_GAME_NAME_LENGTH);
    memcpy(uname, gHostRFUtgtUnameBuffer, RFU_USER_NAME_LENGTH);
}

void CreateWirelessStatusIndicatorSprite(u8 x, u8 y)
{
    u8 sprId;

    if (x == 0 && y == 0)
    {
        x = 0xE7;
        y = 0x08;
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        sprId = CreateSprite(&sWirelessStatusIndicatorSpriteTemplate, x, y, 0);
        gSprites[sprId].data[7] = 0x1234;
        gSprites[sprId].data[6] = GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag);
        gSprites[sprId].invisible = TRUE;
        gWirelessStatusIndicatorSpriteId = sprId;
    }
    else
    {
        gWirelessStatusIndicatorSpriteId = CreateSprite(&sWirelessStatusIndicatorSpriteTemplate, x, y, 0);
        gSprites[gWirelessStatusIndicatorSpriteId].data[7] = 0x1234;
        gSprites[gWirelessStatusIndicatorSpriteId].data[6] = GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag);
        gSprites[gWirelessStatusIndicatorSpriteId].invisible = TRUE;
    }
}

void DestroyWirelessStatusIndicatorSprite(void)
{
    if (gSprites[gWirelessStatusIndicatorSpriteId].data[7] == 0x1234)
    {
        gSprites[gWirelessStatusIndicatorSpriteId].data[7] = 0;
        DestroySprite(&gSprites[gWirelessStatusIndicatorSpriteId]);
        gMain.oamBuffer[125] = gDummyOamData;
        CpuCopy16(&gDummyOamData, (struct OamData *)OAM + 125, sizeof(struct OamData));
    }
}

void LoadWirelessStatusIndicatorSpriteGfx(void)
{
    if (GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheet(&sWirelessStatusIndicatorSpriteSheet);
    }
    LoadSpritePalette(&sWirelessStatusIndicatorSpritePalette);
    gWirelessStatusIndicatorSpriteId = 0xFF;
}

static u8 GetParentSignalStrength(void)
{
    u8 i;
    u8 flags = gRfuLinkStatus->connSlotFlag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (flags & 1)
        {
            return gRfuLinkStatus->strength[i];
        }
        flags >>= 1;
    }
    return 0;
}

static void SetAndRestartWirelessStatusIndicatorAnim(struct Sprite *sprite, s32 signalStrengthAnimNum)
{
    if (sprite->data[2] != signalStrengthAnimNum)
    {
        sprite->data[2] = signalStrengthAnimNum;
        sprite->data[3] = 0;
        sprite->data[4] = 0;
    }
}

void UpdateWirelessStatusIndicatorSprite(void)
{
    if (gWirelessStatusIndicatorSpriteId != 0xFF && gSprites[gWirelessStatusIndicatorSpriteId].data[7] == 0x1234)
    {
        struct Sprite *sprite = &gSprites[gWirelessStatusIndicatorSpriteId];
        u8 signalStrength = RFU_LINK_ICON_LEVEL4_MAX;
        u8 i = 0;
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
        {
            for (i = 0; i < GetLinkPlayerCount() - 1; i++)
            {
                if (signalStrength >= GetConnectedChildStrength(i + 1))
                {
                    signalStrength = GetConnectedChildStrength(i + 1);
                }
            }
        }
        else
        {
            signalStrength = GetParentSignalStrength();
        }
        if (sub_80FC1B0() == TRUE)
        {
            sprite->data[0] = 4;
        }
        else if (signalStrength <= RFU_LINK_ICON_LEVEL1_MAX)
        {
            sprite->data[0] = 3;
        }
        else if (signalStrength >= RFU_LINK_ICON_LEVEL2_MIN && signalStrength <= RFU_LINK_ICON_LEVEL2_MAX)
        {
            sprite->data[0] = 2;
        }
        else if (signalStrength >= RFU_LINK_ICON_LEVEL3_MIN && signalStrength <= RFU_LINK_ICON_LEVEL3_MAX)
        {
            sprite->data[0] = 1;
        }
        else if (signalStrength >= RFU_LINK_ICON_LEVEL4_MIN)
        {
            sprite->data[0] = 0;
        }
        if (sprite->data[0] != sprite->data[1])
        {
            SetAndRestartWirelessStatusIndicatorAnim(sprite, sprite->data[0]);
            sprite->data[1] = sprite->data[0];
        }
        if (sprite->anims[sprite->data[2]][sprite->data[4]].frame.duration < sprite->data[3])
        {
            sprite->data[4]++;
            sprite->data[3] = 0;
            if (sprite->anims[sprite->data[2]][sprite->data[4]].type == -2)
            {
                sprite->data[4] = 0;
            }
        }
        else
        {
            sprite->data[3]++;
        }
        gMain.oamBuffer[125] = sWirelessStatusIndicatorOamData;
        gMain.oamBuffer[125].x = sprite->pos1.x + sprite->centerToCornerVecX;
        gMain.oamBuffer[125].y = sprite->pos1.y + sprite->centerToCornerVecY;
        gMain.oamBuffer[125].paletteNum = sprite->oam.paletteNum;
        gMain.oamBuffer[125].tileNum = sprite->data[6] + sprite->anims[sprite->data[2]][sprite->data[4]].frame.imageValue;
        CpuCopy16(gMain.oamBuffer + 125, (struct OamData *)OAM + 125, sizeof(struct OamData));
        if (sub_80FB9F4() == 1)
        {
            DestroyWirelessStatusIndicatorSprite();
        }
    }
}

static void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name)
{
    int i;
    dest->trainerId = trainerId;
    for (i = 0; i < 7; i++)
    {
        if (name[i] == EOS)
            break;
        dest->trainerName[i] = name[i];
    }
    dest->trainerName[i] = EOS;
}

static void ZeroName(u8 *name)
{
    s32 i;

    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
    {
        *name++ = 0;
    }
}

static bool32 NameIsEmpty(const u8 *name)
{
    s32 i;

    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
    {
        if (*name++ != 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

// Save the currently connected players into the trainer records, shifting all previous records down.
void RecordMixTrainerNames(void)
{
    if (gWirelessCommType != 0)
    {
        s32 i;
        s32 j;
        s32 nextSpace;
        s32 connectedTrainerRecordIndices[5];
        struct TrainerNameRecord *newRecords = AllocZeroed(20 * sizeof(struct TrainerNameRecord));

        // Check if we already have a record saved for connected trainers.
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            connectedTrainerRecordIndices[i] = -1;
            for (j = 0; j < 20; j++)
            {
                if ((u16)gLinkPlayers[i].trainerId ==  gSaveBlock1Ptr->trainerNameRecords[j].trainerId && StringCompare(gLinkPlayers[i].name, gSaveBlock1Ptr->trainerNameRecords[j].trainerName) == 0)
                {
                    connectedTrainerRecordIndices[i] = j;
                }
            }
        }

        // Save the connected trainers first, at the top of the list.
        nextSpace = 0;
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (i != GetMultiplayerId() && gLinkPlayers[i].language != LANGUAGE_JAPANESE)
            {
                CopyTrainerRecord(&newRecords[nextSpace], (u16)gLinkPlayers[i].trainerId, gLinkPlayers[i].name);

                // If we already had a record for this trainer, wipe it so that the next step doesn't duplicate it.
                if (connectedTrainerRecordIndices[i] >= 0)
                {
                    ZeroName(gSaveBlock1Ptr->trainerNameRecords[connectedTrainerRecordIndices[i]].trainerName);
                }
                nextSpace++;
            }
        }

        // Copy all non-empty records to the new list, in the order they appear on the old list. If the list is full,
        // the last (oldest) records will be dropped.
        for (i = 0; i < 20; i++)
        {
            if (!NameIsEmpty(gSaveBlock1Ptr->trainerNameRecords[i].trainerName))
            {
                CopyTrainerRecord(&newRecords[nextSpace], gSaveBlock1Ptr->trainerNameRecords[i].trainerId, gSaveBlock1Ptr->trainerNameRecords[i].trainerName);
                if (++nextSpace >= 20)
                {
                    break;
                }
            }
        }

        // Finalize the new list, and clean up.
        memcpy(gSaveBlock1Ptr->trainerNameRecords, newRecords, 20 * sizeof(struct TrainerNameRecord));
        Free(newRecords);
    }
}

bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name)
{
    s32 i;

    for (i = 0; i < 20; i++)
    {
        if (StringCompareN(gSaveBlock1Ptr->trainerNameRecords[i].trainerName, name, 7) == 0 && gSaveBlock1Ptr->trainerNameRecords[i].trainerId == id)
        {
            return TRUE;
        }
        if (NameIsEmpty(gSaveBlock1Ptr->trainerNameRecords[i].trainerName))
        {
            return FALSE;
        }
    }
    return FALSE;
}
/* dhparam.c: initial DH parameters for stunnel */
#include "prototypes.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
DH *get_dh2048(void) {
    static unsigned char dhp_2048[] = {
        0xc3, 0x83, 0x3f, 0x9e, 0x2b, 0x36, 0x2f, 0x5c, 0xad, 0x53, 0x24, 0x81,
        0x35, 0x33, 0xcb, 0x2a, 0x33, 0x5f, 0x29, 0x6c, 0xd5, 0xa4, 0xef, 0x65,
        0x46, 0xff, 0x0d, 0x29, 0xb0, 0x62, 0xb4, 0x4b, 0xf6, 0x09, 0xbf, 0xde,
        0x5f, 0xbc, 0x18, 0x28, 0x89, 0x5c, 0xe4, 0xb3, 0x70, 0xcb, 0x26, 0x99,
        0xec, 0x7e, 0x8b, 0xcc, 0xc4, 0x2f, 0xa8, 0xe0, 0x91, 0x79, 0xb9, 0x30,
        0x41, 0xb1, 0xe8, 0x11, 0xc3, 0xb2, 0x63, 0x58, 0xe0, 0x01, 0x7d, 0xc4,
        0xb7, 0x23, 0x0d, 0x26, 0xdb, 0xbe, 0x02, 0x6e, 0xfb, 0x87, 0xc6, 0xe6,
        0x05, 0x18, 0x08, 0xb0, 0xd7, 0xc1, 0x0f, 0xed, 0x96, 0x38, 0x05, 0x9f,
        0x9c, 0x22, 0x0e, 0x0f, 0xe2, 0x44, 0x04, 0x75, 0xb4, 0x97, 0xbe, 0x73,
        0x98, 0xbd, 0x1a, 0xb0, 0x0f, 0xd5, 0xe3, 0xd8, 0xc3, 0x5d, 0x44, 0xee,
        0x53, 0x83, 0x7e, 0xcb, 0x88, 0xee, 0xd7, 0xa5, 0xdc, 0xba, 0x65, 0x32,
        0x61, 0x55, 0x98, 0x8e, 0xc7, 0x56, 0xb5, 0x4a, 0x8a, 0xce, 0xce, 0x00,
        0x30, 0x9f, 0xa4, 0x8e, 0xa4, 0xdc, 0x31, 0xf4, 0x91, 0x4a, 0xeb, 0x0b,
        0x5e, 0xf1, 0xcc, 0x11, 0x4b, 0x41, 0x0e, 0xf9, 0x7e, 0x14, 0xe0, 0xf0,
        0xc8, 0xd8, 0x12, 0xae, 0x1d, 0x82, 0xbd, 0x97, 0xc9, 0xdc, 0x56, 0x29,
        0x5d, 0x58, 0x23, 0xe0, 0xfa, 0x8c, 0xaf, 0x34, 0x12, 0x31, 0xc7, 0x73,
        0x6b, 0x59, 0x6f, 0xb0, 0x56, 0x92, 0x01, 0xb2, 0x6f, 0x1c, 0xcb, 0x9c,
        0xb4, 0x6f, 0x65, 0x1b, 0x7f, 0x6e, 0x08, 0x17, 0x6f, 0xb7, 0xfc, 0xcc,
        0x9f, 0x62, 0xd2, 0xbd, 0x65, 0x66, 0x56, 0x39, 0x71, 0x42, 0xc4, 0x0d,
        0x60, 0xf6, 0xc6, 0x26, 0xe1, 0xb3, 0xb4, 0x40, 0x28, 0x48, 0xd5, 0xa9,
        0xe0, 0xe3, 0x61, 0xb3, 0x40, 0x0b, 0x22, 0x89, 0x23, 0x23, 0xe8, 0x2a,
        0x9d, 0xdf, 0x9d, 0xdf
    };
    static unsigned char dhg_2048[] = {
        0x02
    };
    DH *dh = DH_new();
    BIGNUM *p, *g;

    if (dh == NULL)
        return NULL;
    p = BN_bin2bn(dhp_2048, sizeof(dhp_2048), NULL);
    g = BN_bin2bn(dhg_2048, sizeof(dhg_2048), NULL);
    if (p == NULL || g == NULL
            || !DH_set0_pqg(dh, p, NULL, g)) {
        DH_free(dh);
        BN_free(p);
        BN_free(g);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */
/* built for stunnel 5.74 */

/* dhparam.c: initial DH parameters for stunnel */
#include "prototypes.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
DH *get_dh2048(void) {
    static unsigned char dhp_2048[] = {
        0x8c, 0x25, 0x02, 0xef, 0xa7, 0x5b, 0x04, 0x52, 0xd1, 0x12, 0x9e, 0x19,
        0xbc, 0xac, 0x51, 0x7c, 0xd5, 0xc9, 0x80, 0x45, 0xaa, 0x77, 0x8c, 0x63,
        0x0f, 0xd0, 0x5b, 0x56, 0x60, 0x72, 0x81, 0x73, 0x7e, 0xd5, 0x63, 0x63,
        0xb9, 0x24, 0x89, 0xc2, 0xa4, 0x91, 0x7a, 0xab, 0x28, 0x09, 0x2a, 0x43,
        0x72, 0x92, 0x3a, 0xcc, 0xfb, 0x03, 0xfa, 0x14, 0x09, 0x97, 0xe5, 0x45,
        0x8b, 0xcb, 0x14, 0x48, 0xea, 0x5b, 0x9b, 0xa2, 0x5c, 0x0e, 0x48, 0x9b,
        0xc5, 0xac, 0x88, 0x4a, 0x0a, 0x1d, 0x2e, 0x0e, 0x56, 0x1b, 0xc5, 0xc0,
        0x6e, 0x30, 0x50, 0xbc, 0x2a, 0xb8, 0x10, 0x9b, 0xb4, 0xd2, 0xe1, 0x55,
        0xb8, 0x84, 0x19, 0xbc, 0x96, 0xd7, 0x8f, 0xb6, 0x2e, 0xc0, 0xaa, 0x13,
        0xff, 0x1b, 0x4d, 0x00, 0x15, 0x9b, 0xab, 0xb8, 0xd6, 0x76, 0x85, 0x69,
        0x7b, 0x70, 0xcd, 0xdc, 0x9e, 0xbb, 0xc3, 0x65, 0xe9, 0xe2, 0xef, 0x07,
        0xb8, 0x54, 0xee, 0x88, 0x02, 0xf9, 0xaa, 0x74, 0xb3, 0xc8, 0x64, 0x67,
        0xac, 0x60, 0xed, 0x70, 0x99, 0x88, 0xf5, 0x84, 0xa1, 0x9f, 0xe3, 0xff,
        0x45, 0x91, 0xbe, 0x63, 0xf3, 0xca, 0x6e, 0x67, 0x26, 0x84, 0xd3, 0x01,
        0xce, 0x5f, 0xa2, 0xad, 0x1d, 0xa7, 0x1e, 0xc9, 0x34, 0x80, 0x26, 0x76,
        0x2b, 0x3c, 0xc6, 0xd3, 0x92, 0x81, 0x52, 0x7c, 0xd3, 0x56, 0x33, 0x64,
        0x0a, 0x04, 0x3f, 0xe8, 0xb3, 0x2e, 0x11, 0x04, 0x9b, 0x47, 0x5e, 0x7b,
        0xfa, 0x65, 0x22, 0x6f, 0xc9, 0x93, 0x44, 0x1c, 0xc4, 0x96, 0x13, 0x7f,
        0xe1, 0x74, 0xb4, 0x25, 0xbf, 0x79, 0x13, 0x72, 0x0d, 0x7a, 0x70, 0x40,
        0x2e, 0x28, 0x85, 0x90, 0x06, 0xde, 0x47, 0x1c, 0x83, 0xf4, 0x8b, 0x28,
        0xc8, 0x1b, 0xd9, 0x0e, 0x83, 0x70, 0x51, 0x23, 0xa1, 0x56, 0x69, 0xbd,
        0x65, 0xfa, 0xc2, 0xcf
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
/* built for stunnel 5.73 */

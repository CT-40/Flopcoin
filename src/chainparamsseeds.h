#ifndef BITCOIN_CHAINPARAMSSEEDS_H
#define BITCOIN_CHAINPARAMSSEEDS_H

/**
 * List of fixed seed nodes for Flopcoin
 *
 * Each line contains a 16-byte IPv6 address and a port.
 * IPv4 addresses are wrapped inside an IPv6 address accordingly.
 */

static SeedSpec6 pnSeed6_main[] = {
    // 216.45.61.204:32552
    {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
      0x00,0x00,0xff,0xff,0xd8,0x2d,0x3d,0xcc}, 32552},
};

static SeedSpec6 pnSeed6_test[] = {
    // Add testnet seeds here if needed
};

#endif // BITCOIN_CHAINPARAMSSEEDS_H

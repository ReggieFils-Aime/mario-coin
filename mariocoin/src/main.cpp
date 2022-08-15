// Copyright (c) 2011-2013 MarioCoin Developers
// Distributed under the MIT software license, see COPYING.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "version.h"

int64 GetBlockValue(int nHeight, int64 nFees)
{
    int64 nSubsidy = 50 * COIN;

    // subsidy is cut in half every 840000 blocks
    nSubsidy >>= (nHeight / SUBSIDY_HALVING);

    return nSubsidy + nFees;
}

bool MoneyRange(int64 nValue)
{
    return (nValue >= 0 && nValue <= MAX_MONEY);
}

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-version") == 0)
        {
            printf("MarioCoin version %d.%d.%d-beta\n",
                   VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION);
            return 0;
        }
        if (strcmp(argv[i], "-?") == 0)
        {
            printf("Usage: mariocoind [options]\n");
            printf("  -?          this help message\n");
            printf("  -version    print version\n");
            printf("  -daemon     run in the background\n");
            printf("  -gen        generate coins\n");
            printf("  -testnet    use the test network\n");
            return 0;
        }
    }

    printf("MarioCoin server starting\n");
    printf("port %d, rpcport %d\n", DEFAULT_PORT, DEFAULT_RPC_PORT);
    printf("block reward %lld MRC\n", (long long)(GetBlockValue(0, 0) / COIN));

    return 0;
}

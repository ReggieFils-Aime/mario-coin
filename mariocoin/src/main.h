// Copyright (c) 2011-2013 MarioCoin Developers
// Distributed under the MIT software license, see COPYING.
#ifndef MARIOCOIN_MAIN_H
#define MARIOCOIN_MAIN_H

typedef long long int64;

static const int64 COIN = 100000000;
static const int64 CENT = 1000000;

static const int TARGET_SPACING   = 90;
static const int RETARGET_BLOCKS  = 240;
static const int SUBSIDY_HALVING  = 840000;
static const int COINBASE_MATURITY = 60;

static const int DEFAULT_PORT     = 19484;
static const int DEFAULT_RPC_PORT = 19485;

static const int64 MAX_MONEY = 84000000 * COIN;

int64 GetBlockValue(int nHeight, int64 nFees);
bool MoneyRange(int64 nValue);

#endif

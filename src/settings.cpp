/**
 * Copyright (c) 2011-2022 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/system/settings.hpp>

#include <bitcoin/system/chain/chain.hpp>
#include <bitcoin/system/data/data.hpp>
#include <bitcoin/system/define.hpp>
#include <bitcoin/system/math/math.hpp>

namespace libbitcoin {
namespace system {

// Common default values (no settings context).
settings::settings() NOEXCEPT
  : retargeting_factor(4),
    retargeting_interval_seconds(2 * 7 * 24 * 60 * 60),
    block_spacing_seconds(10 * 60),
    timestamp_limit_seconds(2 * 60 * 60),
    proof_of_work_limit(0x1d00ffff),
    initial_subsidy_bitcoin(50),
    subsidy_interval_blocks(210000),
    genesis_block{},
    first_version(1),
    bip34_version(2),
    bip66_version(3),
    bip65_version(4),
    bip9_version_bit0(1 << 0),
    bip9_version_bit1(1 << 1),
    bip9_version_base(0x20000000)
{
}

settings::settings(chain::selection context) NOEXCEPT
  : settings()
{
    switch (context)
    {
        case chain::selection::mainnet:
        {
            genesis_block = chain::block(
            {
                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x3b, 0xa3, 0xed, 0xfd,
                0x7a, 0x7b, 0x12, 0xb2, 0x7a, 0xc7, 0x2c, 0x3e,
                0x67, 0x76, 0x8f, 0x61, 0x7f, 0xc8, 0x1b, 0xc3,
                0x88, 0x8a, 0x51, 0x32, 0x3a, 0x9f, 0xb8, 0xaa,
                0x4b, 0x1e, 0x5e, 0x4a, 0x29, 0xab, 0x5f, 0x49,
                0xff, 0xff, 0x00, 0x1d, 0x1d, 0xac, 0x2b, 0x7c,
                0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
                0xff, 0xff, 0x4d, 0x04, 0xff, 0xff, 0x00, 0x1d,
                0x01, 0x04, 0x45, 0x54, 0x68, 0x65, 0x20, 0x54,
                0x69, 0x6d, 0x65, 0x73, 0x20, 0x30, 0x33, 0x2f,
                0x4a, 0x61, 0x6e, 0x2f, 0x32, 0x30, 0x30, 0x39,
                0x20, 0x43, 0x68, 0x61, 0x6e, 0x63, 0x65, 0x6c,
                0x6c, 0x6f, 0x72, 0x20, 0x6f, 0x6e, 0x20, 0x62,
                0x72, 0x69, 0x6e, 0x6b, 0x20, 0x6f, 0x66, 0x20,
                0x73, 0x65, 0x63, 0x6f, 0x6e, 0x64, 0x20, 0x62,
                0x61, 0x69, 0x6c, 0x6f, 0x75, 0x74, 0x20, 0x66,
                0x6f, 0x72, 0x20, 0x62, 0x61, 0x6e, 0x6b, 0x73,
                0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xf2, 0x05,
                0x2a, 0x01, 0x00, 0x00, 0x00, 0x43, 0x41, 0x04,
                0x67, 0x8a, 0xfd, 0xb0, 0xfe, 0x55, 0x48, 0x27,
                0x19, 0x67, 0xf1, 0xa6, 0x71, 0x30, 0xb7, 0x10,
                0x5c, 0xd6, 0xa8, 0x28, 0xe0, 0x39, 0x09, 0xa6,
                0x79, 0x62, 0xe0, 0xea, 0x1f, 0x61, 0xde, 0xb6,
                0x49, 0xf6, 0xbc, 0x3f, 0x4c, 0xef, 0x38, 0xc4,
                0xf3, 0x55, 0x04, 0xe5, 0x1e, 0xc1, 0x12, 0xde,
                0x5c, 0x38, 0x4d, 0xf7, 0xba, 0x0b, 0x8d, 0x57,
                0x8a, 0x4c, 0x70, 0x2b, 0x6b, 0xf1, 0x1d, 0x5f,
                0xac, 0x00, 0x00, 0x00, 0x00
            }, false);
            activation_threshold = 750;
            enforcement_threshold = 950;
            activation_sample = 1000;

            bip65_freeze = 388381;
            bip66_freeze = 363725;
            bip34_freeze = 227931;
            bip16_activation_time = 0x4f779a80;
            bip34_active_checkpoint = chain::checkpoint(
                "000000000000024b89b42a942fe0d9fea3bb44ab7bd1b19115dd6a759c0808b8",
                bip34_freeze);
            bip9_bit0_active_checkpoint = chain::checkpoint(
                "000000000000000004a1b34462cb8aeebd5799177f7a29cf28f2d1961716b5b5",
                419328);
            bip9_bit1_active_checkpoint = chain::checkpoint(
                "0000000000000000001c8018d9cb3b742ef25114f27563e3fc4a1902167f9893",
                481824);

            break;
        }

        case chain::selection::testnet:
        {
            genesis_block = chain::block(
            {
                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x3b, 0xa3, 0xed, 0xfd,
                0x7a, 0x7b, 0x12, 0xb2, 0x7a, 0xc7, 0x2c, 0x3e,
                0x67, 0x76, 0x8f, 0x61, 0x7f, 0xc8, 0x1b, 0xc3,
                0x88, 0x8a, 0x51, 0x32, 0x3a, 0x9f, 0xb8, 0xaa,
                0x4b, 0x1e, 0x5e, 0x4a, 0xda, 0xe5, 0x49, 0x4d,
                0xff, 0xff, 0x00, 0x1d, 0x1a, 0xa4, 0xae, 0x18,
                0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
                0xff, 0xff, 0x4d, 0x04, 0xff, 0xff, 0x00, 0x1d,
                0x01, 0x04, 0x45, 0x54, 0x68, 0x65, 0x20, 0x54,
                0x69, 0x6d, 0x65, 0x73, 0x20, 0x30, 0x33, 0x2f,
                0x4a, 0x61, 0x6e, 0x2f, 0x32, 0x30, 0x30, 0x39,
                0x20, 0x43, 0x68, 0x61, 0x6e, 0x63, 0x65, 0x6c,
                0x6c, 0x6f, 0x72, 0x20, 0x6f, 0x6e, 0x20, 0x62,
                0x72, 0x69, 0x6e, 0x6b, 0x20, 0x6f, 0x66, 0x20,
                0x73, 0x65, 0x63, 0x6f, 0x6e, 0x64, 0x20, 0x62,
                0x61, 0x69, 0x6c, 0x6f, 0x75, 0x74, 0x20, 0x66,
                0x6f, 0x72, 0x20, 0x62, 0x61, 0x6e, 0x6b, 0x73,
                0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xf2, 0x05,
                0x2a, 0x01, 0x00, 0x00, 0x00, 0x43, 0x41, 0x04,
                0x67, 0x8a, 0xfd, 0xb0, 0xfe, 0x55, 0x48, 0x27,
                0x19, 0x67, 0xf1, 0xa6, 0x71, 0x30, 0xb7, 0x10,
                0x5c, 0xd6, 0xa8, 0x28, 0xe0, 0x39, 0x09, 0xa6,
                0x79, 0x62, 0xe0, 0xea, 0x1f, 0x61, 0xde, 0xb6,
                0x49, 0xf6, 0xbc, 0x3f, 0x4c, 0xef, 0x38, 0xc4,
                0xf3, 0x55, 0x04, 0xe5, 0x1e, 0xc1, 0x12, 0xde,
                0x5c, 0x38, 0x4d, 0xf7, 0xba, 0x0b, 0x8d, 0x57,
                0x8a, 0x4c, 0x70, 0x2b, 0x6b, 0xf1, 0x1d, 0x5f,
                0xac, 0x00, 0x00, 0x00, 0x00
            }, false);
            activation_threshold = 51;
            enforcement_threshold = 75;
            activation_sample = 100;

            bip65_freeze = 581885;
            bip66_freeze = 330776;
            bip34_freeze = 21111;
            bip16_activation_time = 0x4f3af580;
            bip34_active_checkpoint = chain::checkpoint(
                "0000000023b3a96d3484e5abb3755c413e7d41500f8e2a5c3f0dd01299cd8ef8",
                bip34_freeze);
            bip9_bit0_active_checkpoint = chain::checkpoint(
                "00000000025e930139bac5c6c31a403776da130831ab85be56578f3fa75369bb",
                770112);
            bip9_bit1_active_checkpoint = chain::checkpoint(
                "00000000002b980fcd729daaa248fd9316a5200e9b367f4ff2c42453e84201ca",
                834624);

            break;
        }

        case chain::selection::regtest:
        {
            proof_of_work_limit = 0x207fffff;
            subsidy_interval_blocks = 150;
            genesis_block = chain::block(
            {
                0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x3b, 0xa3, 0xed, 0xfd,
                0x7a, 0x7b, 0x12, 0xb2, 0x7a, 0xc7, 0x2c, 0x3e,
                0x67, 0x76, 0x8f, 0x61, 0x7f, 0xc8, 0x1b, 0xc3,
                0x88, 0x8a, 0x51, 0x32, 0x3a, 0x9f, 0xb8, 0xaa,
                0x4b, 0x1e, 0x5e, 0x4a, 0xda, 0xe5, 0x49, 0x4d,
                0xff, 0xff, 0x7f, 0x20, 0x02, 0x00, 0x00, 0x00,
                0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff,
                0xff, 0xff, 0x4d, 0x04, 0xff, 0xff, 0x00, 0x1d,
                0x01, 0x04, 0x45, 0x54, 0x68, 0x65, 0x20, 0x54,
                0x69, 0x6d, 0x65, 0x73, 0x20, 0x30, 0x33, 0x2f,
                0x4a, 0x61, 0x6e, 0x2f, 0x32, 0x30, 0x30, 0x39,
                0x20, 0x43, 0x68, 0x61, 0x6e, 0x63, 0x65, 0x6c,
                0x6c, 0x6f, 0x72, 0x20, 0x6f, 0x6e, 0x20, 0x62,
                0x72, 0x69, 0x6e, 0x6b, 0x20, 0x6f, 0x66, 0x20,
                0x73, 0x65, 0x63, 0x6f, 0x6e, 0x64, 0x20, 0x62,
                0x61, 0x69, 0x6c, 0x6f, 0x75, 0x74, 0x20, 0x66,
                0x6f, 0x72, 0x20, 0x62, 0x61, 0x6e, 0x6b, 0x73,
                0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xf2, 0x05,
                0x2a, 0x01, 0x00, 0x00, 0x00, 0x43, 0x41, 0x04,
                0x67, 0x8a, 0xfd, 0xb0, 0xfe, 0x55, 0x48, 0x27,
                0x19, 0x67, 0xf1, 0xa6, 0x71, 0x30, 0xb7, 0x10,
                0x5c, 0xd6, 0xa8, 0x28, 0xe0, 0x39, 0x09, 0xa6,
                0x79, 0x62, 0xe0, 0xea, 0x1f, 0x61, 0xde, 0xb6,
                0x49, 0xf6, 0xbc, 0x3f, 0x4c, 0xef, 0x38, 0xc4,
                0xf3, 0x55, 0x04, 0xe5, 0x1e, 0xc1, 0x12, 0xde,
                0x5c, 0x38, 0x4d, 0xf7, 0xba, 0x0b, 0x8d, 0x57,
                0x8a, 0x4c, 0x70, 0x2b, 0x6b, 0xf1, 0x1d, 0x5f,
                0xac, 0x00, 0x00, 0x00, 0x00
            }, false);

            bip65_freeze = 1351;
            bip66_freeze = 1251;
            bip34_freeze = 0;
            bip16_activation_time = 0x4f3af580;

            chain::checkpoint genesis_checkpoint(genesis_block.hash(), zero);

            // bip90 assumes a historical bip34 activation block, use genesis.
            bip34_active_checkpoint = genesis_checkpoint;

            // This is fixed and closed, so assume genesis activation.
            bip9_bit0_active_checkpoint = genesis_checkpoint;
            bip9_bit1_active_checkpoint = genesis_checkpoint;

            break;
        }

        default:
        case chain::selection::none:
        {
        }
    }
}

// Computed properties.
// TODO: optimize to prevent recomputation.

// The exact maximum amount of money (as of bip42).
//*****************************************************************************
// CONSENSUS: This assumes bip42 as otherwise money supply is unbounded.
//*****************************************************************************
//*****************************************************************************
// CONSENSUS: The satoshi client uses a "sanity check" value that is
// effectively based on a round but incorrect value of recursive_money,
// which is higher than this true value. Despite comments to the contrary
// in the satoshi code, no value could be consensus critical unless it was
// *less* than the true value. This is non a consensus-critical method, as the
// consensus limit on money is stricly a function of subsidy recursion and
// overspend constraints.
//*****************************************************************************
uint64_t settings::max_money() const NOEXCEPT
{
    std::function<uint64_t(uint64_t)> total = [&](uint64_t subsidy) NOEXCEPT
    {
        // Guarded by parameterization (config).
        return is_zero(subsidy) ? 0 : safe_add(subsidy, total(subsidy >> 1));
    };

    // Guarded by parameterization (config).
    return safe_multiply(total(initial_subsidy()), subsidy_interval_blocks);
}

// Used to initialize initial subsidy setting.
uint64_t settings::bitcoin_to_satoshi(uint64_t value) const NOEXCEPT
{
    // Guarded by parameterization (config).
    return safe_multiply(value, chain::satoshi_per_bitcoin);
}

// The initial block subsidy in satoshis.
uint64_t settings::initial_subsidy() const NOEXCEPT
{
    return bitcoin_to_satoshi(initial_subsidy_bitcoin);
}

// The lower bound for the retargeting timespan.
uint32_t settings::minimum_timespan() const NOEXCEPT
{
    return chain::chain_state::minimum_timespan(retargeting_interval_seconds,
        retargeting_factor);
}

// The upper bound for the retargeting timespan.
uint32_t settings::maximum_timespan() const NOEXCEPT
{
    return chain::chain_state::maximum_timespan(retargeting_interval_seconds,
        retargeting_factor);
}

// The target number of blocks for 2 weeks of work (2016 blocks).
size_t settings::retargeting_interval() const NOEXCEPT
{
    return chain::chain_state::retargeting_interval(
        retargeting_interval_seconds, block_spacing_seconds);
}

} // namespace system
} // namespace libbitcoin
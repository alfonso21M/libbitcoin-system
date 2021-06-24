/**
 * Copyright (c) 2011-2021 libbitcoin developers (see AUTHORS)
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
#ifndef LIBBITCOIN_SYSTEM_IOSTREAM_SINKS_SINK_IPP
#define LIBBITCOIN_SYSTEM_IOSTREAM_SINKS_SINK_IPP

#include <algorithm>
#include <locale>
#include <bitcoin/system/constants.hpp>
#include <bitcoin/system/math/sign.hpp>

namespace libbitcoin {
namespace system {

template <typename Category, typename Container>
base_sink<Category, Container>::base_sink(size_type size) noexcept
  : size_(size)
{
}

template <typename Category, typename Container>
typename base_sink<Category, Container>::size_type
base_sink<Category, Container>::write(const char_type* buffer,
    size_type count) noexcept
{
    if (is_null(buffer) || is_negative(count))
        return negative_one;

    const auto size = std::min(size_, count);
    do_write(reinterpret_cast<const value_type*>(buffer), size);
    size_ -= size;

    // eof is indicated by the return of a value less than count.
    return size;
}

template <typename Category, typename Container>
void base_sink<Category, Container>::imbue(const std::locale& loc) noexcept
{
    // This is a no-op as all text is treated as UTF8.
}

} // namespace system
} // namespace libbitcoin

#endif

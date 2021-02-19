/*
 * Copyright 2019-2020, Offchain Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef valuecache_hpp
#define valuecache_hpp

#include <avm_values/code.hpp>
#include <avm_values/codepointstub.hpp>
#include <avm_values/pool.hpp>
#include <avm_values/tuple.hpp>
#include <avm_values/value.hpp>

#include <optional>
#include <vector>

class ValueCache {
   private:
    struct ValueCacheHasher {
        std::size_t operator()(const uint256_t& hash) const noexcept {
            return intx::narrow_cast<std::size_t>(hash);
        }
    };

    std::unordered_map<uint256_t, value, ValueCacheHasher> cache;

   public:
    void clear();
    void maybeSave(value val);
    std::optional<value> loadIfExists(const uint256_t& hash);
};

#endif /* valuecache_hpp */

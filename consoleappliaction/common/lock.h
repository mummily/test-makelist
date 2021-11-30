#pragma once
#include <shared_mutex>

using ReadLock = std::shared_lock<std::shared_mutex>;
using WriteLock = std::lock_guard<std::shared_mutex>;
using NormalLock = std::lock_guard<std::mutex>;

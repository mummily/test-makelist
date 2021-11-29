#pragma once
#include <shared_mutex>

typedef std::shared_lock<std::shared_mutex> ReadLock;
typedef std::lock_guard<std::shared_mutex> WriteLock;
typedef std::lock_guard<std::mutex> NormalLock;
#pragma once

#include <spectator/registry.h>

namespace atlasagent {

class CGroup {
 public:
  explicit CGroup(spectator::Registry* registry,
                  std::string path_prefix = "/sys/fs/cgroup") noexcept;
  void cpu_stats() noexcept;
  void memory_stats() noexcept;
  void set_prefix(std::string new_prefix) noexcept { path_prefix_ = std::move(new_prefix); }

 private:
  spectator::Registry* registry_;
  std::string path_prefix_;

  void cpu_processing_time() noexcept;
  void cpu_usage_time() noexcept;
  void cpu_shares() noexcept;
  void cpu_throttle() noexcept;
  void kmem_stats() noexcept;
};

}  // namespace atlasagent

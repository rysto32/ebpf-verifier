#pragma once
#include <boost/lexical_cast.hpp>

#include "spec_type_descriptors.hpp"

#include "crab/cfg.hpp"
#include "asm_syntax.hpp"

#include "crab_common.hpp"

inline auto label(int pc) { return std::to_string(pc); }
inline auto label(int pc, const label_t& target) { return label(pc) + ":" + target; }
inline auto label(int pc, int target) { return label(pc, std::to_string(target)); }
inline auto exit_label(const label_t& label) { return label + ":exit"; }
inline auto entry_label() { return label(-1, "entry"); }

inline int first_num(const label_t& s) {
    try {
        return boost::lexical_cast<int>(s.substr(0, s.find_first_of(":+")));
    } catch (...) {
        std::cout << "bad label:" << s << "\n";
        throw;
    }
}

/** Translate an eBPF cfg_t to to Crab's cfg_t.
 */
cfg_t build_crab_cfg(cfg_t const& simple_cfg, program_info info);

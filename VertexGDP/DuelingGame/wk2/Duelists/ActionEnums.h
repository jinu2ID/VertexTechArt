#pragma once
#include <cstdint>
enum class Action : uint8_t { Attack = 0, Parry = 1, Defend = 2, Count };

// Make a Combined enum where each combo is a single bit
// This allows us to use a bitmask to represent the combination of actions
// 
// index = playerIndex * Count + enemyIndex
// 
// player\enemy:   0        1        2
//        0   (0, 0)   (0, 1)   (0, 2)
//        1   (1, 0)   (1, 1)   (1, 2)
//        2   (2, 0)   (2, 1)   (2, 2)

enum CombinedCase : uint16_t {
	AttackVsAttack = 1 << (size_t(Action::Attack) * size_t(Action::Count) + size_t(Action::Attack)), // 1 << 1 = 00000001
	AttackVsParry = 1 << (size_t(Action::Attack) * size_t(Action::Count) + size_t(Action::Parry)),   // 1 << 2 = 00000010
	AttackVsDefend = 1 << (size_t(Action::Attack) * size_t(Action::Count) + size_t(Action::Defend)), // 1 << 4 = 00000100

	ParryVsAttack = 1 << (size_t(Action::Parry) * size_t(Action::Count) + size_t(Action::Attack)),   // 1 << 8 = 00001000
	ParryVsParry = 1 << (size_t(Action::Parry) * size_t(Action::Count) + size_t(Action::Parry)),     // 1 << 16 = 00010000
	ParryVsDefend = 1 << (size_t(Action::Parry) * size_t(Action::Count) + size_t(Action::Defend)),   // 1 << 32 = 00010000

	DefendVsAttack = 1 << (size_t(Action::Defend) * size_t(Action::Count) + size_t(Action::Attack)), // 1 << 64 = 00100000
	DefendVsParry = 1 << (size_t(Action::Defend) * size_t(Action::Count) + size_t(Action::Parry)),   // 1 << 128 = 00100000
	DefendVsDefend = 1 << (size_t(Action::Defend) * size_t(Action::Count) + size_t(Action::Defend))  // 1 << 256 = 01000000
};

inline CombinedCase GetCombinedCase(Action playerAction, Action enemyAction) {
	return static_cast<CombinedCase>(
		1 << (size_t(playerAction) * size_t(Action::Count) + size_t(enemyAction)));
}

inline std::string ToString(Action action) {
	switch (action) {
	case Action::Attack: return "Attack";
	case Action::Parry: return "Parry";
	case Action::Defend: return "Defend";
	default: return "Invalid";
	}
}
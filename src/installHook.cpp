#include "installHook.h"

namespace Hooks {

	struct UpdateCombatThreat
	{
		static void thunk(RE::CombatThreatMap* a_threatMap, RE::Projectile* a_projectile)
		{
			if (a_projectile) {
				const auto* base = a_projectile->GetBaseObject();
				const auto* projectileBase = base ? base->As<RE::BGSProjectile>() : nullptr;
				const auto* weaponSource = projectileBase ? a_projectile->weaponSource : nullptr;

				if (weaponSource) {
					bool bIsBound = false;

					if (weaponSource->weaponData.flags2 & RE::TESObjectWEAP::Data::Flag2::kBoundWeapon) {
						bIsBound = true;
					}

					if (bIsBound) {

					}
					else {

					}
				}
			}
			func(a_threatMap, a_projectile);
		}
		static inline REL::Relocation<decltype(thunk)> func;
	};

	void Install() {
		REL::Relocation<std::uintptr_t> target{ RELOCATION_ID(43030, 44222), OFFSET_3(0x3CB, 0x79D, 0x3A8) };
		stl::write_thunk_call<UpdateCombatThreat>(target.address());
		_loggerInfo("Installed hook.");
	}
}
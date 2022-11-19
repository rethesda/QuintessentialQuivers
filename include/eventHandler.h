#pragma once

namespace Events {

	class OnEquipEventHandler : public RE::BSTEventSink<RE::TESEquipEvent> {

	public:

		static OnEquipEventHandler* GetSingleton();
		static void                 RegisterListener();
		RE::BSEventNotifyControl    ProcessEvent(const RE::TESEquipEvent* a_event, RE::BSTEventSource<RE::TESEquipEvent>* a_eventSource) override;
	};

	inline static void Register() {

		OnEquipEventHandler::RegisterListener();
	}
}
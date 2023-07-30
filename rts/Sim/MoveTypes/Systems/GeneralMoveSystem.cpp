/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

// #undef NDEBUG

#include "GeneralMoveSystem.h"

#include "Sim/Ecs/Registry.h"
#include "Sim/MoveTypes/Components/MoveTypesComponents.h"
#include "Sim/Units/Unit.h"
#include "Sim/Units/UnitHandler.h"

#include "System/EventHandler.h"
#include "System/TimeProfiler.h"
#include "System/Threading/ThreadPool.h"
#include "Sim/Units/UnitDef.h"
using namespace MoveTypes;

void GeneralMoveSystem::Init() {}

void GeneralMoveSystem::Update() {
    auto view = Sim::registry.view<GeneralMoveType>();
	{
        SCOPED_TIMER("Sim::Unit::MoveType::5::UpdateST");
        view.each([](GeneralMoveType& unitId){
            CUnit* unit = unitHandler.GetUnit(unitId.value);
            AMoveType* moveType = unit->moveType;

            unit->SanityCheck();
			unit->PreUpdate();

            if (moveType->Update())
                eventHandler.UnitMoved(unit);

            // this unit is not coming back, kill it now without any death
            // sequence (s.t. deathScriptFinished becomes true immediately)
            if (!unit->pos.IsInBounds() && (unit->speed.w > MAX_UNIT_SPEED))
                unit->ForcedKillUnit(nullptr, false, true, false);

            unit->SanityCheck();
        });
	}
}

void GeneralMoveSystem::Shutdown() {}

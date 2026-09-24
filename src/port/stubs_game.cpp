#include "Game/Boss/DodoryuDemo.hpp"
#include "Game/Enemy/SamboHead.hpp"
#include "Game/Map/SphereSelector.hpp"
#include "Game/Screen/StaffRoll.hpp"
#include "Game/System/GameSystemResetAndPowerProcess.hpp"
#include "Game/Boss/Dodoryu.hpp"
#include "Game/System/StorySequenceExecutor.hpp"
#include "Game/System/WPadRumble.hpp"
#include "JSystem/J3DGraphBase/J3DPacket.hpp"
#include <stdbool.h>

void DodoryuDemoOpening::turnToRabbit() {}
void GameSystemResetAndPowerProcess::draw() const {}
void StaffRoll::exeLineScroll() {}
void StaffRoll::makeLine() {}
void SphereSelector::registerPointingTarget(LiveActor*, HandlePointingPriority) {}
const StorySequenceExecutorType::DemoSequenceInfo* 
StorySequenceExecutor::addDynamicDemoSequenceInfo(u16, u16, const char*) {
    return new StorySequenceExecutorType::DemoSequenceInfo();
}
bool WPadRumble::findRubmlePattern(const void*, s32*, s32*, s32*, const RumblePattern&) { return false; }
bool Dodoryu::keepOffFromClosedArea(TVec3f*) { return false; }
bool SamboHead::receiveOtherMsg(u32, HitSensor*, HitSensor*) { return false; }

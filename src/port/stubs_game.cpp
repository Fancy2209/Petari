#include "Game/Boss/DodoryuDemo.hpp"
#include "Game/Enemy/SamboHead.hpp"
#include "Game/Map/SphereSelector.hpp"
#include "Game/MapObj/MapPartsRailMover.hpp"
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

bool WPadRumble::findRubmlePattern(const void*, s32*, s32*, s32*, const RumblePattern&) { return false; }
bool Dodoryu::keepOffFromClosedArea(TVec3f*) { return false; }
bool SamboHead::receiveOtherMsg(u32, HitSensor*, HitSensor*) { return false; }

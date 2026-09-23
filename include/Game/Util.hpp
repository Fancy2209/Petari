#pragma once

#include "Game/Util/ActorCameraUtil.hpp"
#include "Game/Util/ActorMovementUtil.hpp"
#include "Game/Util/ActorSensorUtil.hpp"
#include "Game/Util/ActorShadowLocalUtil.hpp"
#include "Game/Util/ActorShadowUtil.hpp"
#include "Game/Util/ActorStateUtil.hpp"
#include "Game/Util/ActorSwitchUtil.hpp"
#include "Game/Util/AreaObjUtil.hpp"
#include "Game/Util/Array.hpp"
#include "Game/Util/BaseMatrixFollowTargetHolder.hpp"
#include "Game/Util/BitArray.hpp"
#include "Game/Util/BothDirList.hpp"
#include "Game/Util/CameraUtil.hpp"
#include "Game/Util/Color.hpp"
#include "Game/Util/DemoUtil.hpp"
#include "Game/Util/DirectDraw.hpp"
#include "Game/Util/DirectDrawUtil.hpp"
#include "Game/Util/DrawUtil.hpp"
#include "Game/Util/EffectUtil.hpp"
#include "Game/Util/EventUtil.hpp"
#include "Game/Util/FileUtil.hpp"
#include "Game/Util/FixedPosition.hpp"
#include "Game/Util/FootPrint.hpp"
#include "Game/Util/Functor.hpp"
#include "Game/Util/GamePadUtil.hpp"
#include "Game/Util/GeometryBindUtil.hpp"
#include "Game/Util/GravityUtil.hpp"
#include "Game/Util/HashUtil.hpp"
#include "Game/Util/IKJoint.hpp"
#include "Game/Util/JMapIdInfo.hpp"
#include "Game/Util/JMapInfo.hpp"
#include "Game/Util/JMapLinkInfo.hpp"
#include "Game/Util/JMapUtil.hpp"
#include "Game/Util/JointController.hpp"
#include "Game/Util/JointUtil.hpp"
#include "Game/Util/LayoutUtil.hpp"
#include "Game/Util/LightUtil.hpp"
#include "Game/Util/LiveActorUtil.hpp"
#include "Game/Util/MapPartsUtil.hpp"
#include "Game/Util/MapUtil.hpp"
#include "Game/Util/MathUtil.hpp"
#include "Game/Util/MemoryUtil.hpp"
#include "Game/Util/MessageUtil.hpp"
#include "Game/Util/ModelUtil.hpp"
#include "Game/Util/MtxUtil.hpp"
#include "Game/Util/MultiEventCamera.hpp"
#include "Game/Util/MutexHolder.hpp"
#include "Game/Util/NPCUtil.hpp"
#include "Game/Util/NerveUtil.hpp"
#include "Game/Util/ObjUtil.hpp"
#include "Game/Util/ParabolicPath.hpp"
#include "Game/Util/PlayerUtil.hpp"
#include "Game/Util/PostureHolder.hpp"
#include "Game/Util/RailUtil.hpp"
#include "Game/Util/RumbleCalculator.hpp"
#include "Game/Util/SceneUtil.hpp"
#include "Game/Util/SchedulerUtil.hpp"
#include "Game/Util/ScreenUtil.hpp"
#include "Game/Util/SequenceUtil.hpp"
#include "Game/Util/SingletonHolder.hpp"
#include "Game/Util/SoundUtil.hpp"
#include "Game/Util/SpringValue.hpp"
#include "Game/Util/StarPointerUtil.hpp"
#include "Game/Util/StringUtil.hpp"
#include "Game/Util/SwitchEventFunctorListener.hpp"
#include "Game/Util/SystemUtil.hpp"
#include "Game/Util/TalkUtil.hpp"
#include "Game/Util/TriangleFilter.hpp"
#include "Game/Util/TriggerChecker.hpp"
#include "Game/Util/ValueControl.hpp"
#include "Game/Util/VectorUtil.hpp"

#ifdef PLATFORM_PS3
#include <algorithm>
namespace std {
    template < class InputIterator, class Function >
    inline Function for_each_array(InputIterator* pFirst, InputIterator* pLast, Function f) {
        for (; pFirst != pLast; pFirst++) {
            f(pFirst);
        }

        return f;
    }
    
    template < class Result, class Type >
    inline mem_fun_t< Result, Type > mem_func(Result (Type::*pFunction)()) {
        return mem_fun_t< Result, Type >(pFunction);
    }

    template < class Result, class Type >
    inline const_mem_fun_t< Result, Type > mem_func(Result (Type::*pFunction)() const) {
        return const_mem_fun_t< Result, Type >(pFunction);
    }

    template < class Result, class Type, class Arg >
    inline mem_fun1_t< Result, Type, Arg > mem_func(Result (Type::*pFunction)(Arg)) {
        return mem_fun1_t< Result, Type, Arg >(pFunction);
    }

    template < class Result, class Type, class Arg >
    inline const_mem_fun1_t< Result, Type, Arg > mem_func(Result (Type::*pFunction)(Arg) const) {
        return const_mem_fun1_t< Result, Type, Arg >(pFunction);
    }
}
#endif

#pragma once

#include "flecs.h"

namespace Events
{
struct OnValueHasBeenToggled
{
};
} // namespace Events
extern "C"
{

    struct ModuleStruct
    {
        bool toggle;
    };

    struct Module
    {
        Module(flecs::world &world);
    };
}

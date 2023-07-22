#include "module.hpp"
#include <flecs.h>

int main()
{
    flecs::world ecs;

    ecs.import <Module>();

    flecs::entity bob = ecs.entity().set<ModuleStruct>({true});

    ecs.app().target_fps(60).run();
}

#include "module.hpp"
#include "flecs/addons/cpp/entity.hpp"
#include "flecs/addons/cpp/mixins/pipeline/decl.hpp"
#include <iostream>

Module::Module(flecs::world &ecs)
{
    ecs.module<Module>();
    ecs.component<ModuleStruct>();

    ecs.system<ModuleStruct>("Toggle Value")
        .kind(flecs::OnUpdate)
        .each([&](flecs::iter &it, size_t &i, ModuleStruct &ms) {
            ms.toggle = !ms.toggle;
            ecs.event<Events::OnValueHasBeenToggled>().id<ModuleStruct>().entity(it.entity(i)).emit();
        });

    ecs.observer<ModuleStruct>().event<Events::OnValueHasBeenToggled>().each(
        [](ModuleStruct &ms) { std::cout << "The value has been toggled to " << ms.toggle << "\n"; });
}
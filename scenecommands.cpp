#include "scenecommands.h"

SceneCommands::SceneCommands(PaintScene *scene, Sceneitem *s) :
    item(s),
    p_scene(scene)
{

}

void SceneCommands::undo()
{
    p_scene->removeItem(item);
}

void SceneCommands::redo()
{
    if(!item->isActive()) {
        p_scene->addItem(item);
    }
}

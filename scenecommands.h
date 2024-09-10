#ifndef SCENECOMMANDS_H
#define SCENECOMMANDS_H

#include <QUndoCommand>
#include <memory>

#include "sceneitem.h"
#include "paintscene.h"

class SceneCommands: public QUndoCommand
{
public:
    explicit SceneCommands(PaintScene *scene, Sceneitem *s);

    virtual void undo() override;
    virtual void redo() override;

private:
    Sceneitem *item;
    PaintScene *p_scene;
};

#endif // SCENECOMMANDS_H

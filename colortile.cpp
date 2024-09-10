#include "colortile.h"
#include <QDebug>

ColorTile::ColorTile(const QString& tileColor) :
    tileColor(tileColor)
{
    QString style = "border: 1px; background-color: " + tileColor;
    setStyleSheet(style);
    connect( this, SIGNAL( clicked() ), this, SLOT(slotButtonClicked()) );
    setFixedSize(QSize(16, 16));
}


void ColorTile::slotButtonClicked()
{
    emit signalTileClicked(tileColor);
}

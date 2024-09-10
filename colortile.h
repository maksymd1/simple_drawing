#ifndef COLORTILE_H
#define COLORTILE_H

#include <QAbstractButton>
#include <QPushButton>

class ColorTile : public QPushButton
{
    Q_OBJECT

public:
    ColorTile(const QString& tileColor);

public slots:
    void slotButtonClicked();

signals:
    void signalTileClicked(const QString& tileColor);

private:
    QString tileColor;
};

#endif // COLORTILE_H

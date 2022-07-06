#ifndef FW_ENUM_H
#define FW_ENUM_H

#include <QStringList>
#include <QColor>

const int FIELD_SIZE = 4;

enum MARKERS {
    MARKER_PLAYER,
    MARKER_BOT,
    MARKER_EMPTY,
    MARKER_NUMBER_OF
};

enum WINS {
    WIN_PLAYER,
    WIN_BOT,
    WIN_DRAW,
    WIN_NOONE,
    WIN_NUMBER_OF
};

enum BOTS {
    BOT_RANDOM,
    BOT_TREE,
    BOT_NUMBER_OF
};
const QStringList QSL_Bots = {
    "Random",
    "Tree"
};

enum COLOR {
    COL_DEFAULT,
    COL_PLAYER,
    COL_BOT,
    COL_EMPTY,
    COL_ERROR,
    COL_NUMBER_OF
};
const QStringList QSl_Colors = {
    "#000000",
    "#00ff00",
    "#0000ff",
    "#808080",
    "#ff0000"
};

const QColor Col_Player(0, 255, 0);
const QColor Col_Bot(0, 0, 255);
const QColor Col_Empty(128, 128, 128);

#endif // FW_ENUM_H

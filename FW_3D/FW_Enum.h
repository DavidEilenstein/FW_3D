#ifndef FW_ENUM_H
#define FW_ENUM_H

#include <QStringList>

const int FIELD_SIZE = 4;

enum MARKERS {
    MARKER_WHITE,
    MARKER_BLACK,
    MARKER_EMPTY,
    MARKER_NUMBER_OF
};

enum WINS {
    WIN_WHITE,
    WIN_BLACK,
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

#endif // FW_ENUM_H

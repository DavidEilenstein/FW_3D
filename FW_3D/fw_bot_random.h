#ifndef FW_BOT_RANDOM_H
#define FW_BOT_RANDOM_H

#include <fw_bot.h>
#include <QObject>
#include <QRandomGenerator>
#include <QDateTime>

class FW_Bot_Random : public FW_Bot
{
    Q_OBJECT
public:
    FW_Bot_Random();

    bool make_move(FW_Field* pField, int* x, int* y);
};

#endif // FW_BOT_RANDOM_H

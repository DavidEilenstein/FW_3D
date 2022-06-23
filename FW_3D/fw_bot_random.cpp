#include "fw_bot_random.h"

FW_Bot_Random::FW_Bot_Random()
{

}

bool FW_Bot_Random::make_move(FW_Field *pField, int *x, int *y)
{
    *x = 0;
    *y = 0;
    if(pField->check_full())
        return false;

    QRandomGenerator gen(QDateTime::currentDateTime().time().msecsSinceStartOfDay());

    while (true)
    {
        *x = gen.bounded(0, FIELD_SIZE);
        *y = gen.bounded(0, FIELD_SIZE);

        if(!pField->is_full_stack(*x, *y))
            return true;
    }
}


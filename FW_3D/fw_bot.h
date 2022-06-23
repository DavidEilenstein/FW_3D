#ifndef FW_BOT_H
#define FW_BOT_H

#include <QObject>
#include <fw_field.h>
class FW_Bot : public QObject
{
    Q_OBJECT
public:
    explicit FW_Bot(QObject *parent = nullptr);

    bool make_move(FW_Field* pField, int* x, int* y);

signals:

};

#endif // FW_BOT_H

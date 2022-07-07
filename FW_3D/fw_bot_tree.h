#ifndef FW_BOT_TREE_H
#define FW_BOT_TREE_H

#include <fw_bot.h>
#include <QObject>
#include <vector>
#include <QRandomGenerator>
#include <QDateTime>

using namespace std;

class FW_Bot_Tree : public FW_Bot
{
    Q_OBJECT
public:
    FW_Bot_Tree();

    bool make_move(FW_Field* pField, int* x, int* y, double* score);
    bool set_depths(int d);

private:

    bool try_subtrees(FW_Field field, int *x_best, int *y_best, double *score, char next_marker, int current_depth);
    double score_from_winner(char winner);

    int depth = 1;
};

#endif // FW_BOT_TREE_H

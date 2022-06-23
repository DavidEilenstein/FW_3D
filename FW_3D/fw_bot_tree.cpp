#include "fw_bot_tree.h"

FW_Bot_Tree::FW_Bot_Tree()
{

}

bool FW_Bot_Tree::make_move(FW_Field *pField, int *x, int *y)
{
    *x = 0;
    *y = 0;
    if(pField->check_full())
        return false;

    double score;
    if(!try_subtrees(*pField, x, y, &score, MARKER_BLACK, 0))
        return false;

    return true;
}

bool FW_Bot_Tree::set_depths(int d)
{
    if(d < 1)
        return false;

    depth = d;
    return true;
}

bool FW_Bot_Tree::try_subtrees(FW_Field field, int *x_best, int *y_best, double *score, char next_marker, int current_depth)
{
    //init with default output
    *x_best = 0;
    *y_best = 0;
    *score = 0;

    //field full? -> end
    if(field.check_full())
    {
        *score = 0.5;
        return false;
    }

    //someone wins? -> end (good or bad)
    char w;
    if(field.check_winner(&w))
    {
        *score = score_from_winner(w);
        return true;
    }

    //max depth reached? -> end
    current_depth++;
    if(current_depth > depth)
    {
        *score = 0.5;
        return true;
    }

    //subtree try scores
    double best_subtree_score = 0;
    vector<int> v_best_subtree_x;
    vector<int> v_best_subtree_y;
    double sum_subtrees_scores = 0;
    int subtrees_tried = 0;

    //loop subtrees
    for(int x = 0; x < FIELD_SIZE; x++)
    {
        for(int y = 0; y < FIELD_SIZE; y++)
        {
            //subtree possible?
            if(!field.is_full_stack(x, y))
            {
                //copy field for subtree try
                FW_Field field_copy = field;

                //make move in copy to generate subtree
                field_copy.insert_marker(x, y, next_marker);

                //subtree results
                double subtree_score = 0;
                int subtree_x, subtree_y;

                //subtree is an end?
                if(field_copy.check_end(&w))
                {
                    //end? -> set score
                    subtree_score = score_from_winner(w);
                }
                else
                {
                    //no end? -> go deeper into the subtrees
                    try_subtrees(field_copy, &subtree_x, &subtree_y, &subtree_score, next_marker == MARKER_BLACK ? MARKER_WHITE : MARKER_BLACK, current_depth + 1);
                }

                //count up subtree tries
                subtrees_tried++;
                sum_subtrees_scores += subtree_score;

                //better score? -> set as new best move
                if(subtree_score > best_subtree_score)
                {
                    best_subtree_score = subtree_score;
                    v_best_subtree_x.clear();
                    v_best_subtree_y.clear();
                    v_best_subtree_x.push_back(x);
                    v_best_subtree_y.push_back(y);
                }
                //equal score? -> add to list of possible best moves
                else if(subtree_score == best_subtree_score)
                {
                    v_best_subtree_x.push_back(x);
                    v_best_subtree_y.push_back(y);
                }
            }
        }
    }

    //no valid subtrees found? -> end
    if(subtrees_tried == 0)
        return false;

    //pick one of the possible best moves at random (confuse the humans^^)
    QRandomGenerator gen(QDateTime::currentDateTime().time().msecsSinceStartOfDay());
    size_t i_pick = gen.bounded(0, v_best_subtree_x.size());
    *x_best = v_best_subtree_x[i_pick];
    *y_best = v_best_subtree_y[i_pick];

    //calc score and happy end
    *score = sum_subtrees_scores / subtrees_tried;
    return true;
}

double FW_Bot_Tree::score_from_winner(char winner)
{
    switch (winner) {
    case WIN_WHITE:     return 0.0;
    case WIN_BLACK:     return 1.0;
    default:            return 0.5;
    }
}

#ifndef FW_FIELD_H
#define FW_FIELD_H

#include <FW_Enum.h>
#include <QString>
#include <vector>
#include <QDebug>

using namespace std;

class FW_Field
{
public:
    FW_Field();
    FW_Field(FW_Field& field2copy);

    void    clear_init();
    void    copy_data(FW_Field* field2copy);

    char    get_marker(int x, int y, int z);
    void    set_marker(int x, int y, int z, char m);
    bool    is_marker(int x, int y, int z, char m);

    bool    is_full_stack(int x, int y);
    int     get_first_empty_index(int x, int y);
    bool    insert_marker(int x, int y, char m);

    bool    check_end(char *w);
    bool    check_full();
    bool    check_winner(char *w);

    bool    check_tripples(int* wx, int* wy, char m);
    bool    check_tripples(int* wx, int* wy, int* wz, char m);

private:

    bool check_win(int x, int y, int z, int dx, int dy, int dz, char* w);
    bool check_tripple(int sx, int sy, int sz, int dx, int dy, int dz, char m_check, int *wx, int *wy, int* wz);

    vector<vector<vector<char>>> vvvData;
};

#endif // FW_FIELD_H

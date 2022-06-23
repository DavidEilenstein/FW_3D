#include "fw_field.h"

FW_Field::FW_Field()
{
    clear_init();
}

FW_Field::FW_Field(FW_Field &field2copy)
{
    clear_init();
    copy_data(&field2copy);
}

void FW_Field::clear_init()
{
    vvvData.clear();
    vvvData.resize(FIELD_SIZE, vector<vector<char>>(FIELD_SIZE, vector<char>(FIELD_SIZE, MARKER_EMPTY)));
}

void FW_Field::copy_data(FW_Field *field2copy)
{
    for(int z = 0; z < FIELD_SIZE; z++)
        for(int y = 0; y < FIELD_SIZE; y++)
            for(int x = 0; x < FIELD_SIZE; x++)
                set_marker(x, y, z, field2copy->get_marker(x, y, z));
}

char FW_Field::get_marker(int x, int y, int z)
{
    return vvvData[x][y][z];
}

void FW_Field::set_marker(int x, int y, int z, char m)
{
    vvvData[x][y][z] = m;
}

bool FW_Field::is_marker(int x, int y, int z, char m)
{
    return m == get_marker(x, y, z);
}

bool FW_Field::is_full_stack(int x, int y)
{
    for(int z = 0; z < FIELD_SIZE; z++)
        if(is_marker(x, y, z, MARKER_EMPTY))
            return false;

    return true;
}

int FW_Field::get_first_empty_index(int x, int y)
{
    for(int z = 0; z < FIELD_SIZE; z++)
        if(is_marker(x, y, z, MARKER_EMPTY))
            return z;

    return -1;
}

bool FW_Field::insert_marker(int x, int y, char m)
{
    if(is_full_stack(x, y))
        return false;

    set_marker(x, y, get_first_empty_index(x, y), m);

    return true;
}

bool FW_Field::check_end(char *w)
{
    if(check_full())
    {
        *w = WIN_DRAW;
        return true;
    }

    return check_winner(w);
}

bool FW_Field::check_full()
{
    for(int x = 0; x < FIELD_SIZE; x++)
        for(int y = 0; y < FIELD_SIZE; y++)
            if(!is_full_stack(x, y))
                return false;

    return true;
}

bool FW_Field::check_winner(char* w)
{
    *w = WIN_NOONE;

    //top corrdinate
    const int t = FIELD_SIZE - 1;

    //straight x
    for(int y = 0; y < FIELD_SIZE; y++)
        for(int z = 0; z < FIELD_SIZE; z++)
            if(check_win(   0, y, z,    1, 0, 0,    w))
                return true;

    //straight y
    for(int x = 0; x < FIELD_SIZE; x++)
        for(int z = 0; z < FIELD_SIZE; z++)
            if(check_win(   x, 0, z,    0, 1, 0,    w))
                return true;

    //straight z
    for(int x = 0; x < FIELD_SIZE; x++)
        for(int y = 0; y < FIELD_SIZE; y++)
            if(check_win(   x, y, 0,    0, 0, 1,    w))
                return true;


    //diagonal xy
    for(int z = 0; z < FIELD_SIZE; z++)
    {
        if(check_win(   0, 0, z,     1,  1,  0,     w))
            return true;

        if(check_win(   t, 0, z,    -1,  1,  0,     w))
            return true;
    }

    //diagonal xz
    for(int y = 0; y < FIELD_SIZE; y++)
    {
        if(check_win(   0, y, 0,     1,  0,  1,     w))
            return true;

        if(check_win(   t, y, 0,    -1,  0,  1,     w))
            return true;
    }

    //diagonal yz
    for(int x = 0; x < FIELD_SIZE; x++)
    {
        if(check_win(   x, 0, 0,     0,  1,  1,     w))
            return true;

        if(check_win(   x, 0, t,     0,  1, -1,     w))
            return true;
    }


    //diagonal xyz
    if(check_win(   0, 0, 0,     1,  1,  1,  w))     return true;
    if(check_win(   0, 0, t,     1,  1, -1,  w))     return true;
    if(check_win(   t, 0, 0,    -1,  1,  1,  w))     return true;
    if(check_win(   t, 0, t,    -1,  1, -1,  w))     return true;


    return false;
}

bool FW_Field::check_tripples(int *wx, int *wy, char m)
{
    int wz;
    return check_tripples(wx, wy, &wz, m);
}

bool FW_Field::check_tripples(int *wx, int *wy, int *wz, char m)
{
    //top corrdinate
    const int t = FIELD_SIZE - 1;

    //straight x
    for(int y = 0; y < FIELD_SIZE; y++)
        for(int z = 0; z < FIELD_SIZE; z++)
            if(check_tripple(   0, y, z,    1, 0, 0,    m,      wx, wy, wz))
                return true;

    //straight y
    for(int x = 0; x < FIELD_SIZE; x++)
        for(int z = 0; z < FIELD_SIZE; z++)
            if(check_tripple(   x, 0, z,    0, 1, 0,    m,      wx, wy, wz))
                return true;

    //straight z
    for(int x = 0; x < FIELD_SIZE; x++)
        for(int y = 0; y < FIELD_SIZE; y++)
            if(check_tripple(   x, y, 0,    0, 0, 1,    m,      wx, wy, wz))
                return true;


    //diagonal xy
    for(int z = 0; z < FIELD_SIZE; z++)
    {
        if(check_tripple(   0, 0, z,     1,  1,  0,    m,      wx, wy, wz))
            return true;

        if(check_tripple(   t, 0, z,    -1,  1,  0,    m,      wx, wy, wz))
            return true;
    }

    //diagonal xz
    for(int y = 0; y < FIELD_SIZE; y++)
    {
        if(check_tripple(   0, y, 0,     1,  0,  1,    m,      wx, wy, wz))
            return true;

        if(check_tripple(   t, y, 0,    -1,  0,  1,    m,      wx, wy, wz))
            return true;
    }

    //diagonal yz
    for(int x = 0; x < FIELD_SIZE; x++)
    {
        if(check_tripple(   x, 0, 0,     0,  1,  1,    m,      wx, wy, wz))
            return true;

        if(check_tripple(   x, 0, t,     0,  1, -1,    m,      wx, wy, wz))
            return true;
    }


    //diagonal xyz
    if(check_tripple(   0, 0, 0,     1,  1,  1,    m,      wx, wy, wz))     return true;
    if(check_tripple(   0, 0, t,     1,  1, -1,    m,      wx, wy, wz))     return true;
    if(check_tripple(   t, 0, 0,    -1,  1,  1,    m,      wx, wy, wz))     return true;
    if(check_tripple(   t, 0, t,    -1,  1, -1,    m,      wx, wy, wz))     return true;

    qDebug() << "found no tripple";
    return false;
}

bool FW_Field::check_win(int x, int y, int z, int dx, int dy, int dz, char *w)
{
    *w = WIN_NOONE;
    char m = get_marker(x, y, z);
    if(m == MARKER_EMPTY)
        return false;

    for(int i = 0; i < FIELD_SIZE; i++)
    {
        if(get_marker(x, y, z) != m)
            return false;

        x += dx;
        y += dy;
        z += dz;
    }

    if(m == MARKER_WHITE)
        *w = WIN_WHITE;
    else if(m == MARKER_BLACK)
        *w = WIN_BLACK;
    else
        return false;

    return true;
}

bool FW_Field::check_tripple(int sx, int sy, int sz, int dx, int dy, int dz, char m, int *wx, int *wy, int *wz)
{
    //s start
    //d step
    //w missing for win

    int x = sx;
    int y = sy;
    int z = sz;

    int miss_count = 0;
    for(int i = 0; i < FIELD_SIZE; i++)
    {
        //miss?
        if(get_marker(x, y, z) != m)
        {
            //non empty marker? -> allready blocked
            if(get_marker(x, y, z) != MARKER_EMPTY)
                return false;

            miss_count++;
        }

        //first miss could be the one missing to win
        if(miss_count == 1)
        {
            *wx = x;
            *wy = y;
            *wz = z;
        }

        //more than 1 miss? -> no way for tripple
        if(miss_count > 1)
            return false;

        x += dx;
        y += dy;
        z += dz;
    }

    if(miss_count == 1)
        if(get_first_empty_index(*wx, *wy) == *wz)
            return true;

    return false;
}

#include "mino.h"
#include <stddef.h>
#include <stdlib.h>

const int MINO_I_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_I_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};
const int MINO_I_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_I_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0}
};
const int MINO_T_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 1, },
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_T_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_T_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_T_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_L_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_L_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 1, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_L_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_L_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 1, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_J_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_J_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {1, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_J_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_J_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_O_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_O_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_O_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_O_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_S_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_S_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_S_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_S_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_Z_0[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_Z_90[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
};
const int MINO_Z_180[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 0, 0}
};
const int MINO_Z_270[MINO_MAT_LEN][MINO_MAT_LEN] = {
    {0, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
    {0, 0, 0, 0}
};

Mino* get_current_mino()
{
    static Mino current_mino = { 0 };
    static bool first = true;
    if (first) {
        current_mino.x = 3;
        current_mino.y = 20;
        current_mino.is_movable = true;
        int type = rand() % 7;
        switch (type) {
        case 0:
            current_mino.mino_type = MINO_I;
            break;
        case 1:
            current_mino.mino_type = MINO_T;
            break;
        case 2:
            current_mino.mino_type = MINO_L;
            break;
        case 3:
            current_mino.mino_type = MINO_J;
            break;
        case 4:
            current_mino.mino_type = MINO_O;
            break;
        case 5:
            current_mino.mino_type = MINO_S;
            break;
        case 6:
            current_mino.mino_type = MINO_Z;
            break;
        }
        first = false;
    }
    if (!current_mino.is_movable) {
        current_mino.x = 3;
        current_mino.y = 20;
        current_mino.is_movable = true;
        int type = rand() % 7;
        switch (type) {
        case 0:
            current_mino.mino_type = MINO_I;
            break;
        case 1:
            current_mino.mino_type = MINO_T;
            break;
        case 2:
            current_mino.mino_type = MINO_L;
            break;
        case 3:
            current_mino.mino_type = MINO_J;
            break;
        case 4:
            current_mino.mino_type = MINO_O;
            break;
        case 5:
            current_mino.mino_type = MINO_S;
            break;
        case 6:
            current_mino.mino_type = MINO_Z;
            break;
        }
    }
    return &current_mino;
}
bool move_left(Mino* mino)
{
    --mino->x;
    return true;
}
bool move_right(Mino* mino)
{
    ++mino->x;
    return true;
}
bool move_down(Mino* mino)
{
    --mino->y;
    return true;
}
bool rotate_clockwise(Mino* mino)
{
    switch (mino->mino_angle) {
    case ANGLE_0:
        mino->mino_angle = ANGLE_90;
        break;
    case ANGLE_90:
        mino->mino_angle = ANGLE_180;
        break;
    case ANGLE_180:
        mino->mino_angle = ANGLE_270;
        break;
    case ANGLE_270:
        mino->mino_angle = ANGLE_0;
        break;
    }
    return true;
}
bool rotate_counterclockwise(Mino* mino)
{
    switch (mino->mino_angle) {
    case ANGLE_0:
        mino->mino_angle = ANGLE_270;
        break;
    case ANGLE_90:
        mino->mino_angle = ANGLE_0;
        break;
    case ANGLE_180:
        mino->mino_angle = ANGLE_90;
        break;
    case ANGLE_270:
        mino->mino_angle = ANGLE_180;
        break;
    }
    return true;
}

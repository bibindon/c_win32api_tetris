#pragma once

#include <stdbool.h>

#define STAGE_WIDTH 10
#define STAGE_HEIGHT 20
#define MINO_MAT_LEN 4

typedef enum MinoType {
    MINO_I,
    MINO_T,
    MINO_L,
    MINO_J,
    MINO_O,
    MINO_S,
    MINO_Z
} MinoType;

typedef enum MinoAngle {
    ANGLE_0,
    ANGLE_90,
    ANGLE_180,
    ANGLE_270
} MinoAngle;

typedef struct Mino {
    MinoType mino_type;
    MinoAngle mino_angle;
    int x;
    int y; // bottom is 0
    bool is_movable;
    bool is_next;
} Mino;

const int MINO_I_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_I_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_I_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_I_270[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_T_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_T_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_T_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_T_270[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_L_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_L_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_L_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_L_270[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_J_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_J_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_J_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_J_270[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_O_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_O_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_O_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_O_270[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_S_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_S_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_S_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_S_270[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_Z_0[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_Z_90[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_Z_180[MINO_MAT_LEN][MINO_MAT_LEN];
const int MINO_Z_270[MINO_MAT_LEN][MINO_MAT_LEN];

Mino* get_current_mino();

bool move_left(Mino*);
bool move_right(Mino*);
bool move_down(Mino*);

bool rotate_clockwise(Mino*);
bool rotate_counterclockwise(Mino*);


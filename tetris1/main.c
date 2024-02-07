#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include "resource.h"
#include "mino.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define BLOCK_LEN 10

static void get_stage_mat(int* stage_block[STAGE_HEIGHT][STAGE_WIDTH])
{
    static int block_map[STAGE_HEIGHT][STAGE_WIDTH] = {{0}};
    for (int row = 0; row < STAGE_HEIGHT; ++row) {
        for (int col = 0; col < STAGE_WIDTH; ++col) {
            stage_block[row][col] = &block_map[row][col];
        }
    }
}
static bool is_exist_block(int row, int col)
{
    if (row >= STAGE_HEIGHT) {
        return false;
    }
    int* stage_block[STAGE_HEIGHT][STAGE_WIDTH];
    get_stage_mat(stage_block);
    if (*stage_block[row][col] == 1) {
        return true;
    }
    return false;
}
static void get_mino_mat(Mino* mino, int mino_mat[MINO_MAT_LEN][MINO_MAT_LEN])
{
    if (mino->mino_type == MINO_I) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_I_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_I_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_I_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_I_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    } else if (mino->mino_type == MINO_T) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_T_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_T_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_T_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_T_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    } else if (mino->mino_type == MINO_L) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_L_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_L_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_L_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_L_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    } else if (mino->mino_type == MINO_J) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_J_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_J_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_J_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_J_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    } else if (mino->mino_type == MINO_O) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_O_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_O_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_O_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_O_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    } else if (mino->mino_type == MINO_S) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_S_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_S_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_S_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_S_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    } else if (mino->mino_type == MINO_Z) {
        if (mino->mino_angle == ANGLE_0) {
            memcpy(mino_mat, MINO_Z_0, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_90) {
            memcpy(mino_mat, MINO_Z_90, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_180) {
            memcpy(mino_mat, MINO_Z_180, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        } else if (mino->mino_angle == ANGLE_270) {
            memcpy(mino_mat, MINO_Z_270, sizeof(int)*MINO_MAT_LEN*MINO_MAT_LEN);
        }
    }
}
static void set_stage_mino(Mino* mino)
{
    int* stage_block[STAGE_HEIGHT][STAGE_WIDTH];
    get_stage_mat(stage_block);
    int mino_mat[MINO_MAT_LEN][MINO_MAT_LEN];
    get_mino_mat(mino, mino_mat);
    for (int row = MINO_MAT_LEN-1; row >= 0; --row) {
        for (int col = 0; col < MINO_MAT_LEN; ++col) {
            if (mino_mat[row][col] == 1) {
                if ((mino->y + ((MINO_MAT_LEN - 1) - row)) < STAGE_HEIGHT) {
                    *stage_block[mino->y + ((MINO_MAT_LEN-1)-row)][mino->x + col] = 1;
                }
            }
        }
    }
}
static void paint_block(HDC hdc, int row, int col)
{
    Rectangle(hdc,
        col * BLOCK_LEN,
        ((STAGE_HEIGHT-1) - row) * BLOCK_LEN,
        col * BLOCK_LEN + BLOCK_LEN,
        ((STAGE_HEIGHT-1) - row) * BLOCK_LEN + BLOCK_LEN);
}
static void paint_stage(HDC hdc)
{
    int* stage_block[STAGE_HEIGHT][STAGE_WIDTH];
    get_stage_mat(stage_block);
    for (int row = 0; row < STAGE_HEIGHT; ++row) {
        for (int col = 0; col < STAGE_WIDTH; ++col) {
            if (*stage_block[row][col] == 1) {
                paint_block(hdc, row, col);
            }
        }
    }
}
static void paint_mino(HDC hdc)
{
    Mino* mino = NULL;
    mino = get_current_mino();
    HBRUSH hbrush;
    hbrush = CreateSolidBrush(RGB(0, 255, 255));
    SelectObject(hdc, hbrush);
    int mino_mat[MINO_MAT_LEN][MINO_MAT_LEN];
    get_mino_mat(mino, mino_mat);
    for (int row = 0; row < MINO_MAT_LEN; ++row) {
        for (int col = 0; col < MINO_MAT_LEN; ++col) {
            if (mino_mat[row][col] == 1) {
                paint_block(hdc,
                    mino->y+((MINO_MAT_LEN-1)-row),
                    mino->x+col);
            }
        }
    }
}
static bool is_can_left(Mino* mino)
{
    int mino_mat[MINO_MAT_LEN][MINO_MAT_LEN];
    get_mino_mat(mino, mino_mat);
    for (int row = MINO_MAT_LEN -1; row >= 0; --row) {
        for (int col = 0; col < MINO_MAT_LEN; ++col) {
            if (mino_mat[row][col] == 1) {
                if (mino->x + col - 1 <= -1) {
                    return false;
                }
                bool exist = is_exist_block(mino->y+((MINO_MAT_LEN-1)-row), mino->x+col-1);
                if (exist) {
                    return false;
                }
            }
        }
    }
    return true;
}
static bool is_can_right(Mino* mino)
{
    int mino_mat[MINO_MAT_LEN][MINO_MAT_LEN];
    get_mino_mat(mino, mino_mat);
    for (int row = MINO_MAT_LEN -1; row >= 0; --row) {
        for (int col = 0; col < MINO_MAT_LEN; ++col) {
            if (mino_mat[row][col] == 1) {
                if (mino->x + col + 1 >= STAGE_WIDTH) {
                    return false;
                }
                bool exist = is_exist_block(mino->y+((MINO_MAT_LEN-1)-row), mino->x+col+1);
                if (exist) {
                    return false;
                }
            }
        }
    }
    return true;
}
static bool is_can_down(Mino* mino)
{
    int mino_mat[MINO_MAT_LEN][MINO_MAT_LEN];
    get_mino_mat(mino, mino_mat);
    for (int row = MINO_MAT_LEN -1; row >= 0; --row) {
        for (int col = 0; col < MINO_MAT_LEN; ++col) {
            if (mino_mat[row][col] == 1) {
                if (mino->y + ((MINO_MAT_LEN-1)-row) - 1 <= -1) {
                    return false;
                }
                bool exist = is_exist_block(mino->y+((MINO_MAT_LEN-1)-row)-1, mino->x+col);
                if (exist) {
                    return false;
                }
            }
        }
    }
    return true;
}
static void remove_filled_line(remove_row)
{
    int* stage_block[STAGE_HEIGHT][STAGE_WIDTH];
    get_stage_mat(stage_block);
    for (int row = remove_row; row < STAGE_HEIGHT; ++row) {
        for (int col = 0; col < STAGE_WIDTH; ++col) {
            if (row != STAGE_HEIGHT - 1) {
                *stage_block[row][col] = *stage_block[row+1][col];
            } else {
                *stage_block[row][col] = 0;
            }
        }
    }
}
static void remove_filled_lines()
{
    int* stage_block[STAGE_HEIGHT][STAGE_WIDTH];
    get_stage_mat(stage_block);
    for (int row = 0; row < STAGE_HEIGHT; ++row) {
        if (is_exist_block(row, 0) &&
                is_exist_block(row, 1) &&
                is_exist_block(row, 2) &&
                is_exist_block(row, 3) &&
                is_exist_block(row, 4) &&
                is_exist_block(row, 5) &&
                is_exist_block(row, 6) &&
                is_exist_block(row, 7) &&
                is_exist_block(row, 8) &&
                is_exist_block(row, 9)) {
            remove_filled_line(row);
            --row;
        }
    }
}
static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    HDC hdc;
    HDC hbuffer;
    static HDC stage_hdc;
    static HBITMAP stage_bitmap;
    PAINTSTRUCT paintstruct;
    static HBITMAP hbitmap;
    static int fall_count_per_second = 2; // 1•b‚É2‰ñ—Ž‰º
    SYSTEMTIME current_time = { 0 };
    static SYSTEMTIME previous_time = { 0 };
    static WORD sum_time = 0;

    switch (msg) {
    case WM_DESTROY:
        DeleteObject(stage_hdc);
        DeleteObject(stage_bitmap);
        DeleteObject(hbitmap);
        PostQuitMessage(0);
        return 0;
    case WM_TIMER:
        GetLocalTime(&current_time);
        WORD previous_mseconds = previous_time.wMilliseconds;
        WORD mseconds = current_time.wMilliseconds;
        if (mseconds < previous_mseconds) {
            mseconds += 1000;
        }
        sum_time += (mseconds - previous_mseconds);
        if (sum_time >= (1000/fall_count_per_second)) {
            Mino* mino = get_current_mino();
            bool can_down = is_can_down(mino);

            if (can_down) {
                --mino->y;
            } else {
                set_stage_mino(mino);
                mino->is_movable = false;
                // remove filled line
                remove_filled_lines();
                // check gameover
                if (is_exist_block(STAGE_HEIGHT - 1, 3) ||
                        is_exist_block(STAGE_HEIGHT - 1, 4) ||
                        is_exist_block(STAGE_HEIGHT - 1, 5)) {
                    KillTimer(hwnd, 1);
                    MessageBox(NULL, TEXT("GAME OVER"),
                        TEXT("GAME OVER"), MB_ICONINFORMATION);
                }
            }
            sum_time = 0;
        }
        InvalidateRect(hwnd, NULL, TRUE);

        previous_time = current_time;
        return 0;
    case WM_CREATE:
        SetTimer(hwnd, 1, 17, NULL);
        GetLocalTime(&previous_time);
        stage_bitmap = LoadBitmap(((LPCREATESTRUCT)lp)->hInstance, MAKEINTRESOURCE(IDB_BITMAP1));
        hdc = GetDC(hwnd);
        stage_hdc = CreateCompatibleDC(hdc);
        SelectObject(stage_hdc, stage_bitmap);
        hbitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
        return 0;
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT:
    {
        hdc = BeginPaint(hwnd, &paintstruct);
        hbuffer = CreateCompatibleDC(hdc);
        SelectObject(hbuffer, hbitmap);
        BitBlt(hbuffer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, stage_hdc, 0, 0, SRCCOPY);
        paint_mino(hbuffer);
        paint_stage(hbuffer);
        BitBlt(hdc, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, hbuffer, 0, 0, SRCCOPY);
        DeleteDC(hbuffer);
        EndPaint(hwnd, &paintstruct);

        return 0;
    }
    case WM_KEYDOWN:
    {
        Mino* mino = NULL;
        mino = get_current_mino();
        switch (wp) {
        case 'X':
            rotate_counterclockwise(mino);
            break;
        case 'Z':
            rotate_clockwise(mino);
            break;
        case VK_LEFT:
            if (is_can_left(mino)) {
                move_left(mino);
            }
            break;
        case VK_RIGHT:
            if (is_can_right(mino)) {
                move_right(mino);
            }
            break;
        case VK_DOWN:
            if (is_can_down(mino)) {
                move_down(mino);
            }
            break;
        }
        InvalidateRect(hwnd, NULL, TRUE);
        return 0;
    }
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}
static VOID set_client_size(HWND hwnd, LONG sx, LONG sy)
{
    RECT rc1;
    RECT rc2;

    GetWindowRect(hwnd, &rc1);
    GetClientRect(hwnd, &rc2);
    sx += ((rc1.right - rc1.left) - (rc2.right - rc2.left));
    sy += ((rc1.bottom - rc1.top) - (rc2.bottom - rc2.top));
    SetWindowPos(hwnd, NULL, 0, 0, sx, sy, (SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOMOVE));
}
static void main_loop()
{

}
int WINAPI WinMain(_In_ HINSTANCE hinstance, _In_opt_ HINSTANCE hprev_instance,
    _In_ PSTR cmd_line, _In_ int cmd_show)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS winc = { 0 };

    winc.style = CS_HREDRAW | CS_VREDRAW;
    winc.lpfnWndProc = WndProc;
    winc.cbClsExtra = 0;
    winc.cbWndExtra = 0;
    winc.hInstance = hinstance;
    winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    winc.hCursor = LoadCursor(NULL, IDC_ARROW);
    winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    winc.lpszMenuName = NULL;
    winc.lpszClassName = TEXT("TETRIS");

    if (!RegisterClass(&winc)) {
        return -1;
    }

    hwnd = CreateWindow(
        TEXT("TETRIS"),
        TEXT("C lang and WIN32API tetris"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hinstance,
        NULL);

    if (hwnd == NULL) {
        return -1;
    }

    set_client_size(hwnd, SCREEN_WIDTH, SCREEN_HEIGHT);

    DWORD time = 0;
    while (TRUE) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        } else {
            main_loop();
        }
    }
    return (int)msg.wParam;
}

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "engine.h"
#include "gameconsts.h"
#include "util.h"

// An obstacle consists of a grid of OBS_GRID_SIZE x OBS_GRID_SIZE cells; each of them may
// or may not contain a box. One of the cells may be the bonus cell, which gives the player
// a bonus when hit.
//
// The obstacle grid lies on the XZ plane.
class Obstacle {
    public:
        bool grid[OBS_GRID_SIZE][OBS_GRID_SIZE]; // indexed as [col][row]
        int style;  // obstacle style (currently, this specifies its color).
        int bonusRow, bonusCol;
        const static int STYLE_NULL = 0;  // a null obstacle (not displayed)

        glm::vec3 GetBoxCenter(int gridCol, int gridRow, float posY) {
            return glm::vec3(-TUNNEL_HALF_W + (gridCol + 0.5f) * OBS_CELL_SIZE, posY,
                    -TUNNEL_HALF_H + (gridRow + 0.5f) * OBS_CELL_SIZE);
        }

        glm::vec3 GetBoxSize(int gridCol, int gridRow) {
            return glm::vec3(OBS_BOX_SIZE, OBS_BOX_SIZE, OBS_BOX_SIZE);
        }

        int GetRowAt(float z) {
            return Clamp((int)floor((z + TUNNEL_HALF_H) / OBS_CELL_SIZE), 0, OBS_GRID_SIZE - 1);
        }

        int GetColAt(float x) {
            return Clamp((int)floor((x + TUNNEL_HALF_W) / OBS_CELL_SIZE), 0, OBS_GRID_SIZE - 1);
        }

        float GetMinY(float posY) { return posY - OBS_BOX_SIZE * 0.5f; }
        float GetMaxY(float posY) { return posY + OBS_BOX_SIZE * 0.5f; }

        void Reset() {
            style = STYLE_NULL;
            bonusRow = bonusCol = -1;
            memset(grid, 0, sizeof(grid));
        }

        void SetBonus(int col, int row) {
            bonusCol = col;
            bonusRow = row;
        }

        void PutRandomBonus();

        void DeleteBonus() {
            bonusCol = bonusRow = -1;
        }

        bool HasBonus() {
            return bonusRow >= 0 && bonusRow < OBS_GRID_SIZE &&
                    bonusCol >= 0 && bonusCol < OBS_GRID_SIZE &&
                    !grid[bonusCol][bonusRow];
        }
};


#endif // OBSTACLE_H

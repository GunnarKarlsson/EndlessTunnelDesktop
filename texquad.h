#ifndef TEXQUAD_H
#define TEXQUAD_H


#include "engine.h"
#include "ourshader.h"

// Represents a simple 2D textured quad (that can be used to render an icon, for example)
class TexQuad {
    private:
        Texture *mTexture;
        OurShader *mOurShader;
        SimpleGeom *mGeom;
        float mWidth, mHeight;
        float mScale;
        float mCenterX, mCenterY;
        float mAspect;
        void CreateGeom(float umin, float vmin, float umax, float vmax);
        void Init(Texture *t, OurShader *shader, float aspect,
                float umin, float vmin, float umax, float vmax) {
            mTexture = t;
            mOurShader = shader;
            mAspect = aspect;
            mWidth = mAspect;
            mHeight = 1.0f;
            mCenterX = mCenterY = 0.0f;
            mScale = 1.0f;
            CreateGeom(umin, vmin, umax, vmax);
        }
    public:
        TexQuad(Texture *t, OurShader *shader, float aspect, float umin, float vmin,
                float umax, float vmax) {
            Init(t, shader, aspect, umin, vmin, umax, vmax);
        }
        TexQuad(Texture *t, OurShader *shader, float umin, float vmin, float umax,
               float vmax) {
            Init(t, shader, (umax - umin) / (vmax - vmin), umin, vmin, umax, vmax);
        }
        float GetCenterX() { return mCenterX; }
        float GetCenterY() { return mCenterY; }
        float GetWidth() { return mWidth; }
        float GetHeight() { return mHeight; }
        float GetLeft() { return mCenterX - mWidth * 0.5f; }
        float GetRight() { return mCenterX + mWidth * 0.5f; }
        float GetBottom() { return mCenterY - mHeight * 0.5f; }
        float GetTop() { return mCenterY + mHeight * 0.5f; }
        bool Contains(float x, float y) {
            return x >= GetLeft() && x <= GetRight() && y >= GetBottom() && y <= GetTop();
        }

        void SetCenter(float x, float y) {
            mCenterX = x;
            mCenterY = y;
        }
        void SetWidth(float w) {
            mWidth = w;
            mHeight = w / mAspect;
        }
        void SetHeight(float h) {
            mHeight = h;
            mWidth = h * mAspect;
        }
        ~TexQuad() {
            if (mGeom) {
                delete mGeom;
            }
        }
        void SetScale(float scale) {
            mScale = scale;
        }
        void Render() {
            Render(NULL);
        }
        void Render(glm::mat4 *transform);
};


#endif // TEXQUAD_H

#ifndef TEXTURE_H
#define TEXTURE_H


#include "common.h"

/* Represents an OpenGL texture */
class Texture {
    private:
        GLuint mTextureH;

    public:
        inline Texture() {
            mTextureH = 0;
        }

        // Initialize from raw RGB data. If hasAlpha is true, then it's 4 bytes per pixel
        // (RGBA), otherwise it's interpreted as 3 bytes per pixel (RGB).
        void InitFromRawRGB(int width, int height, bool hasAlpha, const unsigned char *data);
        void Bind(int unit);
        void Unbind();
};

#endif // TEXTURE_H

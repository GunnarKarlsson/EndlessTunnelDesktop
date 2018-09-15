#ifndef OURSHADER_H
#define OURSHADER_H

#include "shader.h"
#include "engine.h"
#include "texture.h"

// An OpenGL shader that can apply a texture and a point light.
// We use to to render the tunnel and the obstacles.
class OurShader : public Shader {
    protected:
       GLint mColorLoc;
       GLint mTexCoordLoc;
       int mTintLoc;
       int mSamplerLoc;
       int mPointLightPosLoc;
       int mPointLightColorLoc;
    public:
       OurShader();
       virtual ~OurShader();
       virtual void Compile();
       void SetTexture(Texture *t);
       void SetTintColor(float r, float g, float b);
       void EnablePointLight(glm::vec3 pos, float r, float g, float b);
       void DisablePointLight();
       virtual void BeginRender(VertexBuf *geom);
   protected:
       virtual const char *GetVertShaderSource();
       virtual const char *GetFragShaderSource();
       virtual const char *GetShaderName();
};

#endif // OURSHADER_H

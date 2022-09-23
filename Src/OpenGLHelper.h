#ifndef _OPENGL_HELPER_H
#define _OPENGL_HELPER_H

namespace OpenGLHelper {

  void Init(
    const unsigned screenWidth,
    const unsigned screenHeight
  );

  void Clear(
    const float r, 
    const float g, 
    const float b
  );

  void Flush();

}

#endif

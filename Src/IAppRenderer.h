#ifndef _I_APP_RENDERER_H
#define _I_APP_RENDERER_H

class IAppRenderer {
  public:
    virtual ~IAppRenderer() = default;

    virtual void Render() = 0;
};

#endif

#ifndef _I_APP_INITIALIZER_H
#define _I_APP_INITIALIZER_H

class IAppInitializer {
  public:
    virtual ~IAppInitializer() = default;

    virtual void Initialize() = 0;
};

#endif

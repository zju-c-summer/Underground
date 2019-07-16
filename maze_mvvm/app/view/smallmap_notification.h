#pragma once
//#include "smallMap.h"
#include "../../utility/common/base.h"

class smallMap;
class smallMapNotification: public Notification{
private:
    //std::shared_ptr<smallMap> view;
    smallMap *view;
public:
    void setView(smallMap* sv);
    virtual void exec();
};

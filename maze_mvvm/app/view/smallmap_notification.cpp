#include"smallmap_notification.h"
#include"smallMap.h"

void smallMapNotification::setView(smallMap* sv){
    view = sv;
}
void smallMapNotification::exec(){
    view->update();
}

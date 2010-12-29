// #include  "btBulletDynamicsCommon.h"

#include  "Bullet.h"

extern "C" void
init (Handle<Object> target) {
    HandleScope scope;
    
    Bullet::Initialize(target);
}
// #include  "btBulletDynamicsCommon.h"

#include  "Bullet.h"
#include  "DefaultCollisionConfiguration.h"
#include  "CollisionDispatcher.h"

extern "C" void
init (Handle<Object> target) {
    HandleScope scope;
    
    Bullet::Initialize(target);
    DefaultCollisionConfiguration::Initialize(target);
    CollisionDispatcher::Initialize(target);
}
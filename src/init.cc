#include  "btBulletDynamicsCommon.h"

#include "Bullet.h"
#include "DefaultCollisionConfiguration.h"
#include "CollisionDispatcher.h"
#include "DbvtBroadphase.h"
#include "SequentialImpulseConstraintSolver.h"
#include "DiscreteDynamicsWorld.h"
#include "BoxShape.h"
#include "Transform.h"
#include "RigidBody.h"

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

using namespace v8;
using namespace node;

extern "C" void
init (Handle<Object> target) {
    HandleScope scope;
    
    Bullet::Initialize(target);
    DefaultCollisionConfiguration::Initialize(target);
    CollisionDispatcher::Initialize(target);
    DbvtBroadphase::Initialize(target);
    SequentialImpulseConstraintSolver::Initialize(target);
    DiscreteDynamicsWorld::Initialize(target);
    BoxShape::Initialize(target);
    Transform::Initialize(target);
    RigidBody::Initialize(target);
}
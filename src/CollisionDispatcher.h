#ifndef __NODE_COLLISIONDISPATCHER_H__
#define __NODE_COLLISIONDISPATCHER_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

#include "DefaultCollisionConfiguration.h"

#include "btBulletDynamicsCommon.h"

using namespace v8;
using namespace node;

class CollisionDispatcher: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    
    CollisionDispatcher(DefaultCollisionConfiguration* defaultCollisionConfiguration);
    
    btCollisionDispatcher* _btCollisionDispatcher;

  private:
    ~CollisionDispatcher();
};

#endif
#ifndef __NODE_DEFAULTCOLLISIONCONFIGURATION_H__
#define __NODE_DEFAULTCOLLISIONCONFIGURATION_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

#include "btBulletDynamicsCommon.h"

using namespace v8;
using namespace node;

class DefaultCollisionConfiguration: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    
    DefaultCollisionConfiguration();
    
    btDefaultCollisionConfiguration* _btDefaultCollisionConfiguration;

  private:
    ~DefaultCollisionConfiguration();
};

#endif
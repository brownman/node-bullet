#ifndef __NODE_TRANSFORM_H__
#define __NODE_TRANSFORM_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

#include "btBulletDynamicsCommon.h"

using namespace v8;
using namespace node;

class Transform: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    
    Transform();

    btTransform* _btTransform;
    
  private:
    ~Transform();
};

#endif
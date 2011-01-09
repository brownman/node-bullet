#ifndef __NODE_DBVTBROADPHASE_H__
#define __NODE_DBVTBROADPHASE_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

#include "btBulletDynamicsCommon.h"

using namespace v8;
using namespace node;

class DbvtBroadphase: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    
    DbvtBroadphase();
    
    btDbvtBroadphase* _btDbvtBroadphase;

  private:
    ~DbvtBroadphase();
};

#endif
#ifndef __NODE_BOXSHAPE_H__
#define __NODE_BOXSHAPE_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

#include "btBulletDynamicsCommon.h"

using namespace v8;
using namespace node;

class BoxShape: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    
    BoxShape();

    btBoxShape* _btBoxShape;
    
  private:
    ~BoxShape();
};

#endif
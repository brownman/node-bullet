#ifndef __NODE_BULLET_H__
#define __NODE_BULLET_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

using namespace v8;
using namespace node;

class Bullet: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    
    Bullet();

  private:
    ~Bullet();
};

#endif
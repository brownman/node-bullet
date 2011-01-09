#include "BoxShape.h"

Persistent<FunctionTemplate> BoxShape::constructor;

void
BoxShape::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(BoxShape::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("BoxShape"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("BoxShape"), constructor->GetFunction());
}

Handle<Value>
BoxShape::New(const Arguments &args) {
  HandleScope scope;
  
  BoxShape* boxShape = new BoxShape();
  boxShape->Wrap(args.This());
  
  return args.This();
}

BoxShape::BoxShape(): ObjectWrap() {
  _btBoxShape = new btBoxShape(btVector3(btScalar(1.0),btScalar(1.0),btScalar(1.0)));
}

BoxShape::~BoxShape() {
  if (_btBoxShape) {
    delete _btBoxShape;
  }
}
#include "Transform.h"

Persistent<FunctionTemplate> Transform::constructor;

void
Transform::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Transform::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Transform"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("Transform"), constructor->GetFunction());
}

Handle<Value>
Transform::New(const Arguments &args) {
  HandleScope scope;
  
  Transform* transform = new Transform();
  transform->Wrap(args.This());
  
  return args.This();
}

Transform::Transform(): ObjectWrap() {
  _btTransform = new btTransform();
  
  // TODO move these out to methods
  _btTransform->setIdentity();
  _btTransform->setOrigin(btVector3(0, 0, 0));
}

Transform::~Transform() {
  if (_btTransform) {
    delete _btTransform;
  }
}
#include "CollisionDispatcher.h"

Persistent<FunctionTemplate> CollisionDispatcher::constructor;

void
CollisionDispatcher::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(CollisionDispatcher::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("CollisionDispatcher"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("CollisionDispatcher"), constructor->GetFunction());
}

Handle<Value>
CollisionDispatcher::New(const Arguments &args) {
  HandleScope scope;
  
  Local<Object> obj = args[0]->ToObject();
  DefaultCollisionConfiguration* defaultCollisionConfiguration = ObjectWrap::Unwrap<DefaultCollisionConfiguration>(obj);
  
  CollisionDispatcher* collisionDispatcher = new CollisionDispatcher(defaultCollisionConfiguration);
  collisionDispatcher->Wrap(args.This());
  
  return args.This();
}

CollisionDispatcher::CollisionDispatcher(DefaultCollisionConfiguration* defaultCollisionConfiguration): ObjectWrap() {
  _btCollisionDispatcher = new btCollisionDispatcher(defaultCollisionConfiguration->_btDefaultCollisionConfiguration);
}

CollisionDispatcher::~CollisionDispatcher() {
  if (_btCollisionDispatcher) {
    delete _btCollisionDispatcher;
  }
}
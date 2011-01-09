#include "DefaultCollisionConfiguration.h"

Persistent<FunctionTemplate> DefaultCollisionConfiguration::constructor;

void
DefaultCollisionConfiguration::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(DefaultCollisionConfiguration::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("DefaultCollisionConfiguration"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("DefaultCollisionConfiguration"), constructor->GetFunction());
}

Handle<Value>
DefaultCollisionConfiguration::New(const Arguments &args) {
  HandleScope scope;
  
  DefaultCollisionConfiguration* defaultCollisionConfiguration = new DefaultCollisionConfiguration();
  defaultCollisionConfiguration->Wrap(args.This());
  
  return args.This();
}

DefaultCollisionConfiguration::DefaultCollisionConfiguration(): ObjectWrap() {
  _btDefaultCollisionConfiguration = new btDefaultCollisionConfiguration();
}

DefaultCollisionConfiguration::~DefaultCollisionConfiguration() {
  if (_btDefaultCollisionConfiguration) {
    //delete _btDefaultCollisionConfiguration;
  }
}
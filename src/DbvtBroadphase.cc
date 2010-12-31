#include "DbvtBroadphase.h"

Persistent<FunctionTemplate> DbvtBroadphase::constructor;

void
DbvtBroadphase::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(DbvtBroadphase::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("DbvtBroadphase"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("DbvtBroadphase"), constructor->GetFunction());
}

Handle<Value>
DbvtBroadphase::New(const Arguments &args) {
  HandleScope scope;
  
  DbvtBroadphase* dbvtBroadphase = new DbvtBroadphase();
  dbvtBroadphase->Wrap(args.This());
  
  return args.This();
}

DbvtBroadphase::DbvtBroadphase(): ObjectWrap() {
}

DbvtBroadphase::~DbvtBroadphase() {
}
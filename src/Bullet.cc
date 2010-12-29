#include "Bullet.h"

Persistent<FunctionTemplate> Bullet::constructor;

void
Bullet::Initialize(Handle<Object> target) {
  HandleScope scope;

  constructor = Persistent<FunctionTemplate>::New(FunctionTemplate::New(Bullet::New));
  constructor->InstanceTemplate()->SetInternalFieldCount(1);
  constructor->SetClassName(String::NewSymbol("Bullet"));

  Local<ObjectTemplate> proto = constructor->PrototypeTemplate();

  target->Set(String::NewSymbol("Bullet"), constructor->GetFunction());
}

Handle<Value>
Bullet::New(const Arguments &args) {
  HandleScope scope;
  
  Bullet* bullet = new Bullet();
  bullet->Wrap(args.This());
  
  return args.This();
}

Bullet::Bullet(): ObjectWrap() {
}

Bullet::~Bullet() {
}
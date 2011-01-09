(function() {
  var Bullet, bullet, collisionDispatcher, dbvtBroadphase, defaultCollisionConfiguration, discreteDynamicsWorld, fps, i, rigidBody, sequentialImpulseConstraintSolver, tick;
  Bullet = require('../index');
  bullet = new Bullet.Bullet;
  console.log('bullet', bullet);
  defaultCollisionConfiguration = new Bullet.DefaultCollisionConfiguration;
  console.log('defaultCollisionConfiguration', defaultCollisionConfiguration);
  collisionDispatcher = new Bullet.CollisionDispatcher(defaultCollisionConfiguration);
  console.log('collisionDispatcher', collisionDispatcher);
  dbvtBroadphase = new Bullet.DbvtBroadphase;
  console.log('dbvtBroadphase', dbvtBroadphase);
  sequentialImpulseConstraintSolver = new Bullet.SequentialImpulseConstraintSolver;
  console.log('sequentialImpulseConstraintSolver', sequentialImpulseConstraintSolver);
  discreteDynamicsWorld = new Bullet.DiscreteDynamicsWorld(collisionDispatcher, dbvtBroadphase, sequentialImpulseConstraintSolver, defaultCollisionConfiguration);
  console.log('discreteDynamicsWorld', discreteDynamicsWorld);
  discreteDynamicsWorld.setGravity();
  for (i = 0; i < 1; i++) {
    rigidBody = new Bullet.RigidBody;
    console.log('rigidBody', rigidBody);
  }
  discreteDynamicsWorld.addRigidBody(rigidBody);
  fps = 0;
  tick = function() {
    fps++;
    discreteDynamicsWorld.stepSimulation();
    return process.nextTick(tick);
  };
  process.nextTick(function() {
    return tick();
  });
  setInterval(function() {
    console.log(fps);
    return fps = 0;
  }, 1000);
}).call(this);

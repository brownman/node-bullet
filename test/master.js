(function() {
  var Bullet, discreteDynamicsWorld, fps, i, rigidBody;
  Bullet = require('../index');
  discreteDynamicsWorld = new Bullet.DiscreteDynamicsWorld;
  console.log('discreteDynamicsWorld', discreteDynamicsWorld);
  for (i = 0; i < 10; i++) {
    rigidBody = new Bullet.RigidBody;
    console.log('rigidBody', rigidBody);
    discreteDynamicsWorld.addRigidBody(rigidBody);
  }
  fps = 0;
  setInterval(function() {
    fps++;
    discreteDynamicsWorld.stepSimulation();
    // gc();
    return;
  }, 0);
  setInterval(function() {
    console.log(fps);
    return fps = 0;
  }, 1000);
}).call(this);

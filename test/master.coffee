Bullet = require '../index.coffee'

bullet = new Bullet.Bullet

console.log bullet

defaultCollisionConfiguration = new Bullet.DefaultCollisionConfiguration

console.log defaultCollisionConfiguration

collisionDispatcher = new Bullet.CollisionDispatcher defaultCollisionConfiguration

console.log collisionDispatcher
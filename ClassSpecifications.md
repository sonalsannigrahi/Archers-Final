### Character-Player---Alice-Sonal-Maelys

**Character class:** each character object has bow,arrow, health and positions attribute

**Player class:** inherits from Character class (click-and-drag function)

**Opponent class:** inherits from Character class (includes the different types of opponents)

### Physics Classes - Saba Nicolas Andre Chris

**Point Mass:** Object with mass and radius, unifrom gravity and collisions fully implemented

**Rectangle:** Object defined by a centre of mass, height, width and angle. Uniform and black hole gravity implemented, inter-rectangle collisions not currently implemented.

For any object, the member function integrate recalculates it's position.

**Black Holes:** Gravity generator defined with a position and a GM attribute (Gravitational constant * mass)

**Gravity:** Takes a black hole or constant gravity and generates (with .addgravityGenerator) a force (In vector form) accordingly


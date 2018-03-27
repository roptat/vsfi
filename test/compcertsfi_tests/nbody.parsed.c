extern void __builtin_debug(int kind, ...);

typedef unsigned int uintptr_t;

extern int dummy$compare(uintptr_t i, uintptr_t j);

extern void dummy$doit(void);

uintptr_t keep[2] = {(uintptr_t) &dummy$compare, (uintptr_t) &dummy$doit, };

extern double sqrt(double __x);

extern int printf(char const * __format, ...);

extern int atoi(char const * __nptr);

struct planet;

struct planet {
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double mass;
};

void advance(int nbodies, struct planet * bodies__1, double dt)
{
  int i;
  int j;
  struct planet * b;
  struct planet * b2;
  double dx;
  double dy;
  double dz;
  double distance;
  double mag;
  struct planet * b__1;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:25");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:27");
  for (__builtin_debug(6, "", 1), i = 0;
       i < nbodies;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1, 3);
    __builtin_debug(1, "#line:nbody.c:28");
    b = &bodies__1[i];
    __builtin_debug(6, "", 1, 3);
    __builtin_debug(1, "#line:nbody.c:29");
    for (__builtin_debug(6, "", 1, 3), j = i + 1;
         j < nbodies;
         __builtin_debug(6, "", 1, 3), j++) {
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:30");
      b2 = &bodies__1[j];
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:31");
      dx = b->x - b2->x;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:32");
      dy = b->y - b2->y;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:33");
      dz = b->z - b2->z;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:34");
      distance = sqrt(dx * dx + dy * dy + dz * dz);
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:35");
      mag = dt / (distance * distance * distance);
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:36");
      b->vx -= dx * b2->mass * mag;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:37");
      b->vy -= dy * b2->mass * mag;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:38");
      b->vz -= dz * b2->mass * mag;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:39");
      b2->vx += dx * b->mass * mag;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:40");
      b2->vy += dy * b->mass * mag;
      __builtin_debug(6, "", 1, 3, 4);
      __builtin_debug(1, "#line:nbody.c:41");
      b2->vz += dz * b->mass * mag;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:44");
  for (__builtin_debug(6, "", 1), i = 0;
       i < nbodies;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:45");
    b__1 = &bodies__1[i];
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:46");
    b__1->x += dt * b__1->vx;
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:47");
    b__1->y += dt * b__1->vy;
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:48");
    b__1->z += dt * b__1->vz;
  }
}

double energy(int nbodies, struct planet * bodies__1)
{
  double e;
  int i;
  int j;
  struct planet * b;
  struct planet * b2;
  double dx;
  double dy;
  double dz;
  double distance;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:54");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:55");
  __builtin_debug(6, "", 1);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:57");
  e = 0.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:58");
  for (__builtin_debug(6, "", 1), i = 0;
       i < nbodies;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:59");
    b = &bodies__1[i];
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:60");
    e += 0.5E0 * b->mass * (b->vx * b->vx + b->vy * b->vy + b->vz * b->vz);
    __builtin_debug(6, "", 1, 2);
    __builtin_debug(1, "#line:nbody.c:61");
    for (__builtin_debug(6, "", 1, 2), j = i + 1;
         j < nbodies;
         __builtin_debug(6, "", 1, 2), j++) {
      __builtin_debug(6, "", 1, 2, 3);
      __builtin_debug(1, "#line:nbody.c:62");
      b2 = &bodies__1[j];
      __builtin_debug(6, "", 1, 2, 3);
      __builtin_debug(1, "#line:nbody.c:63");
      dx = b->x - b2->x;
      __builtin_debug(6, "", 1, 2, 3);
      __builtin_debug(1, "#line:nbody.c:64");
      dy = b->y - b2->y;
      __builtin_debug(6, "", 1, 2, 3);
      __builtin_debug(1, "#line:nbody.c:65");
      dz = b->z - b2->z;
      __builtin_debug(6, "", 1, 2, 3);
      __builtin_debug(1, "#line:nbody.c:66");
      distance = sqrt(dx * dx + dy * dy + dz * dz);
      __builtin_debug(6, "", 1, 2, 3);
      __builtin_debug(1, "#line:nbody.c:67");
      e -= b->mass * b2->mass / distance;
    }
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:70");
  return e;
}

void offset_momentum(int nbodies, struct planet * bodies__1)
{
  double px;
  double py;
  double pz;
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:75");
  px = 0.0E0;
  __builtin_debug(6, "", 1);
  py = 0.0E0;
  __builtin_debug(6, "", 1);
  pz = 0.0E0;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:76");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:77");
  for (__builtin_debug(6, "", 1), i = 0;
       i < nbodies;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:78");
    px += bodies__1[i].vx * bodies__1[i].mass;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:79");
    py += bodies__1[i].vy * bodies__1[i].mass;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:80");
    pz += bodies__1[i].vz * bodies__1[i].mass;
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:82");
  bodies__1[0].vx = -px / (4 * 3.141592653589793E0 * 3.141592653589793E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:83");
  bodies__1[0].vy = -py / (4 * 3.141592653589793E0 * 3.141592653589793E0);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:84");
  bodies__1[0].vz = -pz / (4 * 3.141592653589793E0 * 3.141592653589793E0);
}

struct planet bodies[5] =
  {{0, 0, 0, 0, 0, 0, 1.0E0, },
   {4.84143144246472090E+00, -1.16032004402742839E+00,
    -1.03622044471123109E-01, 1.66007664274403694E-03,
    7.69901118419740425E-03, -6.90460016972063023E-05,
    9.54791938424326609E-04, },
   {8.34336671824457987E+00, 4.12479856412430479E+00,
    -4.03523417114321381E-01, -2.76742510726862411E-03,
    4.99852801234917238E-03, 2.30417297573763929E-05,
    2.85885980666130812E-04, },
   {1.28943695621391310E+01, -1.51111514016986312E+01,
    -2.23307578892655734E-01, 2.96460137564761618E-03,
    2.37847173959480950E-03, -2.96589568540237556E-05,
    4.36624404335156298E-05, },
   {1.53796971148509165E+01, -2.59193146099879641E+01,
    1.79258772950371181E-01, 2.68067772490389322E-03,
    1.62824170038242295E-03, -9.51592254519715870E-05,
    5.15138902046611451E-05, }, };

void setup_bodies(void)
{
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:132");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:133");
  for (__builtin_debug(6, "", 1), i = 0;
       i < 5;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:134");
    bodies[i].vx *= 365.24E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:135");
    bodies[i].vy *= 365.24E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:136");
    bodies[i].vz *= 365.24E0;
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:137");
    bodies[i].mass *= 4 * 3.141592653589793E0 * 3.141592653589793E0;
  }
}

int main(int argc, char * * argv)
{
  int n;
  int i;
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:143");
  n = argc < 2 ? 20000000 : atoi(argv[1]);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:144");
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:146");
  setup_bodies();
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:147");
  offset_momentum(5, bodies);
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:148");
  printf("%.9f\n", energy(5, bodies));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:149");
  for (__builtin_debug(6, "", 1), i = 1;
       i <= n;
       __builtin_debug(6, "", 1), i++) {
    __builtin_debug(6, "", 1);
    __builtin_debug(1, "#line:nbody.c:150");
    advance(5, bodies, 0.01E0);
  }
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:151");
  printf("%.9f\n", energy(5, bodies));
  __builtin_debug(6, "", 1);
  __builtin_debug(1, "#line:nbody.c:152");
  return 0;
  __builtin_debug(6, "");
  return 0;
}



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

void advance(int, struct planet *, double);

double energy(int, struct planet *);

void offset_momentum(int, struct planet *);

void setup_bodies(void);

int main(int, /*signed*/ char **);

static /*signed*/ char const __stringlit_ab19d86789824086001ac0c1f6689fde1[6] = "%.9f\012";

extern unsigned int __compcert_va_int32(void *);

extern unsigned long long __compcert_va_int64(void *);

extern double __compcert_va_float64(void *);

extern void *__compcert_va_composite(void *, unsigned int);

extern long long __i64_dtos(double);

extern unsigned long long __i64_dtou(double);

extern double __i64_stod(long long);

extern double __i64_utod(unsigned long long);

extern float __i64_stof(long long);

extern float __i64_utof(unsigned long long);

extern long long __i64_sdiv(long long, long long);

extern unsigned long long __i64_udiv(unsigned long long, unsigned long long);

extern long long __i64_smod(long long, long long);

extern unsigned long long __i64_umod(unsigned long long, unsigned long long);

extern long long __i64_shl(long long, int);

extern unsigned long long __i64_shr(unsigned long long, int);

extern long long __i64_sar(long long, int);

extern long long __i64_smulh(long long, long long);

extern unsigned long long __i64_umulh(unsigned long long, unsigned long long);

extern void __builtin_debug(int, ...);

extern int dummy$compare(unsigned int, unsigned int);

extern void dummy$doit(void);

 unsigned int keep[2] = { &dummy$compare, &dummy$doit, };

extern double sqrt(double);

extern int printf(/*signed*/ char *, ...);

extern int atoi(/*signed*/ char *);

void advance(int nbodies, struct planet *bodies__1, double dt)
{
  int i;
  int j;
  struct planet *b;
  struct planet *b2;
  double dx;
  double dy;
  double dz;
  double distance;
  double mag;
  struct planet *b__1;
  register double $235;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:25"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:27"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < nbodies)) {
      break;
    }
    builtin debug6 ""(1, 3);
    builtin debug1 "#line:nbody.c:28"();
    b = &*(bodies__1 + i);
    builtin debug6 ""(1, 3);
    builtin debug1 "#line:nbody.c:29"();
    builtin debug6 ""(1, 3);
    j = i + 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1, 3);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j < nbodies)) {
        break;
      }
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:30"();
      b2 = &*(bodies__1 + j);
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:31"();
      dx = (*b).x - (*b2).x;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:32"();
      dy = (*b).y - (*b2).y;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:33"();
      dz = (*b).z - (*b2).z;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:34"();
      $235 = sqrt(dx * dx + dy * dy + dz * dz);
      distance = $235;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:35"();
      mag = dt / (distance * distance * distance);
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:36"();
      (*b).vx = (*b).vx - dx * (*b2).mass * mag;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:37"();
      (*b).vy = (*b).vy - dy * (*b2).mass * mag;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:38"();
      (*b).vz = (*b).vz - dz * (*b2).mass * mag;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:39"();
      (*b2).vx = (*b2).vx + dx * (*b).mass * mag;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:40"();
      (*b2).vy = (*b2).vy + dy * (*b).mass * mag;
      builtin debug6 ""(1, 3, 4);
      builtin debug1 "#line:nbody.c:41"();
      (*b2).vz = (*b2).vz + dz * (*b).mass * mag;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:44"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < nbodies)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:45"();
    b__1 = &*(bodies__1 + i);
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:46"();
    (*b__1).x = (*b__1).x + dt * (*b__1).vx;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:47"();
    (*b__1).y = (*b__1).y + dt * (*b__1).vy;
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:48"();
    (*b__1).z = (*b__1).z + dt * (*b__1).vz;
  }
}

double energy(int nbodies, struct planet *bodies__1)
{
  double e;
  int i;
  int j;
  struct planet *b;
  struct planet *b2;
  double dx;
  double dy;
  double dz;
  double distance;
  register double $235;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:54"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:55"();
  builtin debug6 ""(1);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:57"();
  e = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:58"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < nbodies)) {
      break;
    }
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:59"();
    b = &*(bodies__1 + i);
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:60"();
    e =
      e
        + 0.5 * (*b).mass
            * ((*b).vx * (*b).vx + (*b).vy * (*b).vy + (*b).vz * (*b).vz);
    builtin debug6 ""(1, 2);
    builtin debug1 "#line:nbody.c:61"();
    builtin debug6 ""(1, 2);
    j = i + 1;
    for (;
         1;
         (void)0 /*nothing*/, builtin debug6 ""(1, 2);, (void)0 /*nothing*/, 
         j = j + 1) {
      if (! (j < nbodies)) {
        break;
      }
      builtin debug6 ""(1, 2, 3);
      builtin debug1 "#line:nbody.c:62"();
      b2 = &*(bodies__1 + j);
      builtin debug6 ""(1, 2, 3);
      builtin debug1 "#line:nbody.c:63"();
      dx = (*b).x - (*b2).x;
      builtin debug6 ""(1, 2, 3);
      builtin debug1 "#line:nbody.c:64"();
      dy = (*b).y - (*b2).y;
      builtin debug6 ""(1, 2, 3);
      builtin debug1 "#line:nbody.c:65"();
      dz = (*b).z - (*b2).z;
      builtin debug6 ""(1, 2, 3);
      builtin debug1 "#line:nbody.c:66"();
      $235 = sqrt(dx * dx + dy * dy + dz * dz);
      distance = $235;
      builtin debug6 ""(1, 2, 3);
      builtin debug1 "#line:nbody.c:67"();
      e = e - (*b).mass * (*b2).mass / distance;
    }
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:70"();
  return e;
}

void offset_momentum(int nbodies, struct planet *bodies__1)
{
  double px;
  double py;
  double pz;
  int i;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:75"();
  px = 0;
  builtin debug6 ""(1);
  py = 0;
  builtin debug6 ""(1);
  pz = 0;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:76"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:77"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < nbodies)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:78"();
    px = px + (*(bodies__1 + i)).vx * (*(bodies__1 + i)).mass;
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:79"();
    py = py + (*(bodies__1 + i)).vy * (*(bodies__1 + i)).mass;
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:80"();
    pz = pz + (*(bodies__1 + i)).vz * (*(bodies__1 + i)).mass;
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:82"();
  (*(bodies__1 + 0)).vx =
    -px / (4 * 3.14159265358979312 * 3.14159265358979312);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:83"();
  (*(bodies__1 + 0)).vy =
    -py / (4 * 3.14159265358979312 * 3.14159265358979312);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:84"();
  (*(bodies__1 + 0)).vz =
    -pz / (4 * 3.14159265358979312 * 3.14159265358979312);
}

 struct planet bodies[5] = { 0., 0., 0., 0., 0., 0., 1., 4.84143144246,
  -1.16032004403, -0.103622044471, 0.00166007664274, 0.0076990111842,
  -6.90460016972e-05, 0.000954791938424, 8.34336671824, 4.12479856412,
  -0.403523417114, -0.00276742510727, 0.00499852801235, 2.30417297574e-05,
  0.000285885980666, 12.8943695621, -15.1111514017, -0.223307578893,
  0.00296460137565, 0.00237847173959, -2.9658956854e-05, 4.36624404335e-05,
  15.3796971149, -25.91931461, 0.17925877295, 0.0026806777249,
  0.00162824170038, -9.5159225452e-05, 5.15138902047e-05, };

void setup_bodies(void)
{
  int i;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:132"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:133"();
  builtin debug6 ""(1);
  i = 0;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i < 5)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:134"();
    (*(bodies + i)).vx = (*(bodies + i)).vx * 365.240000000000009;
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:135"();
    (*(bodies + i)).vy = (*(bodies + i)).vy * 365.240000000000009;
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:136"();
    (*(bodies + i)).vz = (*(bodies + i)).vz * 365.240000000000009;
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:137"();
    (*(bodies + i)).mass =
      (*(bodies + i)).mass * (4 * 3.14159265358979312 * 3.14159265358979312);
  }
}

int main(int argc, /*signed*/ char **argv)
{
  int n;
  int i;
  register double $238;
  register double $237;
  register int $236;
  register int $235;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:143"();
  if (argc < 2) {
    $235 = (int) 20000000;
  } else {
    $236 = atoi(*(argv + 1));
    $235 = (int) $236;
  }
  n = $235;
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:144"();
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:146"();
  setup_bodies();
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:147"();
  offset_momentum(5, bodies);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:148"();
  $237 = energy(5, bodies);
  printf(__stringlit_ab19d86789824086001ac0c1f6689fde1, $237);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:149"();
  builtin debug6 ""(1);
  i = 1;
  for (;
       1;
       (void)0 /*nothing*/, builtin debug6 ""(1);, (void)0 /*nothing*/, 
       i = i + 1) {
    if (! (i <= n)) {
      break;
    }
    builtin debug6 ""(1);
    builtin debug1 "#line:nbody.c:150"();
    advance(5, bodies, 0.0100000000000000002);
  }
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:151"();
  $238 = energy(5, bodies);
  printf(__stringlit_ab19d86789824086001ac0c1f6689fde1, $238);
  builtin debug6 ""(1);
  builtin debug1 "#line:nbody.c:152"();
  return 0;
  builtin debug6 ""();
  return 0;
}



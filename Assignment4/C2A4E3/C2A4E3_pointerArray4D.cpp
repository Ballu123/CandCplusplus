// Name:Balram Panwar
// Email id: balram.panwar@gmail.com
// Name of the file: C2A4E3_pointerArray4D.cpp
// Win7
// Microsoft Visual Studio
//
// created the 4-dimensional pointer array by using the DIMO0, DIM1, DIM2, DIM3 
// which must have 9 values of 2, 3, 4, and 5, respectively. 
extern const int DIM0 = 2;
extern const int DIM1 = 3;
extern const int DIM2 = 4;
extern const int DIM3 = 5;

static float xa[DIM3], xb[DIM3], xc[DIM3], xd[DIM3], xe[DIM3], xf[DIM3], xg[DIM3], xh[DIM3];
static float xi[DIM3], xj[DIM3], xk[DIM3], xl[DIM3], xm[DIM3], xn[DIM3], xo[DIM3], xp[DIM3];
static float xq[DIM3], xr[DIM3], xs[DIM3], xt[DIM3], xu[DIM3], xv[DIM3], xw[DIM3], xx[DIM3];

static float *yr[DIM2] = {xa, xb, xc, xd}, *ys[DIM2] = {xe, xf, xg, xh};
static float *yt[DIM2] = {xi, xj, xk, xl}, *yu[DIM2] = {xm, xn, xo, xp};
static float *yv[DIM2] = {xq, xr, xs, xt}, *yw[DIM2] = {xu, xv, xw, xx};

static float **z1[DIM1] = {yr, ys, yt};
static float **z2[DIM1] = {yu, yv, yw};

float ***pointerArray4D[DIM0] = {z1, z2};

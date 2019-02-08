
#include <stdio.h>

#include <stdlib.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
 #endif
 #ifndef min
  #define min(a,b) (((a) < (b)) ? (a) : (b))
  #endif

int MOD(int A,int B){
  return A%B;
}
double RVEC[1001];
int IVEC = 0;
const long MODCNS = 1000000000;
int NVEC = 1000;

extern double DRAND48(double dummy){
  if (IVEC ==0 || IVEC>=NVEC){
    RM48(NVEC);
    IVEC = 1;
  }else{
    IVEC+=1;
  }
  return RVEC[IVEC];
}

void RM48(double LENV){
  double U[98],C,HALF,UNI;
  int KALLED,NTOTIN,NTOT2N,I,J,K,L,M,NOW,IJ,KL;

   int  I97, J97,IJKLIN;
   double T,S;
  static double CD, CM, TWOM24,TWOM49 ,ONE, ZERO;
  static int IJKL=0,NTOT=-1, NTOT2=0;
  if(NTOT>=0) goto L50;
  IJKL = 54217137;
  NTOT = 0;
  NTOT2 = 0;
  KALLED = 0;

  IJ = IJKL/30082;
  KL = IJKL - 30082*IJ;
  I = (IJ/177)% 177 + 2;
  J = IJ%177     + 2;
  K = (KL/169)% 178 + 1;
  L =KL% 169;
  ONE = 1.;
  HALF = 0.5;
  ZERO = 0.;
  for(int II= 1;II<= 97;++II){
  S = 0.;
  T = HALF;
  for(int JJ= 1;JJ<= 48;++JJ){
     M =(((I*J)%179)*K)% 179;
     I = J;
     J = K;
     K = M;
     L = (53*L+1)% 169;
     if ((L*M)%64 >= 32)  S = S+T;
     T = HALF*T;
   }
 U[II] = S;
}
TWOM49 = T;
TWOM24 = ONE;
for(int I24= 1;I24<= 24;++I24){
 TWOM24 = HALF*TWOM24;
}
C  =   362436.*TWOM24;
CD =  7654321.*TWOM24;
CM = 16777213.*TWOM24;
I97 = 97;
J97 = 33;

for(int LOOP2 = 1;LOOP2<=NTOT2+1;++LOOP2){
  NOW = MODCNS;
  if (LOOP2 == NTOT2+1)  NOW=NTOT;
  if (NOW > 0)  {
      for(int IDUM = 1;IDUM<= NTOT;++IDUM){
      UNI = U[I97]-U[J97];
      if (UNI < ZERO)  UNI=UNI+ONE;
      U[I97] = UNI;
      I97 = I97-1;
      if (I97== 0)  I97=97;
      J97 = J97-1;
      if (J97 == 0)  J97=97;
      C = C - CD;
      if (C < ZERO)  C=C+CM;
      }
  }
}

  if (KALLED == 1)  return;
  L50:
  for(IVEC= 1;IVEC<=LENV;++IVEC){
  UNI = U[I97]-U[J97];
  if (UNI < ZERO)  UNI=UNI+ONE;
  U[I97] = UNI;
  I97 = I97-1;
  if (I97 == 0)  I97=97;
  J97 = J97-1;
  if (J97== 0)  J97=97;
  C = C - CD;
  if (C < ZERO)  C=C+CM;
  UNI = UNI-C;
  if (UNI < ZERO) UNI=UNI+ONE;
  RVEC[IVEC] = UNI;
//             Replace exact zeros by 2**-49
     if (UNI == ZERO){
        RVEC[IVEC] = TWOM49;
     }
  }
  NTOT = NTOT + LENV;
     if (NTOT >= MODCNS) {
     NTOT2 = NTOT2 + 1;
     NTOT = NTOT - MODCNS;
   }

   return;
}
int main(){
  RM48(1000);
  for (int i=0;i<998;++i)
  DRAND48(0.666);
  printf("%f\n",DRAND48(0.666));

  printf("%f\n",DRAND48(0.666));

  for(int i=0;i<10;++i)
  printf("%f\n",DRAND48(0.666));
  return 0;
}

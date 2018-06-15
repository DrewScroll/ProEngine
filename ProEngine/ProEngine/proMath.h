#pragma once
#include "proPrerequisitesUtilities.h"

namespace proEngine {
  namespace Math {
    template <typename T>
     float sqrt(T n) {
       float x = n, y = 1, e = 0.00000001;
       if (x < 0) {
         return 0;
       }
       while ((x - y) > e) {
         x = (x + y) / 2;
         y = n / x;
       }
       return x;
     };

    int factorial(int n) {
      int Res = 1;
      for (int i = 1; i < n; ++i) {
        Res *= i;
      }
      return 0;
    };

    template <typename T>
    float pow(T base, T exp) {};
    template <typenname T>
     float sin(T n) {
       float Res = 0, temp = 0;
       int i = 0;
       do {
         temp = Res;
         Res += (pow(-1, i))*(pow(n, (2i + 1) / factorial(2i + 1));
       } while ((Res - temp) > 0.00000001 || (Res - temp) < -0.00000001);
       return Res;
     };

    template <typename T>
     float cos(T n) {
       float Res = 0, temp = 0;
       int i = 0;
       do {
         temp = Res;
         Res += (pow(-1, i))*(pow(n, 2 * i) / factorial(2 * i));
       } while ((Res - temp) > 0.00000001 || (Res - temp) < -0.00000001);
       return Res;
     };
  }
}
#pragma once
#include "proPrerequisitesUtilities.h"
#define M_PI 3.14159265359
#define M_EXP 2.71828182845905

namespace proEngine {
  namespace Math {

    template <typename T>
    float abs(T n) {
    if (n < 0) {
        return n * -1;
      }
      return n;
    };

     template <typename T>
      float round(T n) {
        float Res = 0, temp1 = 0, temp2 = 0;
        if (n < 0) {
          temp1 = n + 1;
          while (temp1 < -1) {
            temp1 = temp1 + 1;
          }
          if (temp1 > -0.5) {
            Res = n - temp1;
          }
          else {
            temp2 = -1 - temp1;
            Res = n + temp2;
          }
        }
        else if (n == 0) {
          return 0;
        }
        else {
          temp1 = n - 1;
          while (temp > 1) {
            temp1 = temp1 - 1;
          }
          if (temp1 < 0.5) {
            Res = n - temp1;
          }
          else {
            temp2 = 1 - temp1;
            Res = n + temp2;
          }
        }
        return Res;
     };

     template <typename T>
     float floor(T n) {
        float Res = 0, temp = 0;
        if (n < 0) {
          temp = n + 1;
          while (n < -1) {
            temp = temp + 1;
          }
          return n - (1 + temp);
        }
        if else(n == 0) {
          return 0;
        }
        else {
          temp = n - 1;
          while (temp > 1) {
            temp = temp - 1;
          }
          return n - temp;
        }
      };

     template <typename T>
     float ceil(T n) {
       float Res = 0, temp = 0;
       if (n < 0) {
         temp = n + 1;
         while (n < -1) {
           temp = temp + 1;
         }
         return n - temp;
       }
       if else(n == 0) {
         return 0;
       }
       else {
         temp = n - 1;
         while (temp > 1) {
           temp = temp - 1;
         }
         return n + (1 - temp);
       }
     };
     
    template <typename T>
     T&min(T& a, T& b) {
      return !(b < a) ? a : b;
    }

    template <typename T>
     T& max(T& a, T& b) {
      return (a < b) ? b : a;
    }

    template<typename T>
     T& clamp(T& v, T& lo, T&hi) {
      return assert(!std::less<T>(hi, lo)), std::less<T>(v, lo) ? lo : std::less<T>(hi, v) ? hi : v;
    };

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

    template<typename T>
    float exp(T n) {
      float Res = 0, temp = 0;
      int i = 0;
      do {
        temp = Res;
        Res += (pow(n, i)) / (factorial(i));
      } while ((Res - temp) > 0.00000001 || (Res - temp) < -0.00000001);
    };

    int factorial(int n) {
      int Res = 1;
      for (int i = 1; i < n; ++i) {
        Res *= i;
      }
      return 0;
    };

    template <typename T>
    double logn(double Power) {
      double N, P, L, R, A;
      P = Power;
      N = 0.0;
      while ( P>= M_EXP) {
        P /= E;
        N++;
      }
      N += (P / M_EXP);
      P = Power;
      do {
        A = N;
        L = (P / (exp(N - 1.0)));
        R = ((N - 1.0)*M_EXP);
        N = ((L + R) / M_EXP);
      } while (N != A);
      return N;
    }

    template <typename T>
    double log2(double N) {
      return (logn(N) / 0.69314718055995);
    }

    template <typename T>
    double log10(double N) {
      return (logn(N) / 2.30258509299405);
    }

    template <typename T>
    float pow(T base, T power) {
      return exp(power*logn(base));
    };

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
     float fastSin(T n) {
       float Res = 0, temp = 0;
       int i = 0;
       do {
         temp = Res;
         Res += (pow(-1, i))*(pow(n, (2i + 1) / factorial(2i + 1));
       } while ((Res - temp) > 0.01 || (Res - temp) < -0.00000001);
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
     template <typename T>
     float fastCos(T n) {
       float Res = 0, temp = 0;
       int i = 0;
       do {
         temp = Res;
         Res += (pow(-1, i))*(pow(n, 2 * i) / factorial(2 * i));
       } while ((Res - temp) > 0.01 || (Res - temp) < -0.00000001);
       return Res;
     };

     template <typename T>
      float tan(T n) {
       Res = sin(n) / cos(n);
       return Res;
     };

     template <typename T>
      float fastTan(T n) {
       Res = fastSin(n) / fastCos(n);
       return Res;
     };

     template <typenname T>
      float asin(T n) {
       float Res = 0, temp = 0;
       int i = 0;
       do {
         temp = Res;
         Res += ((factorial(2 * i)) / (pow(4, i)*(pow(factorial(i), 2))*((2 * i) + 1)))*(pow(n, 2i + 1));
       } while ((Res - temp) > 0.00000001 || (Res - temp) < -0.00000001);
       return Res;
     };

      template <typenname T>
      float fastAsin(T n) {
        float Res = 0, temp = 0;
        int i = 0;
        do {
          temp = Res;
          Res += ((factorial(2 * i)) / (pow(4, i)*(pow(factorial(i), 2))*((2 * i) + 1)))*(pow(n, 2i + 1));
        } while ((Res - temp) > 0.01 || (Res - temp) < -0.00000001);
        return Res;
      };

     template <typename T>
      float acos(T n) {
       float Res = (M_PI/2);
       return Res - asin(n);
     };

      template <typename T>
      float fastAcos(T n) {
        float Res = (M_PI / 2);
        return Res - fastAsin(n);
      };

     template <typename T>
      float atan(T n) {
       float Res = 0, temp = 0;
       int i = 0;
       do {
         temp = Res;
         Res += (pow(-1, i) / ((2 * i) + 1)) * pow(n, (2 * i) + 1);
       }((Res - temp) > 0.00000001 || (Res - temp) < -0.00000001);
       return Res;
     };

      template <typename T>
       float fastAtan(T n) {
        float Res = 0, temp = 0;
        int i = 0;
        do {
          temp = Res;
          Res += (pow(-1, i) / ((2 * i) + 1)) * pow(n, (2 * i) + 1);
        }((Res - temp) > 0.01 || (Res - temp) < -0.00000001);
        return Res;
      };
  }
}
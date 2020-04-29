#include <iostream>
#include <string>
#include <stdbool.h>
#include <complex>
#include "solver.hpp"

using namespace std;
namespace solver{

    RealVariable operator+(const RealVariable r,const double d) { return r.x+d;}
    RealVariable operator-(const RealVariable r,const double d) {return r.x-d;}
    RealVariable operator*(const RealVariable r,const double d) {return r.x*d;}
    RealVariable operator/(const RealVariable r,const double d) {
        if(d==0)throw std::runtime_error(std::string("Exception - Divide with zero"));
        return r.x/d;
    }
    RealVariable operator^(const RealVariable r,const double d) {
        double sum=1;
        for(int i=0;i<(int)d;i++){
            sum*=r.x;
        }
        return sum;
    }
    //right
     RealVariable operator-(const double d,const RealVariable r) {
        return d-r.x;
    }
     RealVariable operator/(const double d,const RealVariable r) {
         if(r.x==0)throw std::runtime_error(std::string("Exception - Divide with zero"));
         return d/r.x;
     }

     RealVariable operator^(const double d,const RealVariable r) {
         double sum=1;
         for(int i=0;i<(int)d;i++){
             sum*=r.x;
         }
         return sum;
    }
    //both
     RealVariable operator+(const RealVariable l,const RealVariable r) {
        return l.x+r.x;
    }
     RealVariable operator-(const RealVariable l,const RealVariable r) {
        return l.x-r.x;
    }
     RealVariable operator*(const RealVariable l,const RealVariable r) {
        return l.x*r.x;
    }
     RealVariable operator/(const RealVariable l,const RealVariable r) {
        return 0;
    }
     RealVariable operator^(const RealVariable l,const RealVariable r) { return 0;  }
    //relevant for solve function
     RealVariable operator== (const double d,const RealVariable r){ return 0;}
     RealVariable operator== (const RealVariable l,const RealVariable r){ return 0;}

    //left
     ComplexVariable operator+(const ComplexVariable r,const complex<double> d){ return d;}
     ComplexVariable operator-(const ComplexVariable r,const complex<double> d){ return d;}
     ComplexVariable operator*(const ComplexVariable r,const complex<double> d){ return d;}
     ComplexVariable operator/(const ComplexVariable r,const complex<double> d){ return d;;}
     ComplexVariable operator^(const ComplexVariable r,const complex<double> d){ return d;}
    //right
     ComplexVariable operator+(const complex<double> d,const ComplexVariable r){ return d;}
     ComplexVariable operator-(const complex<double> d,const ComplexVariable r){return d;}
     ComplexVariable operator*(const complex<double> d,const ComplexVariable r){return d;}
     ComplexVariable operator/(const complex<double> r,const ComplexVariable d){return d;}
     ComplexVariable operator^(const complex<double> r,const ComplexVariable d){return d;}
    //both
     ComplexVariable operator+(const ComplexVariable l,const ComplexVariable r){return l;}
     ComplexVariable operator-(const ComplexVariable l,const ComplexVariable r){return l;}
     ComplexVariable operator*(const ComplexVariable l,const ComplexVariable r){return l;}
     ComplexVariable operator/(const ComplexVariable l,const ComplexVariable r){return l;}
     ComplexVariable operator^(const ComplexVariable l,const ComplexVariable r){return l;}
    //relevant for solve function


     ComplexVariable operator== (const complex<double> d,const ComplexVariable r){return r;}
     ComplexVariable operator== (const ComplexVariable l,const complex<double> d){return l;}
     ComplexVariable operator== (const ComplexVariable l,const ComplexVariable r){return l;}


   double solve(const RealVariable e){return 1.0;}
    complex<double> solve(const ComplexVariable e){return NULL;}
};

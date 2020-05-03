#include <iostream>
#include <string>
#include <stdbool.h>
#include <complex>
#include "solver.hpp"

using namespace std;
namespace solver{           // https://www.programiz.com/cpp-programming/examples/quadratic-roots

    RealVariable operator+(const RealVariable& r,const double d) {
        return RealVariable(r.a,r.b,r.c+d);
    }
    RealVariable operator-(const RealVariable& r,const double d) {
        return RealVariable(r.a,r.b,r.c-d);
    }
    RealVariable operator*(const RealVariable& r,const double d) {return RealVariable(r.a*d,r.b*d,r.c*d);}
    RealVariable operator/(const RealVariable& r,const double d) {
        if(d==0)throw std::runtime_error(std::string("Exception - Divide with zero"));
        return RealVariable(r.a/d,r.b/d,r.c/d);
    }
    RealVariable operator^(const RealVariable& r,const double d) {
        if(d==2){
            return r*r;
        }else if(d==1){
            return r;
        }else if(d==0){
            return RealVariable(0,0,1);
        }
        else{
            throw std::runtime_error(std::string("Exception - power greater than 2"));
        }
    }
    //right
    RealVariable operator-(const double d,const RealVariable& r) {
        return RealVariable(r.a,r.b,r.c-d);
    }
//    RealVariable operator/(const double d,const RealVariable r) {
//        if(r.a==0 || r.b==0 || r.c==0)throw std::runtime_error(std::string("Exception - Divide with zero"));
//        return RealVariable(d/r.a,d/r.b,d/r.c);
  //  }

//    RealVariable operator^(const double d,const RealVariable r) {
//        return (d^r.a)*(d^r.b);
//    }
    RealVariable operator== (const double d,const RealVariable& r){
        if(d==0 && r.a==0 && r.b==0 && r.c==0)return RealVariable (r.a, r.b, r.c - d);;
    }
    RealVariable operator== (const RealVariable& l,const RealVariable& r){
        return RealVariable (l.a-r.a, l.b-r.b, l.c-r.c );
    }
    //both
    RealVariable operator+(const RealVariable& l,const RealVariable& r) { //assuming they are from the same expo
        return RealVariable(l.a+r.a,l.b+r.b,l.c+r.c);
    }
    RealVariable operator-(const RealVariable& l,const RealVariable& r) { //assuming they are from the same expo
        return RealVariable(l.a-r.a,l.b-r.b,l.c-r.c);
    }
    RealVariable operator*(const RealVariable& l,const RealVariable& r) { //assuming they are from the same expo
        if(l.a!=0 && (r.a!=0  || r.b!=0) )throw std::runtime_error(std::string("Exception - Expo is too high"));
        if(l.b!=0 && r.a!=0 )throw std::runtime_error(std::string("Exception - Expo is too high"));
        return RealVariable(l.a*r.a+l.b*r.b+l.c*r.c,l.b*r.c+l.c*r.b,l.c*r.c);
    }
    RealVariable operator/(const RealVariable& l,const RealVariable& r) {
        if(r.a==0 && r.b==0 && r.c==0) throw std::runtime_error(std::string("Exception - Dividing with zero"));
        if(l.a==r.a && l.b==r.b && l.c==r.c) return RealVariable(0, 0, 1);
        if(r.a == 0 && r.b == 0) return RealVariable(l.a/r.c,l.b/r.c,l.c/r.c);
        throw std::runtime_error(std::string("Exception - Division is not possible"));
    }
//    RealVariable operator^(const RealVariable l,const RealVariable r) { return 0;  }
    double solve(const RealVariable& e){
        double discriminant;
        if(e.a == 0) {          // The equation is linear
            if ((e.b == 0) && (e.c != 0))throw std::runtime_error(std::string("Exception - not an equation"));
            return -e.c/e.b;
        }
        discriminant = e.b*e.b - 4*e.a*e.c;
        if(discriminant>=0)return  (e.b + sqrt(discriminant)) / (2*e.a);

        throw std::runtime_error(std::string("Exception - equation is imaginary"));

    }

    //left
    ComplexVariable operator+(const ComplexVariable& r,const complex<double> d){ return d;}
    ComplexVariable operator-(const ComplexVariable& r,const complex<double> d){ return d;}
    ComplexVariable operator*(const ComplexVariable& r,const complex<double> d){ return d;}
    ComplexVariable operator/(const ComplexVariable& r,const complex<double> d){ return d;;}
    ComplexVariable operator^(const ComplexVariable& r,const complex<double> d){ return d;}
    //right
    ComplexVariable operator+(const complex<double> d,const ComplexVariable& r){ return d;}
    ComplexVariable operator-(const complex<double> d,const ComplexVariable& r){return d;}
    ComplexVariable operator*(const complex<double> d,const ComplexVariable& r){return d;}
    ComplexVariable operator/(const complex<double> r,const ComplexVariable& d){return d;}
    ComplexVariable operator^(const complex<double> r,const ComplexVariable& d){return d;}
    //both
    ComplexVariable operator+(const ComplexVariable& l,const ComplexVariable& r){return l;}
    ComplexVariable operator-(const ComplexVariable& l,const ComplexVariable& r){return l;}
    ComplexVariable operator*(const ComplexVariable& l,const ComplexVariable& r){return l;}
    ComplexVariable operator/(const ComplexVariable& l,const ComplexVariable& r){return l;}
    ComplexVariable operator^(const ComplexVariable& l,const ComplexVariable& r){return l;}
    //relevant for solve function


    ComplexVariable operator== (const complex<double> d,const ComplexVariable& r){return r;}
    ComplexVariable operator== (const ComplexVariable& l,const complex<double> d){return l;}
    ComplexVariable operator== (const ComplexVariable& l,const ComplexVariable& r){return l;}



    complex<double> solve(const ComplexVariable& e){return NULL;}
};
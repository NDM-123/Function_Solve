

#ifndef SOLVER_A_MASTER_SOLVER_HPP
#define SOLVER_A_MASTER_SOLVER_HPP

#pragma once
#include <iostream>
#include <string>
#include <stdbool.h>
#include <complex>

using namespace std;
namespace solver{



    class RealVariable{
        double x;
    public:
    RealVariable():x(0){};

    RealVariable(double num){
        this->x=num;
    }
        const double & getx() const { return this->x;}
        //left
        friend RealVariable operator+(const RealVariable r,const double d);
        friend RealVariable operator-(const RealVariable r,const double d);
        friend RealVariable operator*(const RealVariable r,const double d);
        friend RealVariable operator/(const RealVariable r,const double d);
        friend RealVariable operator^(const RealVariable r,const double d);
        //right
        friend RealVariable operator-(const double d,const RealVariable r);
        friend RealVariable operator/(const double d,const RealVariable r);
        friend RealVariable operator^(const double d,const RealVariable r);
        //both
        friend RealVariable operator+(const RealVariable l,const RealVariable r);
        friend RealVariable operator-(const RealVariable l,const RealVariable r);
        friend RealVariable operator*(const RealVariable l,const RealVariable r);
        friend RealVariable operator/(const RealVariable l,const RealVariable r);
        friend RealVariable operator^(const RealVariable l,const RealVariable r);
        //relevant for solve function
        friend RealVariable operator== (const double d,const RealVariable r);
        friend RealVariable operator== (const RealVariable l,const RealVariable r);


    };
    class ComplexVariable{
        complex<double> x;
    public:
        ComplexVariable():x(0){};

        ComplexVariable(complex<double> num){
            this->x=num;
        }
        const complex<double>& getx() const { return this->x;}

        //left
        friend ComplexVariable operator+(const ComplexVariable r,const complex<double> d);
        friend ComplexVariable operator-(const ComplexVariable r,const complex<double> d);
        friend ComplexVariable operator*(const ComplexVariable r,const complex<double> d);
        friend ComplexVariable operator/(const ComplexVariable r,const complex<double> d);
        friend ComplexVariable operator^(const ComplexVariable r,const complex<double> d);
        //right
        friend ComplexVariable operator+(const complex<double> d,const ComplexVariable r);
        friend ComplexVariable operator-(const complex<double> d,const ComplexVariable r);
        friend ComplexVariable operator*(const complex<double> d,const ComplexVariable r);
        friend ComplexVariable operator/(const complex<double> r,const ComplexVariable d);
        friend ComplexVariable operator^(const complex<double> r,const ComplexVariable d);
        //both
        friend ComplexVariable operator+(const ComplexVariable l,const ComplexVariable r);
        friend ComplexVariable operator-(const ComplexVariable l,const ComplexVariable r);
        friend ComplexVariable operator*(const ComplexVariable l,const ComplexVariable r);
        friend ComplexVariable operator/(const ComplexVariable l,const ComplexVariable r);
        friend ComplexVariable operator^(const ComplexVariable l,const ComplexVariable r);
        //relevant for solve function
        friend ComplexVariable operator== (const complex<double> d,const ComplexVariable r);
        friend ComplexVariable operator== (const ComplexVariable l,const complex<double> d);
        friend ComplexVariable operator== (const ComplexVariable l,const ComplexVariable r);


    };

    //solve the equation with a function
    double solve(const RealVariable e);
    complex<double> solve(const ComplexVariable e);

};



#endif

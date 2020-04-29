#include "doctest.h"

#include <iostream>

#include <complex>

#include "solver.hpp"



using namespace std;

using solver::solve, solver::RealVariable, solver::ComplexVariable;



 int fact(int n,int m) {

  return n||m ? true : false; 

}





TEST_CASE("RealVariable - linear equations") {

    RealVariable x;

            CHECK(solve(2 == 2) == 0);

            CHECK(solve(2*x == 10) ==5);

            CHECK(solve(2*x-4 == 10) ==7);

            CHECK(solve(2*x-10 == 10) ==0);

            CHECK(solve(2*x-4 == 4) ==0);

            CHECK(solve(10*x == 10) ==1);

            CHECK(solve(2*x-4+4 == 10) ==5);

            CHECK(solve(2*x-1*x == 10) ==10);

            CHECK(solve(2*x-2 == 0) ==1);

            CHECK(solve(2*x+4*x+4*x == 10) ==1);

            CHECK(solve(2*x-2*x == 0) ==1);     //11



}

TEST_CASE("RealVariable - polynomial equations") {

    RealVariable x;

           CHECK(solve( (x^2) == 16)==4);     //second solution

           CHECK(solve((x^3) == 8)==2 );

            CHECK(solve((x^4) == 16)==2 );      //second solution    

            CHECK(solve((x^3) == 27)==3 );

           CHECK(solve((x^2) == 64)==8 );       //second solution

           CHECK(solve(  ( ( ( ((x^2)+(x^2)) == 128)==8))));    //second solution

            CHECK(solve((x^3)+(x^3) == 16)==2  );

           CHECK(solve((x^3)+(x^3) == -16)==-2 );

            CHECK(solve((x^2)-(x^2) == 0)==0 );

            CHECK(solve(2*(x^2)-(x^2)-1 == 0)==1 );         //21



}

TEST_CASE("RealVariable - throw cases") {

    RealVariable x;

            CHECK_THROWS(solve(2 == 1));

            CHECK_THROWS(solve((x^2) ==-1 ) );

            CHECK_THROWS(solve(2*x/x == 10) );

            CHECK_THROWS(solve((x*2-10)/x == 10) );

            CHECK_THROWS(solve(2*x/x == 3) );

            CHECK_THROWS(solve(10*x+2*(x^2) == 10) );

            CHECK_THROWS(solve(2-4+4 == 10) );

            CHECK_THROWS(solve((2^2) == 10) );

            CHECK_THROWS(solve(2*x-2 == 2) );

            CHECK_THROWS(solve(2*x == 10) ==1);

            CHECK_THROWS(solve(-1*(x^2)+2*x == -15)); //32

}

TEST_CASE("ComplexVariable - linear equations") {

    ComplexVariable y;

            CHECK(fact(solve(-1*y^2+4*y == 15) ==complex(2.0,sqrt(11))  ,solve(-1*y^2+4*y == 15) ==complex(2.0,-sqrt(11)) ));

            CHECK(fact(solve(-1*y^2+6*y == 15) ==complex(3.0,sqrt(6))  ,solve(-1*y^2+6*y == 15) ==complex(3.0,-sqrt(6))) );

            CHECK(fact(solve(-1*y^2+8*y == 15) ==complex(5.0,0.0)  ,solve(-1*y^2+8*y == 15) ==complex(3.0,0.0)) );

            CHECK(fact(solve(-1*y^2+10*y == 15) == complex(5.0,sqrt(10)) ,solve(-1*y^2+10*y == 15) ==complex(5.0,sqrt(10)))) ;

            CHECK(fact(solve(-1*y^2+14*y == 15) ==complex(7.0,sqrt(34)) ,solve(-1*y^2+14*y == 15) ==complex(7.0,-sqrt(34))) );

            CHECK(fact(solve(-1*y^2+16*y == 15) == complex(1.0,0.0) , solve(-1*y^2+16*y == 15) ==complex(8.0,0.0)));

            CHECK(fact(solve(-1*y^2+2*y == 15) == complex(1.0,sqrt(14)) , solve(-1*y^2+2*y == 15) == complex(1.0,-sqrt(14))));

            CHECK(solve(2*y-4 == 10) == complex(7.0,0.0));

            CHECK(solve(2 == 2) == complex(0.0,0.0) );/////deafult

            CHECK(solve(2*y == 10)==complex(5.0,0.0)) ;

            CHECK(solve(2*y-2*y == 0) == complex(0.0,0.0)) ;

            CHECK(solve(2*y-2 == 0) == complex(1.0,0.0));

            //not sure about the i

            CHECK(solve(y+5 == 10) == complex(0.0,2.0));

            CHECK(solve(y+7i == 2*y+3i) == complex(0.0,4.0));

           

            CHECK(solve(y+5i+3 == 2*y+3i) == complex(3.0,2.0));

            CHECK(solve(y+5i == 3*y+3i) ==complex(0.0,1.0));       //48



   CHECK(solve(2*y-4 == 10) == complex(7.0,0.0));

    CHECK(fact(solve((y^2) == 16) == complex(4.0,0.0) , solve((y^2) == 16) == complex(-4.0,0.0)));

    CHECK(fact(solve((y^2) == -16) == complex(0.0,4.0) , solve((y^2) == -16) == complex(0.0,-4.0)));

    CHECK(fact(solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == complex(4.0,0.0) , solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y) == complex(-4.0,0.0)));

    CHECK(solve(y+5i == 2*y+3i) == complex(0.0,2.0));





}

TEST_CASE("ComplexVariable - polynomial equations") {



        ComplexVariable z;

     

          CHECK(solve((z^2) +2*z +1== 1) == complex(0.0,0.0) );



       CHECK(fact(solve((z^2) +9 == 0) == complex(0.0,3.0) , solve((z^2) +9 == 0) == complex(0.0,-3.0)));

CHECK(solve((z^5) +1 == 0) == complex(1.0,0.0));

           CHECK(fact(solve((z^2) +4*z +7 == 0) == complex(2.0,sqrt(3)) , solve((z^2) +4*z +7 == 0) == complex(2.0,-sqrt(3))));

           CHECK(fact(solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,sqrt(6)/5) , solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,-sqrt(6)/5)));



  CHECK(fact(solve(2*(z^2) +12*z +9 == 0) == complex(-1.5*(sqrt(2)+2),0.0), solve(2*(z^2) +12*z +9  == 0) == complex(-1.5*(sqrt(2)+2),0.0)));

            CHECK(solve(0*(z^2) +3*z +27 == 0) == complex(-9.0,0.0) );

CHECK(fact(solve((z^2)/2 +z +14 == 0) == complex(-1.0,3*sqrt(3)) ,solve((z^2)/2 +z +14 == 0) == complex(-1.0,-3*sqrt(3))));

          CHECK(fact(solve((z^2)*8 +56*z +16 == 0) == complex(-(7+sqrt(41))/2,0.0) , solve((z^2)*8 +56*z +16 == 0) == complex((-7+sqrt(41))/2,0.0)));

          CHECK(fact(solve(2*(z^2) +4*z +9== 8+2/2) == complex(0.0,0.0) , solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));

           CHECK(fact(solve(6*(z^2)/2 +2*z*3 +90== 90) == complex(0.0,0.0) , solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));



}

TEST_CASE("ComplexVariable - throw cases") {

    ComplexVariable y;

            CHECK_THROWS(solve(3*y/0 == 0));

            CHECK_THROWS(solve(2*y-2*y+8 == 0));

            CHECK_THROWS(solve(4*(y^6)+8 == 0));

            CHECK_THROWS(solve(4*y*9+(y^3)+8==9));

            CHECK_THROWS(solve(y/0+8.0 == 0));

            CHECK_THROWS(solve(12/0*y == y*4));

            CHECK_THROWS(solve((y^2)/0 == 2*(y^4)));

            CHECK_THROWS(solve(4*y == 6*y));

            CHECK_THROWS(solve((y^2)+12 == 2*(y^2)));

            CHECK_THROWS(solve(4*y-3*y+1 == 0));   

  

    CHECK_THROWS(solve(4*y/0+12 == 0));

    CHECK_THROWS(solve(4*y-4*y+12 == 0));

    CHECK_THROWS(solve(4*(y^6)+12 == 0));

    CHECK_THROWS(solve(4*y*9+(y^3)+12==9));

    CHECK_THROWS(solve(4*y+y/0+12.0 == 0));

    CHECK_THROWS(solve(4*y+12 == y*4));

    CHECK_THROWS(solve(4*(y^2)+12 == 8*(y^2)/2));

    CHECK_THROWS(solve(4*y+0.0 == 4*y+9));

    CHECK_THROWS(solve(4*(y^4)*7+12 == 28*(y^2)));

    CHECK_THROWS(solve(4*y-3*y/0 == 0));                        //84





}

TEST_CASE("RealVariable - extra tests") {

    RealVariable x;

            CHECK(solve(x+5 == 7) == 2);

            CHECK(solve(5+x == 10) ==5);

            CHECK(solve(2*x+3*x == 20) ==4);

            CHECK(solve(2*x-3*x == -1) ==1);

            CHECK(solve(2*x-4*x == 4) ==-2);

            CHECK(solve(5*x == 10) == 2);

            CHECK(solve(2*x-2 == 0) ==-2);

            CHECK(solve(2*x-1*x == 15) ==15);

            CHECK(solve(2*x+2*x-2*x-2*x == 0) ==0);

            CHECK(solve(2*x+4*x+4*x == 10) ==1);

            CHECK(solve(x-x == 0) ==0); 

            CHECK(solve(x == x) == 0);

            CHECK(solve(5*x == -5) ==-1);

            CHECK(solve(x-4 == 10) ==14);

            CHECK(solve(5*x-10 == 10) ==0);

            CHECK(solve(x*x == (x^2)) ==0);                     //100

            

}




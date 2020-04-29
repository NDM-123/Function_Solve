#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

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
            //CHECK(solve(x^2 == 16)==4 ||solve(x^2 == 16)== -4 );
            //CHECK(solve(x^3 == 8)==2 );
            //CHECK(solve(x^2 == -8)==-2 );
            //CHECK(solve(x^3 == 27)==3 );
            //CHECK(solve(x^2 == 64)==8 ||solve(x^2 == 64)==-8 );
            //CHECK(solve(x^2+x^2 == 128)==8 ||solve(x^2+x^2 == 128)== -8);
            //CHECK(solve(x^3+x^3 == 16)==2  );
           // CHECK(solve(x^3+x^3 == -16)==-2 );
            //CHECK(solve(x^2-x^2 == 0)==1 );
            //CHECK(solve(2*x^2-x^2-1 == 0)==1 );         //21

}
TEST_CASE("RealVariable - throw cases") {
    RealVariable x;
            CHECK_THROWS(solve(2 == 1));
            //CHECK_THROWS(solve(x^2 ==-1 ) );
            CHECK_THROWS(solve(2*x/x == 10) );
            CHECK_THROWS(solve((x*2-10)/x == 10) );
            CHECK_THROWS(solve(2*x/x == 3) );
            //CHECK_THROWS(solve(10*x+2*x^2 == 10) );
            CHECK_THROWS(solve(2-4+4 == 10) );
            //CHECK_THROWS(solve(2^2 == 10) );
            CHECK_THROWS(solve(2*x-2 == 2) );
            //CHECK_THROWS(solve(2*x == 10) ==1);
            CHECK_THROWS(solve(-1*x^2+2*x == -15)); //32
}
TEST_CASE("ComplexVariable - linear equations") {
    ComplexVariable y;
 //           CHECK(solve(-1*y^2+4*y == 15) == 2+sqrt(11)*y || 2-sqrt(11)*y);
           // CHECK(solve(-1*y^2+6*y == 15) ==3+sqrt(6)*y || 3-sqrt(6)*y);
           // CHECK(solve(-1*y^2+8*y == 15) == 5 || 3);
            //CHECK(solve(-1*y^2+10*y == 15) == 5+sqrt(10)*y || 5-sqrt(10)*y);
            //CHECK(solve(-1*y^2+14*y == 15) == 7+sqrt(34)*y || 7-sqrt(34)*y);
            //CHECK(solve(-1*y^2+16*y == 15) == 1 || 8);
            //CHECK(solve(-1*y^2+2*y == 15) == 1+sqrt(14)*y || 1-sqrt(14)*y);
            //CHECK(solve(2*y-4 == 10) == 7+0*y);
           // CHECK(solve(2 == 2) == y );
           // CHECK(solve(2*y == 10)== 5+0*y) ;
           // CHECK(solve(2*y-2*y == 0) == 0+0*y) ;
           // CHECK(solve(2*y-2 == 0) == 1+0*y);
            //not sure about the i
            //CHECK(solve(y+5 == 10) == 0+2*y);
            //CHECK(solve(y+7i == 2*y+3i) == 0+4*y);
           // CHECK(solve(y+5i+3 == 2*y+3i) == 3+2*y);
           // CHECK(solve(y+5i+3 == 2*y+3i) == 3+2*y);
           // CHECK(solve(y+5i+3 == 2*y+3i) == 3+2*y);
            //CHECK(solve(y+5i == 3*y+3i) ==0+1*y);       //48


}
TEST_CASE("ComplexVariable - polynomial equations") {

        ComplexVariable z;
     
          CHECK(solve((z^2) +2*z +1== 1) == complex(0.0,0.0) );

        //   CHECK((solve((z^2) +9 == 0) == complex(0.0,3.0) || solve((z^2) +9 == 0) == complex(0.0,-3.0)));
 //CHECK((solve((z^5) +1 == 0) == complex(1.0,0.0)
 /////////////unkcow error          CHECK(solve((z^2) +4*z +7 == 0) == complex(2.0,sqrt(3)) || solve((z^2) +4*z +7 == 0) == complex(2.0,-sqrt(3)));
          //  CHECK((solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,sqrt(6)/5) || solve(5*(z^2) +6*z +3 == 0) == complex(-0.6,-sqrt(6)/5)));

  //CHECK(solve(2*(z^2) +12*z +9 == 0) == complex(-1.5*(sqrt(2)+2),0.0)|| solve(2*(z^2) +12*z +9  == 0) == complex(-1.5*(sqrt(2)+2),0.0));
    //        CHECK((solve(0*(z^2) +3*z +27 == 0) == complex(-9.0,0.0) ));
//CHECK((solve((z^2)/2 +z +14 == 0) == complex(-1.0,3*sqrt(3)) || solve((z^2)/2 +z +14 == 0) == complex(-1.0,-3*sqrt(3))));
 //           CHECK((solve((z^2)*8 +56*z +16 == 0) == complex(-(7+sqrt(41))/2,0.0) || solve((z^2)*8 +56*z +16 == 0) == complex((-7+sqrt(41))/2,0.0)));
  //         CHECK((solve(2*(z^2) +4*z +9== 8+2/2) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));
    //        CHECK((solve(6*(z^2)/2 +2*z*3 +90== 90) == complex(0.0,0.0) || solve((z^2) +2*z +1== 1) == complex(-2.0,0.0)));

}
TEST_CASE("ComplexVariable - throw cases") {
    ComplexVariable y;
           // CHECK_THROWS(solve(3*y/0 == 0));
            //CHECK_THROWS(solve(2*y-2*y+8 == 0));
            //CHECK_THROWS(solve(4*(y^6)+8 == 0));
            //CHECK_THROWS(solve(4*y*9+(y^3)+8==9));
            //CHECK_THROWS(solve(y/0+8.0 == 0));
            //CHECK_THROWS(solve(12/0*y == y*4));
            //CHECK_THROWS(solve((y^2)/0 == 2*(y^4)));
            //CHECK_THROWS(solve(4*y == 6*y));
            //CHECK_THROWS(solve((y^2)+12 == 2*(y^2)));
            //CHECK_THROWS(solve(4*y-3*y+1 == 0));    //61

}

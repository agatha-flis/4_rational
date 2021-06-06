#include <gtest/gtest.h>
#include "../src/rational.h"

TEST(TS1, add_two_rationals) {
    EXPECT_EQ(Rational(1,1),Rational(1,2)+Rational(1,2));
    EXPECT_EQ(Rational(5,1),Rational(3,2)+Rational(7,2));
}

TEST(TS1, subtract_two_rationals) {
    EXPECT_EQ(Rational(1,2),Rational(2,2)-Rational(1,2));
    EXPECT_EQ(Rational(3,1),Rational(10,2)-Rational(4,2));
}

TEST(TS1, multiply_two_rationals) {
    EXPECT_EQ(Rational(5,4),Rational(3,2)*Rational(5,6));
    }

TEST(TS1, divide_two_rationals) {
    EXPECT_EQ(Rational(10,1),Rational(5,1)/Rational(1,2));
    EXPECT_THROW(Rational v3(3,0), MyException); 
}

TEST(TS1, add_rational_int) {
    EXPECT_EQ(Rational(7,2),Rational(1,2)+3);
    EXPECT_EQ(Rational(7,2),3+Rational(1,2));
}

TEST(TS1, subtract_rational_int) {
    EXPECT_EQ(Rational(2,1),Rational(10,2)-3);
    EXPECT_EQ(Rational(5,1),10-Rational(10,2));
}

TEST(TS1, multiply_rational_int) {
    EXPECT_EQ(Rational(7,8),Rational(7,4)*Rational(3,6));
    }

TEST(TS1, divide_rational_int) {
    EXPECT_EQ(Rational(10,3),Rational(5,3)/Rational(1,2));
    EXPECT_THROW(Rational(3,5)/Rational(7,0), MyException);
}

TEST(TS1, equality) {
    EXPECT_TRUE(Rational(2,3)==Rational(2,3));
    EXPECT_FALSE(Rational(2,3)==Rational(7,3));
    EXPECT_TRUE(Rational(2,3)==Rational(4,6));
    }

TEST(TS1, greater_or_equal) {
    EXPECT_TRUE(Rational(2,3)>=Rational(1,8));
    EXPECT_FALSE(Rational(1,2)>=Rational(3,4));
    EXPECT_TRUE(Rational(2,3)>=Rational(2,3));
    }

TEST(TS1, lesser_or_equal) {
    EXPECT_TRUE(Rational(1,8)<=Rational(1,2));
    EXPECT_FALSE(Rational(1,2)<=Rational(1,6));
    EXPECT_TRUE(Rational(2,3)<=Rational(2,3));
    }

TEST(TS1, greater) {
    EXPECT_TRUE(Rational(1,2)>Rational(1,8));
    EXPECT_FALSE(Rational(1,6)>Rational(1,2));
    EXPECT_FALSE(Rational(2,3)>Rational(2,3));
    }

TEST(TS1, lesser) {
    EXPECT_TRUE(Rational(1,8)<Rational(1,2));
    EXPECT_FALSE(Rational(1,2)<Rational(1,6));
    EXPECT_FALSE(Rational(2,3)<Rational(2,3));
    }


TEST(TS1, normalize) {
    Rational v1 = Rational::normalize(Rational(3,33));
    EXPECT_EQ(1,v1.numerator());
    EXPECT_EQ(11,v1.denominator());

    Rational v2 = Rational::normalize(Rational(-5,20));
    EXPECT_EQ(-1,v2.numerator());
    EXPECT_EQ(4,v2.denominator());
}

TEST(TS1, create_rational) {
    Rational v1(3,6);
    EXPECT_EQ(v1.numerator(), 3);
    EXPECT_EQ(v1.denominator(), 6);
    
    EXPECT_EQ(Rational(1,3), Rational(1,3));
    
    //Rational v2(3,6);
    //EXPECT_EQ(v2.numerator(), 1);
    //EXPECT_EQ(v2.denominator(), 2);

    EXPECT_THROW(Rational(3,0), MyException);
}

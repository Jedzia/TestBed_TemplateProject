//
// Created by Jedzia on 24.10.2019.
//

#include "gtest/gtest.h"
//#include "Julian.h"
//#include "Gregorian.h"


class DateConverterFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        //gregDate = new GregorianDate();
        //julDate = new JulianDate();
    }

    virtual void TearDown() {
        //delete gregDate;
        //delete julDate;
    }

    //GregorianDate * gregDate;
    //JulianDate * julDate;
};

TEST_F(DateConverterFixture, FirstDayEver
) { // 1/1/1 -> 1/3/1

    //gregDate->SetMonth(1);
    //gregDate->SetDay(1);
    //gregDate->SetYear(1);

    //int absGregDate = gregDate->getAbsoluteDate();
    //julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(6, 1);
    //EXPECT_EQ(julDate->getDay(),3);
    //EXPECT_EQ(julDate->getYear(),1);

}

#include <gtest/gtest.h>
#include <dumbstep.h>

class StepperTest : public ::testing::Test {
    protected:
        DumbStep stepper{}; 
};

TEST_F(StepperTest, SingleStepSuccess) {
    bool run{false};

    stepper.step([&]() {
        run = true;
        return true;
    });

    EXPECT_TRUE(run);
    EXPECT_TRUE(stepper.success());
}

TEST_F(StepperTest, SingleStepFail) {
    bool run{false};

    stepper.step([&]() {
        run = true;
        return false;
    });

    EXPECT_TRUE(run);
    EXPECT_FALSE(stepper.success());
}

TEST_F(StepperTest, MultipleStepSuccess) {
    bool run1{false};
    bool run2{false};

    stepper.step([&]() {
        run1 = true;
        return true;
    }).step([&]() {
        run2 = true;
        return true;
    });

    EXPECT_TRUE(run1);
    EXPECT_TRUE(run2);
    EXPECT_TRUE(stepper.success());
}

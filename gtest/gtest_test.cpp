#include <string>
#include "gmock/gmock.h"
 
namespace gmock_ {
 
class Foo {
public:
	// Must be virtual as we'll inherit from Foo.
	virtual ~Foo() {}
 
	virtual bool SetName(const std::string& name) = 0;
	virtual std::string GetName() const = 0;
};
 
class MockFoo : public Foo {
public: 
    //! 1. first argument is return type
    //! 2. second argument is the name of the method
    //! 3. third argument is the arguments
    //! 4. fourth argument is the confined type
	MOCK_METHOD(bool, SetName, (const std::string&), (override)); // the last argument is the convention for a mock method.
	MOCK_METHOD(std::string, GetName, (), (const, override));
};
 
class Area {
public:
	virtual ~Area() {}
	virtual int area() = 0;
};
 
int GetValue(Area* p) { return p->area() / 2; }
 
class MockArea : public Area {
public:
	MOCK_METHOD(int, area, (), (override));
};
 
} // namespace gmock_
 
TEST(gmock, name) {
	using namespace gmock_;
	using ::testing::AtLeast;
	using ::testing::Return;
 
	MockFoo foo;
	EXPECT_CALL(foo, SetName("Mike"))
		.Times(AtLeast(2))
		.WillOnce(Return(1))
		.WillOnce(Return(0));
	EXPECT_TRUE(foo.SetName("Mike"));
	EXPECT_FALSE(foo.SetName("Mike"));
 
	EXPECT_CALL(foo, GetName())
		.Times(AtLeast(1))
		.WillRepeatedly(Return("Mike"));
	EXPECT_EQ("Mike", foo.GetName());
}
 
TEST(gmock, area) {
	using namespace gmock_;
	using ::testing::Return;
 
	MockArea m;
	EXPECT_CALL(m, area()).WillRepeatedly(Return(10));
	EXPECT_EQ(5, GetValue(&m));
}


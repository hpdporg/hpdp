#include "AsmIncludes.h"
#include "ParsingTests.h"

TEST(ParsingTest, ReturnsFirstParsedValue) {
	
	char* letters = "FirstVal";



	EXPECT_STREQ("FirstVal",letters);
}


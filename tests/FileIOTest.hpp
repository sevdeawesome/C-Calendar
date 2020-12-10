#ifndef __FILEIOTEST_HPP_
#define __FILEIOTEST_HPP_

#include "../header/FileIO.hpp"

TEST(FileIOTests, ReadFromFileAndShowDataTest)
{
	FileIO::GetInstance()->readFromFile("winter2020.txt");
	EXPECT_EQ(FileIO::GetInstance()->showAllData(), "1\n2\n3\n4\n5\n");
} 


#endif
#ifndef __FILEIOTEST_HPP_
#define __FILEIOTEST_HPP_

#include "../header/FileIO.hpp"


TEST(FileIOTests, ReadFromFileAndShowDataTest)
{
	FileIO::GetInstance()->readFromFile("readFile.txt");
	EXPECT_EQ(FileIO::GetInstance()->showAllData(), "1\n2\n3\n4\n5\n");
	ASSERT_NE(FileIO::GetInstance()->showAllData(), "21\n2\n3\n4\n5\n");
	ASSERT_TRUE(FileIO::GetInstance()->showAllData() == "1\n2\n3\n4\n5\n");
	ASSERT_FALSE(FileIO::GetInstance()->showAllData() == "21\n2\n3\n4\n5\n");
}
TEST(FileIOTests, AddDataTest)
{
	FileIO::GetInstance()->readFromFile("readFile.txt");
	FileIO::GetInstance()->addData("6");
	EXPECT_EQ(FileIO::GetInstance()->showAllData(), "1\n2\n3\n4\n5\n6\n");
	ASSERT_NE(FileIO::GetInstance()->showAllData(), "21\n2\n3\n4\n5\n6\n");
	ASSERT_TRUE(FileIO::GetInstance()->showAllData() == "1\n2\n3\n4\n5\n6\n");
	ASSERT_FALSE(FileIO::GetInstance()->showAllData() == "21\n2\n3\n4\n5\n6\n");
}
TEST(FileIOTests, GetDataTest)
{
	FileIO::GetInstance()->readFromFile("readFile.txt");
	EXPECT_EQ(FileIO::GetInstance()->getData(0), "1");
	ASSERT_NE(FileIO::GetInstance()->getData(0), "21");
	ASSERT_TRUE(FileIO::GetInstance()->getData(0) == "1");
	ASSERT_FALSE(FileIO::GetInstance()->getData(0) == "21");
}
TEST(FileIOTests, WriteToFileAndShowDataTest)
{
		string middata;
	string middata_2;
	FileIO::GetInstance()->readFromFile("readFile.txt");
	middata = FileIO::GetInstance()->showAllData();
	FileIO::GetInstance()->addData("6");
	FileIO::GetInstance()->writeToFile("writeFile.txt");
	FileIO::GetInstance()->readFromFile("writeFile.txt");
	middata = middata + "6\n";
	middata_2 = middata + "6\n";
	assert(middata == FileIO::GetInstance()->showAllData());
	EXPECT_EQ(FileIO::GetInstance()->showAllData(), middata);
	ASSERT_NE(FileIO::GetInstance()->showAllData(), middata_2);
	ASSERT_TRUE(FileIO::GetInstance()->showAllData() == middata);
	ASSERT_FALSE(FileIO::GetInstance()->showAllData() == middata_2);
}


#endif
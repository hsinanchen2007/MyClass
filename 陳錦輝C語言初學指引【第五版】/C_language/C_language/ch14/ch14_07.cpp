/*    檔名:ch14_07.cpp    功能:讀取二進位檔內的物件資料   */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class student
{
 private:
  string stu_id;
  int    ScoreComputer;
  int    ScoreMath;
  int    ScoreEng;
  float  ScoreAvg;
 public:
  void setdata(string a,int b,int c,int d,float e)
  {
    stu_id=a;
    ScoreComputer=b;
    ScoreMath=c;
    ScoreEng=d;
    ScoreAvg=e;
  }
  void showdata() 
  {
    cout << stu_id << "\t" << ScoreComputer << "\t" << ScoreMath << \
                      "\t" << ScoreEng << "\t" << ScoreAvg << endl;
  }
};

/**************main**************/
int main(void)
{
 string stu[3]={"S9703501","S9703502","S9703503"};
 int score[3][3]={{89,84,75},
                  {77,69,87},
                  {65,68,77}};
 ifstream readfile;
 int i,Total[3];
 student IM[3];
  
 for(i=0;i<3;i++)
 {
   Total[i]=0;
   Total[i]=score[i][0]+score[i][1]+score[i][2];
   IM[i].setdata(stu[i],score[i][0],score[i][1] \
                ,score[i][2],float(Total[i])/3);  //C++語法
 }
   
 readfile.open("data5",ios::in|ios::binary);
 if(readfile.fail())   //開檔失敗
 {
  cout << "檔案發生錯誤" << endl;
  exit(1); //強迫結束程式
 }

 readfile.read((char *)&IM[i], sizeof(IM[i])*2);
 readfile.close();
 
 cout << "二進位檔讀取完成,前兩筆學生資料如下" << endl;
 
 for(i=0;i<2;i++)
   IM[i].showdata();
 return 0;
}

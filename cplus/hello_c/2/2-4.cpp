#include <iostream>  // 输入输出流（cin、cout）
#include <fstream>   //  文件流（ifstream、ofstream）

using namespace std;

int main()
{
    int nYear, nMonth, nDate;

    ifstream fin("Data.txt");  // 创建输入文件流对象
    if (fin.is_open())
    {
        fin >> nYear >> nMonth >> nDate;
        cout << "文件中记录的日期是："
             << nYear << "-" << nMonth << "-" << nDate << endl;
        fin.close();
    }
    else
    {
        cout << "无法打开文件并进行读取。" << endl;
    }

    cout << "请输入新日期（例如，1982 10 3）：" << endl;
    cin >> nYear >> nMonth >> nDate;

    ofstream fout("Data.txt");  // 创建一个输出文件流对象 ,如果文件不存在，会自动创建, 
    if (fout.is_open())
    {
        fout << nYear << " " << nMonth << " " << nDate;  //使用 << 插入符向文件写入数据
        fout.close();
    }
    else
    {
        cout << "无法打开文件并进行写入。" << endl;
    }

    return 0;
}
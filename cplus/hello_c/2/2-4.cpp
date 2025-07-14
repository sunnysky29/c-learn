#include <iostream>
// 引入文件输入/输出需要的头文件
#include <fstream>

using namespace std;

// 主函数
int main()
{ 
    // 定义变量，保存程序中的数据
    int nYear, nMonth, nDate;
    // 创建输入文件流对象fin，并尝试打开Data.txt文件
    // 这个文件应该位于exe文件相同的目录下，
    // 才能直接使用文件名打开，否则应该使用完整的文件路径
    ifstream fin("Data.txt");
    // 判断Data.txt文件是否成功打开   
    // 如果成功打开文件，则从文件中读取内容
    if( fin.is_open() )        
    {
        // 用提取符“>>”从文件输入流对象fin中读取文件中的数据，并保存到相应的变量
        // 文件中的内容应该是以空格间隔的三个整数，例如：1981 9 22
        fin>>nYear>>nMonth>>nDate;
        // 将读取的数据显示到屏幕
        cout<<"文件中记录的日期是："
            <<nYear<<"-"<<nMonth<<"-"<<nDate<<endl;
        // 读取完成后，关闭文件
        fin.close();
    }
    else
    {
        // 如果文件打开失败，则提示错误信息
        cout<<"无法打开文件并进行读取。"<<endl;
    }
    
    // 提示用户输入新的数据并将其写入文件
    cout<<"请输入新日期（例如，1982 10 3）："<<endl;
    // 获取用户通过键盘输入的数据并保存到相应的变量中
    cin>>nYear>>nMonth>>nDate;

    //创建输出文件流对象fout，并尝试打开Data.txt文件，
    // 如果这个文件不存在，则创建一个新文件并打开
    ofstream fout("Data.txt");
    // 如果成功打开Data.txt文件，则将用户输入的数据写入文件
    if( fout.is_open() )
    {
        // 利用插入符“<<”将数据插入文件输出流对象fout中，
        // 也就是将数据写入与之关联的Data.txt文件中
		// 为了便于将来的读取，这里输出的数据以空格作为间隔	
        fout<<nYear<<" "<<nMonth<<" "<<nDate;
        // 写入完成后，关闭文件
        fout.close();
    }
    else
    {
        // 如果无法打开文件，则提示错误信息
        cout<<"无法打开文件并进行写入。"<<endl;
    }

    return 0;
}

// 用并列条件选择实现的看天穿衣
#include <iostream>

using namespace std;

// 枚举可能的天气情况
enum Weather
{
    SUNNY = 1,	// 晴天，指定其值为1
    CLOUDY,	     // 阴天，其值递增为2
    RAINY,		// 雨天，其值递增为3
};

int main()
{
    cout<<"请输入明天的天气(1-晴天;2-阴天;3-雨天)：";
    int nW = 0;
    // 获取用户输入的天气情况
    cin>>nW;
	
    // 对天气情况进行判断
    if(SUNNY == nW) // 如果是晴天
    {
        // 输出晴天该穿的衣服
        cout<<"晴天穿T恤"<<endl;
    }
    else if(CLOUDY == nW) // 如果是阴天
    {
        cout<<"阴天穿衬衣"<<endl;
    }
    else if(RAINY == nW) // 如果是雨天
    {
        cout<<"雨天穿外套"<<endl;
    }
    else
    {
	   cout<<"不知道明天是什么天气，你爱穿什么穿什么吧"<<endl;
    }

    return 0;
}

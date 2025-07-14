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
	
    // 用switch语句实现的并列条件选择
    // 以表示天气状况的nW作为条件量，根据不同的天气穿不同的衣服
	switch(nW)
	{
		case SUNNY: // 以表示晴天的SUNNY作为常量值，进行对晴天状况的处理
			cout<<"晴天穿T恤"<<endl;
		break;// 完成对晴天状况的处理，用break结束整个switch语句
		case CLOUDY:  // 处理阴天
			cout<<"阴天穿衬衣"<<endl;
		break;
		case RAINY:  // 处理雨天
			cout<<"雨天穿外套"<<endl;
		break;
		default:// 对例外情况进行默认的处理
			cout<<"不知道这是什么天气，你爱穿什么穿什么吧"<<endl;
	}

    return 0;
}

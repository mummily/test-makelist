#include <iostream>
#include <vector>
#include <variant>

using namespace std;

namespace Ino
{
    struct Variant
    {
        Variant(bool b) : data(b) {}
        Variant(int i) : data(i) {}
        Variant(double d) : data(d) {}
        Variant(std::string s) : data(std::move(s)) {}
        // ... 其他简单类型constructor
        Variant(std::initializer_list<Variant> l) : data(std::move(l)) {}

        inline operator int() const
        {
            if (auto p = std::get_if<int>(&data); p)
                return *p;
            return 0;
        }
        // ... 其他简单类型operator

        std::variant<bool, int, double, std::string, std::initializer_list<Variant>> data;
    };
}

namespace Ino
{
    struct NodeInfo
    {
        string node;        // 节点描述
        int type;           // 节点属性
        Ino::Variant value; // 值
        bool result;        // 结果
    };
}

namespace Ino
{
    struct CallMethod
    {
        string object;                          // 读取节点
        string method;                          // 读取节点属性
        std::vector<Ino::Variant> inputparams;  // 输入参数，默认为空
        std::vector<Ino::Variant> outputparams; // 输出参数，默认为空
        bool result;                            // 结果
    };
}

void fun(std::vector<Ino::Variant> &ms)
{
    for (auto &&m : ms)
    {
        int index = m.data.index();
        cout << index << " ";
        auto &val = m.data;
        if (auto p = std::get_if<int>(&m.data); p)
        {
            cout << *p << endl;
            *p = 100;
        }
    }
}

int main(int argc, char **argv)
{
    // Ino::NodeInfo info = {"", 5};
    // info.value = "";
    // int value = std::get<int>(info.value.data);
    // int value2 = info.value;

    std::vector<Ino::Variant> params = {1, 2, 3, false, 3.3, {2, 3.3, false}};
    cout << params.at(0);
    // fun(params);

    // std::variant<int, double, list<int>> v12{list<int>({3, 4})};
    // Ino::Variant var(vector<Ino::Variant>({3, false}));

    // std::visit([](const auto& val) {std::cout << "value: " << val << '\n'; }, v12);
    // std::visit([](const auto& val) {std::cout << "value: " << val << '\n'; }, v11);

    return 0;
}
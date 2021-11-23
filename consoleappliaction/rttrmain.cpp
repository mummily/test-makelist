#include <iostream>
#include <rttr/registration>
#include <rttr/variant.h>
using namespace rttr;
using namespace std;

struct MyStruct
{
    MyStruct() { data = 0; };
    MyStruct(int _data) { data = _data; };
    void func(double d) { cout << d << endl; };

public:
    int data;
};

RTTR_REGISTRATION
{
    registration::class_<MyStruct>("MyStruct")
        .constructor<>()
        .constructor<int>()(
            default_arguments(23),
            policy::ctor::as_std_shared_ptr)
        .property("data", &MyStruct::data)
        .method("func", &MyStruct::func);
}

// 用法说明
// 1. 获取type
//    a. type t = type::get<MyStruct>();
//    b. type t = type::get_by_name("MyStruct");
//    c. MyStruct obj;
//       type t = type::get(obj);
// 2. 获取属性
//    a. t.get_properties()
//    b. property prop = t.get_property("data")
//    2.1 属性调用
//        MyStruct obj;
//        prop.set_value(obj, 23);
//        variant var_prop = prop.get_value(obj);
// 3. 获取方法
//    a. t.get_methods()
//    b. method meth = type::get(obj).get_method("func");
//    3.1 方法调用
//        // 现有对象
//        MyStruct obj;
//        meth.invoke(obj, 42.0);
//        // rttr构造对象
//        variant var = type::get(obj).create();
//        meth.invoke(var, 42.0);
// 4. 调用构造函数/创建对象
//    a. variant var = t.create();
//    b. constructor ctor = t.get_constructor();
//       variant var = ctor.invoke();
int main(int argc, char **argv)
{
#pragma region 类型
    // 方法 1
    type t = type::get<MyStruct>();

    // 方法 2
    // type t = type::get_by_name("MyStruct");

    // 方法 3
    MyStruct obj(23);
    // type t = type::get(obj);
#pragma endregion

#pragma region 构造对象
    // 方法 1
    // variant var = t.create({23});

    // 方法 2
    constructor ctor = t.get_constructor({type::get<int>()}); // 2nd way with the constructor class
    variant var = ctor.invoke(23);

    cout << var.get_type().get_name() << endl;
#pragma endregion

    // 枚举属性、方法
    {
        for (auto &prop : t.get_properties())
            cout << "prop name: " << prop.get_name() << endl;

        for (auto &meth : t.get_methods())
            cout << "meth name: " << meth.get_name() << endl;
    }

    // Set/get属性
    {
        property prop = t.get_property("data");

        prop.set_value(obj, 23);
        variant var_prop = prop.get_value(obj);

        cout << var_prop.to_int() << endl;
    }

    // 调用方法
    {
        method meth = t.get_method("func");

        meth.invoke(obj, 42.0);
        meth.invoke(var, 42.0);
    }

    return 0;
}
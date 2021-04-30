#include <iostream>

class GlobalClass
{
    int m_value;
    // static pointer to Singleton instance 
    static GlobalClass *s_instance;

    // private constructor so so no objects can be created
    GlobalClass(int v = 0) {
        m_value = v;
    }

    public:
        int get_value() {
            return m_value;
        }

        void set_value(int v) {
            m_value = v;
        }

        // Static call which initializes if object is not made yet
        static GlobalClass *instance() {
            if (!s_instance) {
                s_instance = new GlobalClass;
            }
            return s_instance;
        }
};
// Allocating and initializing GlobalClass's static data member.  
// The pointer is being allocated - not the object inself.
GlobalClass *GlobalClass::s_instance = 0;

void foo(void) {
    GlobalClass::instance()->set_value(1);
    cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << endl;
}

void bar(void) {
    GlobalClass::instance()->set_value(2);
    cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << endl;
}

int main() {
    cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << endl;
    foo();
    bar();
    return 0;
}
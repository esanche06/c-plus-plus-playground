#include <iostream>
#include <sstream>

using namespace std;


class Student {
    // Would most likely have a constructor here...

    private:
        int age;
        string first_name;
        string last_name;
        int standard;
    public:
        // Note that we would normally do some kind of validation on these
        // class members when they're set, but we're ignoring that for the sake
        // of the simplicity of the prompt...for now. ;)

        int set_age(int new_age) {
            age = new_age;
            return age;
        }

        int get_age() {
            return age;
        }

        string set_first_name(string new_first_name) {
            first_name = new_first_name;
            return first_name;
        }

        string get_first_name() {
            return first_name;
        }

        string set_last_name(string new_last_name) {
            last_name = new_last_name;
            return last_name;
        }

        string get_last_name() {
            return last_name;
        }

        int set_standard(int new_standard) {
            standard = new_standard;
            return standard;
        }

        int get_standard() {
            return standard;
        }

        string to_string() {
            stringstream s;
            s << age << "," << first_name << "," << last_name << "," << standard;
            return s.str();
        }

};

int main() {
    int age = 15, standard = 10;
    string first_name = "john", last_name = "carmack";

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
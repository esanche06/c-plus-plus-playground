#include <vector>

using namespace std;

class Profile {
    private:
        string username;
        string city;
        string country;
        string pronouns;
        vector<string> hobbies;
        int age;
    public:
        Profile(
            string new_username = "default", string new_city = "unknown",
            string new_country = "unknown", string new_pronouns = "N/A",
            int new_age = 0
        );
        void addHobby(string hobby);
        void printProfile();
};
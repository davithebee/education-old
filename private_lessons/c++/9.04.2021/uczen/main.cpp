#include <iostream>
#include <fstream>
#include <vector>

struct address
{
    std::string street;
    std::string city;
};

struct student
{
    std::string lastName;
    int studentNumber;
    std::string studentClass;
    address studentAddress;
};

struct citiesAndNumbers
{
    std::string city;
    int studentCount;
};

int main()
{
    std::fstream in, out;
    in.open("dane.txt", std::ios::in);
    out.open("wynik.txt", std::ios::out);
    std::vector<citiesAndNumbers>amount;

    if(in.good())
    {
        int n;
        in >> n;
        in.ignore();
        student *school = new student[n];
        bool flag{false};
        citiesAndNumbers temp;

        for(int i{0}; i < n; i++)
        {
            getline(in, school[i].lastName);
            in >> school[i].studentNumber;
            in.ignore();
            getline(in, school[i].studentClass);
            getline(in, school[i].studentAddress.street);
            getline(in, school[i].studentAddress.city);

            for(int j{0}; j < amount.size(); j++)
            {
                if(amount[j].city == school[i].studentAddress.city)
                {
                    amount[j].studentCount++;
                    flag = true;
                    break;
                }
            }
            if(flag == false)
            {
                temp.city = school[i].studentAddress.city;
                temp.studentCount = 1;

                amount.push_back(temp);
            }
        }

        for(int j{0}; j < amount.size(); j++)
        {
            out << amount[j].city << '\n';
            out << amount[j].studentCount << '\n' << '\n';
        }

    }
    else
    {
        std::cout << "FSTREAM ERROR";
        out << "FSTREAM ERROR";
    }

}

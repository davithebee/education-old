#include <iostream>
#include <fstream>
#include <iomanip>

struct book
{
    std::string title;
    std::string author;
    double price;
    int amount;
};

void read(std::fstream &in, book *inventory, int n)
{
    for(int i{0}; i < n; i++)
    {
        getline(in, inventory[i].title);
        getline(in, inventory[i].author);
        in >> inventory[i].price;
        in >> inventory[i].amount;
        in.ignore();
    }
};

void write(std::fstream &out, book a)
{
    out << "Tytul:" << a.title << '\n';
    out << "Autor:" << a.author << '\n';
    out << "Cena:" << std::fixed << std::setprecision(2) << a.price << '\n';
    out << "Naklad:" << a.amount << '\n';
    out << "--------------------" << '\n';
};

void findMostExpensive(std::fstream &out, book *inventory, int n)
{
    int index{0};
    for(int i{1}; i < n; i++)
        {
            if(inventory[i].price > inventory[index].price)
            {
                index = i;
            }
        }

    out << "Najdrozsza ksiazka: " << inventory[index].title << '\n';
    out << "Cena: " << inventory[index].price;
}

int main()
{
    std::fstream in, out;
    in.open("dane.txt", std::ios::in);
    out.open("wynik.txt", std::ios::out);

    if(in.good())
    {
        int n;
        in >> n;
        book *inventory = new book[n];
        in.ignore();

        read(in, inventory, n);

        for(int i{0}; i < n; i++)
        {
            write(out, inventory[i]);
        }

        findMostExpensive(out, inventory, n);
    }
    else
    {
        std::cout << "FSTREAM ERROR";
        out << "FSTREAM ERROR";
    }

    return 0;
}

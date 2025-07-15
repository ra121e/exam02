#ifndef VECT2_HPP
# define VECT2_HPP

# include <iostream> // ostream

class vect2
{
    public:
        vect2();
        vect2(int x, int y);
        vect2(vect2 const &other);
        vect2   &operator=(vect2 const &other);
        ~vect2();

        vect2   operator+(vect2 const &other) const; // const
        vect2   operator-(vect2 const &other) const; // const
        vect2   operator-() const; //const
        vect2   operator*(int k) const; //const
        friend vect2    operator*(int k, vect2 const &other);

        vect2   &operator++();
        vect2   operator++(int);
        vect2   &operator--();
        vect2   operator--(int);

        vect2   &operator+=(vect2 const &other);
        vect2   &operator-=(vect2 const &other);
        vect2   &operator*=(int k); // int k <- other

        int     &operator[](size_t i); // & and size_t
        int     operator[](size_t i) const; // size_t 

        bool    operator==(vect2 const &other) const;
        bool    operator!=(vect2 const &other) const;

        friend std::ostream &operator<<(std::ostream &os, vect2 const &other); //& of os

        
    private:
        int _x;
        int _y;
};

#endif
#include <iostream>
#include <string>

/*
class date that  we can initiate to modify the date info
*/
class Date{
    private:
        static int month,date,year;            //Private variables that are the main variables
        bool is_leap_year(int month, int date, int year);    //Check if the year is a leap year or not
        bool check_validity(int month, int date, int year)  //Function that checks if the given data is actually valid or not
        {
            bool flag = true;
            if(!(year > 1899 && year < 2026))   //check if the year is in between 1900 and 2026
                flag=false;
            if(!(month > 0 && month <13))       //check if the month value is between 1 and 12
                flag=false;
            
            
        }
        bool set_date(int month, int date, int year);     //Function that sets the date
    public:
        Date(int month, int date, int year){
            if(check_validity(month, date, year)){           //When a class is initiated we check if the given input is valid or not, only then will we update the private variables
                set_date(month, date, year);
            }    
        };
};

void main(){

    std::cout << "First OOPS program with C++" << std::endl;
}